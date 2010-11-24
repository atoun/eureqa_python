/*
 * TODO: description
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef SEARCHPROGRESS_H_
#define SEARCHPROGRESS_H_


#include <eureqa/search_progress.h>

#include "SolutionFrontier.h"


class SearchProgress
{
	private:

		eureqa::search_progress instance;

	public:

		/**
		 * Since those variables will be visible directly from Python, they are written with lowercase_separated_by_underscores
		 */
		SolutionInfo solution;
		float& generations;
		float& generations_per_sec;
		float& evaluations;
		float& evaluations_per_sec;
		int& total_population_size;


		// Wrapper for default constructor
		SearchProgress() :	solution(instance.solution_),
							generations(instance.generations_),
							generations_per_sec(instance.generations_per_sec_),
							evaluations(instance.evaluations_),
							evaluations_per_sec(instance.evaluations_per_sec_),
							total_population_size(instance.total_population_size_)
							{}


		// Wrapper for function testing if fields are entered and in range
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the search progress
		std::string Summary() const {return instance.summary();}
};


#endif /* SEARCHPROGRESS_H_ */

