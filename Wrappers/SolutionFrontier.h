/*
 *  Wrapper classes for eureqa::solution_info and eureqa::solution_frontier
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */


#ifndef SOLUTIONFRONTIER_H_
#define SOLUTIONFRONTIER_H_


#include <eureqa/solution_frontier.h>


class SolutionInfo
{
	private:

		eureqa::solution_info instance;

	public:

		// Wrapper for eureqa::solution_info's constructor with default parameter's value
		SolutionInfo() : instance("") {}

		// Wrapper for eureqa::solution_info's constructor
		SolutionInfo(std::string text) : instance(text) {}

		// Constructor taking eureqa::solution_info as the parameter (C++ usage)
		SolutionInfo(const eureqa::solution_info& instance) {this->instance = instance;}

		// Getter for the eureqa::solution_info's instance (C++ usage)
		const eureqa::solution_info& GetInstance() {return instance;}

		// Wrappers for functions testing if the solution dominates another solution in fitness and complexity
		bool Dominates(SolutionInfo solutionInfo) {return instance.dominates(solutionInfo.GetInstance());}
		bool Matches(SolutionInfo solutionInfo) {return instance.matches(solutionInfo.GetInstance());}

		// Getters and setters for eureqa::solution_info's public members
		unsigned int GetAge() const {return instance.age_;}
		void SetAge(unsigned int age) {instance.age_ = age;}
		float GetComplexity() const {return instance.complexity_;}
		void SetComplexity(float complexity) {instance.complexity_ = complexity;}
		float GetFitness() const {return instance.fitness_;}
		void SetFitness(float fitness) {instance.fitness_ = fitness;}
		float GetScore() const {return instance.score_;}
		void SetScore(float score) {instance.score_ = score;}
		std::string GetText() const {return instance.text_;}
		void SetText(std::string text) {instance.text_ = text;}
};


class SolutionFrontier
{
	private:

		eureqa::solution_frontier instance;

	public:

		// Default constructor
		SolutionFrontier() {}

		// Constructor taking eureqa::solution_frontier as the parameter (C++ usage)
		SolutionFrontier(const eureqa::solution_frontier& instance){this->instance = instance;}

		// Wrapper for function adding solution to the pareto front if non-dominated
		// and removing any existing dominated by the solution
		bool Add(SolutionInfo solutionInfo) {return instance.add(solutionInfo.GetInstance());}

		// Wrapper for function testing if a solution is non-dominated and not already on the current frontier
		bool Test(SolutionInfo solutionInfo) {return instance.test(solutionInfo.GetInstance());}

		// Wrapper for function returning a text display of the frontier
		std::string ToString() const {return instance.to_string();}

		// Wrappers for basic container functions
		int Size() const {return instance.size();}
		SolutionInfo operator [] (int i) {return SolutionInfo(instance[i]);}
		void Clear() {instance.clear();}
		void Remove(int i) {instance.remove(i);}
};


#endif /* SOLUTIONFRONTIER_H_ */


/**
 *
 * Eventual TODO:
 * const solution_info& operator [](int i) const { return front_[i]; }
 *
 */
