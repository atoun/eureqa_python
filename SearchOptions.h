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

		/**
		 * Since those variables will be visible directly from Python, they are written with lowercase_separated_by_underscores
		 */
		std::string& search_relationship;
		//TODO: std::vector<std::string> building_blocks_;
		float& normalize_fitness_by;
		int& fitness_metric;
		int& solution_population_size;
		int& predictor_population_size;
		int& trainer_population_size;
		float& solution_crossover_probability;
		float& solution_mutation_probability;
		float& predictor_crossover_probability;
		float& predictor_mutation_probability;
		std::string& implicit_derivative_dependencies;

		int& max_delays_per_variable;
		float& max_history_fraction;
		int& min_implicit_variables_used;

		// Wrapper for default constructor
		SearchOptions(std::string searchRelationship = "0=f(0)") :	instance(searchRelationship),
																	search_relationship(instance.search_relationship_),
																	//TODO: std::vector<std::string> building_blocks_
																	normalize_fitness_by(instance.normalize_fitness_by_),
																	fitness_metric(instance.fitness_metric_),
																	solution_population_size(instance.solution_population_size_),
																	predictor_population_size(instance.predictor_population_size_),
																	trainer_population_size(instance.trainer_population_size_),
																	solution_crossover_probability(instance.solution_crossover_probability_),
																	solution_mutation_probability(instance.solution_mutation_probability_),
																	predictor_crossover_probability(instance.predictor_crossover_probability_),
																	predictor_mutation_probability(instance.predictor_mutation_probability_),
																	implicit_derivative_dependencies(instance.implicit_derivative_dependencies_),
																	max_delays_per_variable(instance.max_delays_per_variable_),
																	max_history_fraction(instance.max_history_fraction_),
																	min_implicit_variables_used(instance.min_implicit_variables_used_)
																	{}

		// Wrapper for function testing if the options are entered and in range
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function setting default search options
		void SetDefaultOptions() {instance.set_default_options();}
		void SetDefaultBuildingBlocks() {instance.set_default_building_blocks();}

		// Wrapper for function returning a short text summary of the search options
		std::string Summary() const {return instance.summary();}
};


#endif /* SEARCHOPTIONS_H_ */
