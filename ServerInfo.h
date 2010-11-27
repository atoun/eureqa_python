/*
 *  Wrapper class for eureqa::server_info
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

		// Wrapper for default constructor
		ServerInfo() {}

		// Wrapper for function testing if info is entered and in range
		bool IsValid() {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the server info
		std::string Summary() {return instance.summary();}

		// Getters and setters for eureqa::server_info's public members
		std::string GetHostname() {return instance.hostname_;}
		void SetHostname(std::string hostname) {instance.hostname_ = hostname;}
		std::string GetOperatingSystem() {return instance.operating_system_;}
		void SetOperatingSystem(std::string operating_system) {instance.operating_system_ = operating_system;}
		double GetEureqaVersion() {return instance.eureqa_version_;}
		void SetEureqaVersion(double eureqa_version) {instance.eureqa_version_ = eureqa_version;}
		int GetCpuCores() {return instance.cpu_cores_;}
		void SetCpuCores(int cpu_cores) {instance.cpu_cores_ = cpu_cores;}
};


#endif /* SERVERINFO_H_ */
