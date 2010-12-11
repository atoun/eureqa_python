/*
 * TODO: description
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_


#include <eureqa/connection.h>

#include "DataSet.h"
#include "SearchOptions.h"
#include "SearchProgress.h"
#include "ServerInfo.h"
#include "SolutionFrontier.h"


class CommandResult
{
	private:

		eureqa::command_result instance;

	public:

		// Wrappers for constructors
		CommandResult() {}
		CommandResult(int value, std::string message) : instance(value, message) {}

		// Constructor taking eureqa::command_result as the parameter
		CommandResult(const eureqa::command_result& instance) {this->instance = instance;}

		// Getters and setters for eureqa::command_result's public members
		int GetValue() {return instance.value_;}
		void SetValue(int value) {instance.value_ = value;}
		std::string GetMessage() {return instance.message_;}
		void SetMessage(std::string message) {instance.message_ = message;}
};

class Connection
{
	private:

		eureqa::connection instance;

	public:

		// Wrappers for constructors
		Connection() {}
		Connection(std::string hostname) : instance(hostname, eureqa::default_port_tcp) {}
		Connection(std::string hostname, int port) : instance(hostname, port) {}
		// TODO: connection(boost::asio::ioconnection(boost::asio::io_service& io_service);_service& io_service);

		// Wrappers for basic connection information
		bool IsConnected() {return instance.is_connected();}
		CommandResult LastResult() {return CommandResult(instance.last_result());}

		// Wrappers for functions opening a network connection to a eureqa server
		bool Connect(std::string hostname, int port) {return instance.connect(hostname, port);}
		void Disconnect() {instance.disconnect();}

		// Wrappers for functions sending server the data set over the network
		// or telling it to load it from a network file
		bool SendData(DataSet data) {return instance.send_data_set(data.GetInstance());}
		bool SendDataLocation(std::string path) {return instance.send_data_location(path);}

		// Wrapper for functions sending server the search options
		bool SendOptions(SearchOptions searchOptions) {return instance.send_options(searchOptions.GetInstance());}

		// Wrappers for functions sending server individuals to insert into its population
		bool SendIndividuals(std::string text) {return instance.send_individuals(text);}
		bool SendIndividuals(SolutionInfo solutionInfo) {return instance.send_individuals(solutionInfo.GetInstance());}
		bool SendIndividuals(std::vector<SolutionInfo> individuals) {return false;} //TODO: make it inline

		//  Wrapper for function sending server a population
		bool SendPopulation(std::vector<SolutionInfo> individuals) {return false;} //TODO: make it inline

		//  Wrapper for function querying server for information on the search progress
		boost::tuple<int> QueryProgress(); //TODO: make it inline

		//  Wrapper for function querying server for its system information
		boost::tuple<int> QueryServerInfo(); //TODO: make it inline

		//  Wrappers for functions querying server for random individuals from its population
		boost::tuple<int> QueryIndividuals(); //TODO: make it inline
		boost::tuple<int> QueryIndividuals(int count); //TODO: make it inline

		//  Wrappers for function querying server for the current population
		boost::tuple<int> QueryPopulation(); //TODO: make it inline

		//  Wrapper for function querying the servers local solution frontier
		boost::tuple<int> QueryFrontier(); //TODO: make it inline

		//  Wrappers for functions telling server to start/pause/end searching
		bool StartSearch() {return instance.start_search();}
		bool PauseSearch() {return instance.pause_search();}
		bool EndSearch() {return instance.end_search();}

		//  Wrappers for functions calculating the solution info on the server
		boost::tuple<int> CalcSolutionInfo(SolutionInfo solutionInfo); //TODO: make it inline
		boost::tuple<int> CalcSolutionInfo(std::vector<SolutionInfo> individuals); //TODO: make it inline

		// returns are a short description of the connection
		std::string Summary() const {return instance.summary();}
		std::string RemoteAddress() const {return instance.remote_address();}
		int RemotePort() const {return instance.remote_port();}
};


#endif /* CONNECTION_H_ */
