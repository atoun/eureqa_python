/*
 *  Wrapper class for eureqa::search_progress
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

		// Wrapper for default constructor
		SearchProgress() {}

		// Wrapper for function testing if fields are entered and in range
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function returning a short text summary of the search progress
		std::string Summary() const {return instance.summary();}

		// Getters and setters for eureqa::search_progress's public members
		float GetEvaluations() {return instance.evaluations_;}
	    void SetEvaluations(float evaluations) {instance.evaluations_ = evaluations;}
	    float GetEvaluationsPerSec() {return instance.evaluations_per_sec_;}
	    void SetEvaluationsPerSec(float evaluationsPerSec) {instance.evaluations_per_sec_ = evaluationsPerSec;}
		float GetGenerations() {return instance.generations_;}
		void SetGenerations(float generations) {instance.generations_ = generations;}
	    float GetGenerationsPerSec() {return instance.evaluations_per_sec_;}
	    void SetGenerationsPerSec(float generationsPerSec) {instance.generations_per_sec_ = generationsPerSec;}
		SolutionInfo GetSolution() {return SolutionInfo(instance.solution_);}
		void SetSolution(SolutionInfo& solution) {instance.solution_ = solution.GetInstance();}
	    int GetTotalPopulationSize() {return instance.total_population_size_;}
	    void SetTotalPopulationSize(int totalPopulationSize) {instance.total_population_size_ = totalPopulationSize;}
};


#endif /* SEARCHPROGRESS_H_ */
