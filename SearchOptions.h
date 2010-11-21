/*
 * SearchOptions.h
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef SEARCHOPTIONS_H_
#define SEARCHOPTIONS_H_


#include <eureqa/search_options.h>


class SearchOptions
{
	private:

		eureqa::search_options instance;

	public:

// TODO:		std::string search_relationship_;
// TODO:		std::vector<std::string> building_blocks_;
// TODO:		float normalize_fitness_by_;
// TODO:		int fitness_metric_;
// TODO:		int solution_population_size_;
// TODO:		int predictor_population_size_;
// TODO:		int trainer_population_size_;
// TODO:		float solution_crossover_probability_;
// TODO:		float solution_mutation_probability_;
// TODO:		float predictor_crossover_probability_;
// TODO:		float predictor_mutation_probability_;
// TODO:		std::string implicit_derivative_dependencies_;
//
// TODO:		int max_delays_per_variable_;
// TODO:		float max_history_fraction_;
// TODO:		int min_implicit_variables_used_;

		// Wrapper for default constructor
		// SearchOptions(std::string searchRelationship = "0=f(0)") : instance(searchRelationship {}

		// Wrapper for function testing if the options are entered and in range
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function setting default search options
		void SetDefaultOptions() {instance.set_default_options();}
		void SetDefaultBuildingBlocks() {instance.set_default_building_blocks();}

		// Wrapper for function returning a short text summary of the search options
		std::string Summary() const {return instance.summary();}
};

#endif /* SEARCHOPTIONS_H_ */
