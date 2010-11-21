/*
 * ServerInfo.h
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
//		solution_info solution_; // a solution recently added server's solution frontier
//		float generations_; // total generations completed
//		float generations_per_sec_; // generations speed
//		float evaluations_; // total times any equation was evaluated
//		float evaluations_per_sec_; // evaluation speed
//		int total_population_size_; // total number of individuals in the current population

		// Wrapper for default constructor
		ServerInfo() {}

		// Wrapper for function testing if info is entered and in range
		bool IsValid() {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the server info
		std::string Summary() {return instance.summary();}
};


#endif /* SERVERINFO_H_ */
