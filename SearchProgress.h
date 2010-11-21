/*
 * SearchProgress.h
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef SEARCHPROGRESS_H_
#define SEARCHPROGRESS_H_


#include <eureqa/search_progress.h>


class SearchProgress
{
	private:

		eureqa::search_progress instance;

	public:

//		TODO: solution_info solution_; // a solution recently added server's solution frontier
//		TODO: float generations_; // total generations completed
//		TODO: float generations_per_sec_; // generations speed
//		TODO: float evaluations_; // total times any equation was evaluated
//		TODO: float evaluations_per_sec_; // evaluation speed
//		TODO: int total_population_size_; // total number of individuals in the current population
//

		// Wrapper for default constructor
		SearchProgress() {}

		// Wrapper for function testing if fields are entered and in range
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the search progress
		std::string Summary() const {return instance.summary();}
};


#endif /* SEARCHPROGRESS_H_ */

