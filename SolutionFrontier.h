/*
 * TODO: description
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

		// Getter for the eureqa::solution_info's instance
		const eureqa::solution_info& GetInstance()  {return instance;}

		// Wrapper for default constructor
		SolutionInfo(std::string text = "") : instance(text) {}

		// TODO: Description and check if it works!
		SolutionInfo(eureqa::solution_info& instance) {/*TODO: Implement*/}

		// Wrappers for functions testing if the solution dominates another solution in fitness and complexity
		bool Dominates(SolutionInfo& solutionInfo) {return instance.dominates(solutionInfo.GetInstance());}
		bool Matches(SolutionInfo& solutionInfo) {return instance.matches(solutionInfo.GetInstance());}
};


class SolutionFrontier
{
	private:

		eureqa::solution_frontier instance;

	public:

		// Wrapper for function adding solution to the pareto front if non-dominated
		// and removing any existing dominated by the solution
		// TODO: bool Add(const SolutionInfo& solutionInfo) {return instance.add(solutionInfo.GetInstance());}

		// Wrapper for function testing if a solution is non-dominated and not already on the current frontier
		// TODO: bool Test(const SolutionInfo& solutionInfo) {return instance.test(solutionInfo.GetInstance());}

		// Wrapper for function returning a text display of the frontier
		std::string ToString() const {return instance.to_string();}

		// Wrappers for basic container functions
		int Size() const {return instance.size();}
		// TODO: solution_info& operator [](int i) { return front_[i]; }
		// TODO: const solution_info& operator [](int i) const { return front_[i]; }
		void Clear() {instance.clear();}
		void Remove(int i) {instance.remove(i);}
};

#endif /* SOLUTIONFRONTIER_H_ */
