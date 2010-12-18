/*
 *  Wrapper class for eureqa::connection
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <boost/thread/thread.hpp>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

#include <eureqa/connection.h>

#include "DataSet.h"
#include "SearchOptions.h"
#include "SearchProgress.h"
#include "ServerInfo.h"
#include "SolutionFrontier.h"

#include "../EureqaServerController.h"

#define CONN_TIMEOUT 30
#define LOCALHOST "127.0.0.1"


//! ConnectionChecker class
/*
 * It tries to establish connection with an Eureqa's server for a certain defined amount of
 * time given in CONN_TIMEOUT (used only if the server's address is localhost)
 */
class ConnectionChecker
{

	public:

		//! Parameterized constructor
		/*
		 * \param connection reference to the Eureqa's server's connection
		 */
		ConnectionChecker(eureqa::connection& connection) : connection(connection) {}

		//! Overriding function for the '()' operator
		void operator ()() {while(!connection.connect(LOCALHOST));}

	private:

		//! Constructor
		/*
		 * Default constructor - made private to allow only parameterized initialization
		 */
		ConnectionChecker();

		//! Reference to the Eureqa's server's connection
		eureqa::connection& connection;
};

class CommandResult
{
	private:

		eureqa::command_result instance;

	public:

		// Wrappers for constructors
		CommandResult() {}
		CommandResult(int value, std::string message) : instance(value, message) {}

		// Constructor taking eureqa::command_result as the parameter
		CommandResult(const eureqa::command_result& instance) {this->instance = instance;}

		// Getters and setters for eureqa::command_result's public members
		int GetValue() {return instance.value_;}
		void SetValue(int value) {instance.value_ = value;}
		std::string GetMessage() {return instance.message_;}
		void SetMessage(std::string message) {instance.message_ = message;}
};

class Connection
{
	private:

		eureqa::connection instance;

		// Utility functions
		std::vector<SolutionInfo> CreateWrappersVector(std::vector<eureqa::solution_info> input)
		{
			std::vector<SolutionInfo> output;
			foreach(eureqa::solution_info solutionInfo, input)
				output.push_back(SolutionInfo(solutionInfo));
		}
		std::vector<eureqa::solution_info> CreateEureqaVector(std::vector<SolutionInfo> input)
		{
			std::vector<eureqa::solution_info> output;
			foreach(SolutionInfo solutionInfo, input)
				output.push_back(eureqa::solution_info(solutionInfo.GetInstance()));
		}

	public:

		// Wrappers for constructors
		Connection() {}
		Connection(const Connection& connection) {}
		Connection(std::string hostname) : instance(hostname, eureqa::default_port_tcp) {}
		Connection(std::string hostname, int port) : instance(hostname, port) {}
		// TODO: connection(boost::asio::ioconnection(boost::asio::io_service& io_service);_service& io_service);

		// Wrappers for basic connection information
		bool IsConnected() {return instance.is_connected();}
		CommandResult LastResult() {return CommandResult(instance.last_result());}

		// Wrappers for functions opening a network connection to a eureqa server
		bool Connect(std::string hostname) {return instance.connect(hostname, eureqa::default_port_tcp);}
		bool Connect(std::string hostname, unsigned int port) {return instance.connect(hostname, port);}
		void Disconnect() {instance.disconnect();}

		// Function opening a newtork connection to a eureqa server which operates
		// on localhost
		bool Connect(unsigned int timeout)
		{
		    /*
		     * Since it can take longer for Eureqa's server to start, the working thread will attempt
		     * to 'ping' the server for a period of time
		     */
			ConnectionChecker connectionChecker(instance);
			boost::thread connectionCheckerThread(boost::ref(connectionChecker));
			if(!connectionCheckerThread.timed_join(boost::posix_time::seconds(timeout)))
			{
				EureqaServerCommunicator::GetInstance()->ReportServerError();
				return false;
			}
			return true;
		}

		// Wrappers for functions sending server the data set over the network
		// or telling it to load it from a network file
		bool SendData(DataSet data) {return instance.send_data_set(data.GetInstance());}
		bool SendDataLocation(std::string path) {return instance.send_data_location(path);}

		// Wrapper for functions sending server the search options
		bool SendOptions(SearchOptions searchOptions) {return instance.send_options(searchOptions.GetInstance());}

