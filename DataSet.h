/*
 * TODO: description
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <eureqa/data_set.h>

class DataSet
{
	private:

		eureqa::data_set instance;

	public:
//		std::vector<int> r_; // series identifier (optional)
//		std::vector<float> t_; // time ordering values (optional)
//		std::vector<float> w_; // weight values (optional)
//		boost::numeric::ublas::matrix<float> X_; // data values
//		boost::numeric::ublas::matrix<float> Y_; // special values (reserved)
//		std::vector<std::string> X_symbols_; // symbols for data values
//		std::vector<std::string> Y_symbols_; // symbols for special values (reserved)


		// Wrappers for constructors
		DataSet(const DataSet& c) {/*TODO:*/}
		DataSet() {}
		DataSet(std::string path) : instance(path) {}
		DataSet(int rows, int cols) : instance(rows,cols) {}

		// Wrapper for function testing if the data set is sized and filled in correctly
		bool IsValid() const {return instance.is_valid();}

		// Wrapper for function setting symbols as { x1, x2, x3, ... }
		void SetDefaultSymbols() {instance.set_default_symbols();}

		// Wrappers for basic container member functions
		int Size() const {return instance.size();}
		int NumVars() const {return instance.num_vars();}
		int SpecialVars() const {return instance.special_vars();}
		// TODO: float& operator ()(int i, int j)       { return X_(i,j); }
		// TODO: const float& operator ()(int i, int j) const { return X_(i,j); }
		void Clear() {instance.clear();}
		// TODO: void swap(data_set& d);
		void Resize(int rows, int cols) {instance.resize(rows,cols);}
		bool Empty() const {return instance.empty();}

		// Wrappers for functions importing plain ascii text files with single line header
		// can read a eureqa header, plain column header, or missing header
		// data can be delimited by whitespace or commas
		// lines can be commented using the '%' character
		// TODO: bool import_ascii(std::string path);
		// TODO: bool import_ascii(std::string path, std::string& error_msg);
		// TODO: bool import_ascii(std::istream& is);
		// TODO: bool import_ascii(std::istream& is, std::string& error_msg);
		// TODO: void export_ascii(std::string path) { std::ofstream file(path.c_str()); export_ascii(file); }
		// TODO: void export_ascii(std::ostream& os);

		// Wrapper for function returning a short text summary of the data set
		std::string Summary() const {return instance.summary();}
};


#endif /* DATASET_H_ */
