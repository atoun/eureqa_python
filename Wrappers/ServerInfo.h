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

		// Constructor taking eureqa::server_info as the parameter (C++ usage)
		ServerInfo(const eureqa::server_info& instance) {this->instance = instance;}

		// Getter for the eureqa::server_info's instance (C++ usage)
		const eureqa::server_info& GetInstance() {return instance;}

		// Wrapper for function testing if info is entered and in range
		bool IsValid() {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the server info
		std::string Summary() {return instance.summary();}

		// Getters and setters for eureqa::server_info's public members
		int GetCpuCores() const {return instance.cpu_cores_;}
		void SetCpuCores(int cpu_cores) {instance.cpu_cores_ = cpu_cores;}
		double GetEureqaVersion() const {return instance.eureqa_version_;}
		void SetEureqaVersion(double eureqa_version) {instance.eureqa_version_ = eureqa_version;}
		std::string GetHostname() const {return instance.hostname_;}
		void SetHostname(std::string hostname) {instance.hostname_ = hostname;}
		std::string GetOperatingSystem() const {return instance.operating_system_;}
		void SetOperatingSystem(std::string operating_system) {instance.operating_system_ = operating_system;}
};


#endif /* SERVERINFO_H_ */
