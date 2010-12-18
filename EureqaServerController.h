/*
 *  Class responsible for automatic management of Eureqa's server
 *
 *  Created on: Dec 12, 2010
 *      Author: MF
 */

#ifndef SERVERMANAGER_H_
#define SERVERMANAGER_H_


#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>
#include <sstream>
#include <stdlib.h>

#ifdef linux
#include <signal.h>
#include <unistd.h>
#endif /* linux */

// TODO: chmod on eureqa_server


//! Utility function converting arbitrary type to a string
template <class T> std::string ToString(const T& value)
{
   std::stringstream outputStream(std::stringstream::in | std::stringstream::out);
   outputStream << value;
   return outputStream.str();
}


class EureqaServerCommunicator: private boost::noncopyable
{
	public:

		//! Getter for the class' instance
		static EureqaServerCommunicator* GetInstance() {return initialized ? &instance : NULL;}

		//! Function reporting that it was impossible to connect with Eureqa's server
		void ReportServerError() {serverStarter->ReportServerError();}

		//! Function which sets Eureqa's server's binary path
		void SetBinaryPath(std::string binaryPath) {serverStarter->SetBinaryPath(binaryPath);}

		//! Function starting Eureqa's server binary (if no Eureqa's server is already started)
		void StartServer() {serverStarter->StartServer();}

		//! Function stopping Eureqa's server binary (if not already stopped)
		void StopServer() {serverStarter->StopServer();}

	private:

		//! Constructor
		/*!
		 * Default constructor - made private, since the class is the Singleton
		 */
		EureqaServerCommunicator() :
		#ifdef linux
			serverStarter(new LinuxServerStarter())
		#endif /* linux */
		#if defined(__WIN32__) || defined(__WIN64__) || defined(_WIN32) || defined(_WIN64)
		#endif /* _WIN32_ || _WIN64_ || _WIN32 || _WIN64 */
		{initialized = true;}

		//! Destructor
		/*!
		 * Default destructor - made private, since the class is the Singleton
		 */
		~EureqaServerCommunicator() {initialized = false;}

		//! Flag indicating if the class has been initialized
		static bool initialized;

		//! Class' instance
		static EureqaServerCommunicator instance;

		//! Internal class responsible for starting Eureqa's server
		class ServerStarter
		{
			public:

				//! Default destructor's prototype
				virtual ~ServerStarter() {}

				//! Prototype for the function which reports Eureqa's server's error
				virtual void ReportServerError() {throw "Called function is not implemented!";}

				//! Prototype for the function which sets Eureqa's server's binary path
				virtual void SetBinaryPath(std::string binaryPath) {throw "Called function is not implemented!";}

				//! Prototype for the function which starts Eureqa's server binary
				virtual void StartServer() {throw "Called function is not implemented!";}

				//! Prototype for the function which stops Eureqa's server binary
				virtual void StopServer() {throw "Called function is not implemented!";}
		};

		#ifdef linux

			//! LinuxServerStarter class
			/*!
			 * Internal class which starts Eureqa's server binary under Linux
			 */
			class LinuxServerStarter: public ServerStarter
			{
			public:

				//! Parameterized constructor
				/*
				 * \param binaryPath path to the Eureqa's server's Linux binary
				 */
				LinuxServerStarter()
				{
					serverStarted = false;
					serverProcessIdentifier = 0;
					checkBinaryStateAllowed = (system("lsof > /dev/null 2>&1") == 0) && (system("echo > /dev/null 2>&1") == 0);
				}

				//! Default destructor
				~LinuxServerStarter()
				{
					if (serverStarted)
					try
					{
						StopServer();
					}
					catch (...)
					{
						// No exceptions in destructor
					}
				}

				//! Reports Eureqa's server's error
				void ReportServerError()
				{
					serverStarted = false;
				}

				//! Sets Eureqa's server's binary path
				void SetBinaryPath(std::string binaryPath)
				{
					this->binaryPath = binaryPath;
				}

				//! Starts Eureqa's Linux server's binary
				void StartServer()
				{
					if (!serverStarted)
					{
						CheckBinaryState();
						serverProcessIdentifier = RunProcess(binaryPath, false, NULL, &stdoutServerPipe, NULL);
						serverStarted = true;
					}
				}

				//! Stops Eureqa's Linux server's binary
				void StopServer()
				{
					if (serverStarted)
					{
						KillProcess(serverProcessIdentifier);
						serverStarted = false;
						serverProcessIdentifier = 0;
					}
				}

			private:

				//! Internal function to check if the server's binary isn't used by another process
				void CheckBinaryState()
				{
					std::string exceptionMessage;

					// Check if 'lsof' and 'echo' are supported on the used Linux distribution
					if(checkBinaryStateAllowed)
					{
						/*
						 * The trick is to 'be sure' that the command's output contains at least one character
						 * In the case of the following command it will be '$' character
						 */
						std::string command = "echo \"`lsof " + this->binaryPath + "`$\"";

						int outputPipeAddress;
						char outputBuffer;

						RunProcess(command, true, NULL, &outputPipeAddress, NULL);
						read(outputPipeAddress, &outputBuffer, 1);

						if(outputBuffer != '$')
							throw "Cannot run server's binary - file's already in use or doesn't exist";
					}
					else
					{
						throw "Cannot check binary's state";
					}
				}

				//! Internal function used to kill a process under Linux environment
				/*
				 * \param processIdentifier identifier of a process (or process group) to be killed
				 * \return Boolean value indicating if the process has been terminated
				 */
				void KillProcess(pid_t processIdentifier)
				{
					if(kill(processIdentifier, SIGKILL) !=0)
						throw "Cannot kill the process: " + ToString(processIdentifier);
				}

				//! Internal function used to run a process under Linux environment
				/*
				 * \param command command to be executed
				 * \param shUse flag indicating if /bin/sh should be used to run the process
				 * \param stdinPipe pipe used for 'stdin' of the process
				 * \param stdoutPipe pipe used for 'stdout' of the process
				 * \param stderrPipe pipe used for 'stderr' of the process
				 * \return Identifier of the newly created process
				 */
				pid_t RunProcess(std::string command, bool shUse, int* stdinPipe, int* stdoutPipe, int* stderrPipe)
				{
					const unsigned int IN  = 0;
					const unsigned int OUT = 1;
					const unsigned int ERR = 2;

					int _stdinPipe[2];
					int _stdoutPipe[2];
					int _stderrPipe[2];

					std::string exceptionMessage;

					if (pipe(_stdinPipe) !=0 || pipe(_stdoutPipe) != 0 , pipe(_stderrPipe) != 0)
					{
						throw "Cannot create pipes controlling the process";
					}

					signal(SIGCHLD, SIG_IGN);
					pid_t processIdentifier = fork();

					if(processIdentifier == 0)
					{
						// Perform 'stdin', 'stdout' and 'stderr' redirections
						close(_stdinPipe[OUT]);
						dup2(_stdinPipe[IN], IN);
						close(_stdoutPipe[IN]);
						dup2(_stdoutPipe[OUT], OUT);
						close(_stderrPipe[IN]);
						dup2(_stderrPipe[OUT], ERR);

						// Execute the command
						if(shUse)
							execl("/bin/sh", "sh", "-c", command.c_str(), NULL);
						else
							execl(command.c_str(), command.c_str(), NULL);

						// The program shouldn't reach this point
						throw "Cannot start the process";
					}

					if(stdinPipe == NULL)
						close(_stdinPipe[OUT]);
					else
						*stdinPipe = _stdinPipe[OUT];

					if(stdoutPipe == NULL)
						close(_stdoutPipe[IN]);
					else
						*stdoutPipe = _stdoutPipe[IN];

					if(stderrPipe == NULL)
						close(_stderrPipe[IN]);
					else
						*stderrPipe = _stderrPipe[IN];

					return processIdentifier;
				}

				//! Full name of the Eureqa's server's Linux binary
				std::string binaryPath;

				//! Pipe's address for Eureqa's server's 'stdout'
				int stdoutServerPipe;

				//! Server's binary process identifier
				pid_t serverProcessIdentifier;

				//! Flag indicating if the Eureqa's server has been started
				bool serverStarted;

				//! Flag indicating if the running environment allows to check file's state
				bool checkBinaryStateAllowed;
			};

		#endif /* linux */

		#if defined(__WIN32__) || defined(__WIN64__) || defined(_WIN32) || defined(_WIN64)
		#endif /* _WIN32_ || _WIN64_ || _WIN32 || _WIN64 */

		//! Instance of ServerStarter class
		boost::scoped_ptr<ServerStarter> serverStarter;
};


/**
 * Singleton's initialization
 */

bool EureqaServerCommunicator::initialized;
EureqaServerCommunicator EureqaServerCommunicator::instance;


class EureqaServerController
{
	public:

		static bool StartServer(std::string binaryPath)
		{
			EureqaServerCommunicator::GetInstance()->SetBinaryPath(binaryPath);
			EureqaServerCommunicator::GetInstance()->StartServer();
		}

		static bool StopServer() {EureqaServerCommunicator::GetInstance()->StopServer();}
};

#endif /* SERVERMANAGER_H_ */
