/*
 * TODO: description
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef SERVERINFO_H_
#define SERVERINFO_H_


#include <eureqa/server_info.h>


class ServerInfo
{
	private:

		eureqa::server_info instance;

	public:

		/**
		 * Since those variables will be visible directly from Python, they are written with lowercase_separated_by_underscores
		 */
		std::string& hostname;
		std::string& operating_system;
		double& eureqa_version;
		int& cpu_cores;

		// Wrapper for default constructor
		ServerInfo() :	hostname(instance.hostname_),
						operating_system(instance.operating_system_),
						eureqa_version(instance.eureqa_version_),
						cpu_cores(instance.cpu_cores_)
						{}

		// Wrapper for function testing if info is entered and in range
		bool IsValid() {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the server info
		std::string Summary() {return instance.summary();}
};


#endif /* SERVERINFO_H_ */