		// Wrappers for functions sending server individuals to insert into its population
		bool SendIndividuals(std::string text) {return instance.send_individuals(text);}
		bool SendIndividuals(SolutionInfo solutionInfo) {return instance.send_individuals(solutionInfo.GetInstance());}
		bool SendIndividuals(std::vector<SolutionInfo> individuals) {return false;} //TODO: make it inline

		//  Wrapper for function sending server a population
		bool SendPopulation(std::vector<SolutionInfo> individuals) {return false;} //TODO: make it inline

		//  Wrapper for function querying server for information on the search progress (NOTE change concerning the return value)
		boost::tuple<bool, SearchProgress> QueryProgress()
		{
			eureqa::search_progress searchProgress;
			return boost::make_tuple(instance.query_progress(searchProgress), SearchProgress(searchProgress));
		}

		//  Wrapper for function querying server for its system information (NOTE change concerning the return value)
		boost::tuple<bool, ServerInfo> QueryServerInfo()
		{
			eureqa::server_info serverInfo;
			return boost::make_tuple(instance.query_server_info(serverInfo), ServerInfo(serverInfo));
		}

		//  Wrappers for functions querying server for random individuals from its population (NOTE change concerning the return value)
		boost::tuple<bool, SolutionInfo> QueryIndividuals()
		{
			eureqa::solution_info solutionInfo;
			return boost::make_tuple(instance.query_individuals(solutionInfo), SolutionInfo(solutionInfo));
		}
		boost::tuple<bool, std::vector<SolutionInfo> > QueryIndividuals(unsigned int count)
		{
			std::vector<eureqa::solution_info> individuals;

			std::vector<SolutionInfo> secondElement;
			bool firstElement;

			firstElement = instance.query_individuals(individuals, count);

			if(firstElement)
				foreach(eureqa::solution_info solutionInfo, individuals)
					secondElement.push_back(SolutionInfo(solutionInfo));

			return boost::make_tuple(firstElement, secondElement);
		}

		//  Wrappers for function querying server for the current population (NOTE change concerning the return value)
		boost::tuple<bool, std::vector<SolutionInfo> > QueryPopulation()
		{
			std::vector<eureqa::solution_info> individuals;

			std::vector<SolutionInfo> secondElement;
			bool firstElement;

			firstElement = instance.query_population(individuals);

			if(firstElement)
				foreach(eureqa::solution_info solutionInfo, individuals)
					secondElement.push_back(SolutionInfo(solutionInfo));

			return boost::make_tuple(firstElement, secondElement);
		}

		//  Wrapper for function querying the servers local solution frontier (NOTE change concerning the return value)
		boost::tuple<bool, SolutionFrontier> QueryFrontier()
		{
			eureqa::solution_frontier solutionFrontier;
			return boost::make_tuple(instance.query_frontier(solutionFrontier), SolutionFrontier(solutionFrontier));
		}

		//  Wrappers for functions telling server to start/pause/end searching
		bool StartSearch() {return instance.start_search();}
		bool PauseSearch() {return instance.pause_search();}
		bool EndSearch() {return instance.end_search();}

		//  Wrappers for functions calculating the solution info on the server (NOTE change concerning the return value)
		boost::tuple<bool, SolutionInfo> CalcSolutionInfo(SolutionInfo solutionInfo)
		{
			eureqa::solution_info _solutionInfo = solutionInfo.GetInstance();
			return boost::make_tuple(instance.calc_solution_info(_solutionInfo), SolutionInfo(_solutionInfo));
		}
		boost::tuple<bool, std::vector<SolutionInfo> > CalcSolutionInfo(std::vector<SolutionInfo> individuals)
		{
			std::vector<eureqa::solution_info> _individuals;

			foreach(SolutionInfo solutionInfo, individuals)
				_individuals.push_back(solutionInfo.GetInstance());

			std::vector<SolutionInfo> secondElement;
			bool firstElement;

			firstElement = instance.query_population(_individuals);

			if(firstElement)
				foreach(eureqa::solution_info solutionInfo, _individuals)
					secondElement.push_back(SolutionInfo(solutionInfo));

			return boost::make_tuple(firstElement, secondElement);
		}

		// Wrapper for functions returning a short description of the connection
		std::string Summary() const {return instance.summary();}
		std::string RemoteAddress() const {return instance.remote_address();}
		int RemotePort() const {return instance.remote_port();}
};


#endif /* CONNECTION_H_ */
