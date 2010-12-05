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
//		boost::numeric::ublas::matrix<float> X_; // data values
//		boost::numeric::ublas::matrix<float> Y_; // special values (reserved)

		// Wrappers for constructors
		DataSet() {}
		DataSet(std::string path) : instance(path) {}
		DataSet(int rows, int cols) : instance(rows,cols) {}

		// Getter for eureqa::data_set's instance
		eureqa::data_set& GetInstance() {return instance;}

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
		void Swap(DataSet dataSet) {instance.swap(dataSet.GetInstance());}
		void Resize(int rows, int cols) {instance.resize(rows,cols);}
		bool Empty() const {return instance.empty();}

		// Wrappers for functions importing plain ascii text files with single line header
		bool ImportAscii(std::string path) {return instance.import_ascii(path);}
		bool ImportAscii(std::string path, std::string& errorMessage) {return instance.import_ascii(path, errorMessage);}
		void ExportAscii(std::string path) {instance.export_ascii(path);}

		// Wrapper for function returning a short text summary of the data set
		std::string Summary() const {return instance.summary();}

		// Getters and setters for eureqa::data_set's public members
		std::vector<int> GetR() {return instance.r_;}
		void SetR(std::vector<int> r) {instance.r_ = r;}
		std::vector<float> GetT() {return instance.t_;}
		void SetT(std::vector<float> t) {instance.t_ = t;}
		std::vector<float> GetW() {return instance.w_;}
		void SetW(std::vector<float> w) {instance.w_ = w;}
		std::vector<std::string> GetXSymbols() {return instance.X_symbols_;}
		void SetXSymbols(std::vector<std::string> xSymbols) {instance.X_symbols_ = xSymbols;}
		std::vector<std::string> GetYSymbols() {return instance.Y_symbols_;}
		void SetYSymbols(std::vector<std::string> ySymbols) {instance.Y_symbols_ = ySymbols;}
};


#endif /* DATASET_H_ */


/**
 * Eventual TODOs
 * bool import_ascii(std::istream& is);
 * bool import_ascii(std::istream& is, std::string& error_msg);
 * void export_ascii(std::ostream& os);
 */
