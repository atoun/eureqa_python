/*
 * TODO: description
 *
 *  Created on: Nov 21, 2010
 *      Author: MF
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_


#include <eureqa/connection.h>


// TODO: command_result

class Connection
{
	private:

		eureqa::connection instance;

	public:

		// Wrappers for constructors
		Connection(const Connection& c) {/*TODO:*/}
		Connection() {}
		// Connection(std::string hostname, int port = eureqa::default_port_tcp) : instance(new eureqa::connection(hostname, port)) {}
		// TODO: connection(boost::asio::ioconnection(boost::asio::io_service& io_service);_service& io_service);

		// Wrappers for basic connection information
		bool IsConnected() {return instance.is_connected();}
		// TODO: connection(boost::asio::io_service& io_service);

		// Wrappers for functions opening a network connection to a eureqa server
		bool Connect(std::string hostname, int port) {return instance.connect(hostname, port);}
		void Disconnect() {instance.disconnect();}

		// Wrappers for functions sending server the data set over the network
		// or telling it to load it from a network file
		// TODO: bool send_data_set(const eureqa::data_set& data);
		bool SendDataLocation(std::string path) {return instance.send_data_location(path);}

		// Wrapper for functions sending server the search options
		// TODO: bool send_options(const eureqa::search_options& options);

		// Wrappers for functions sending server individuals to insert into its population
		bool SendIndividuals(std::string text) {return instance.send_individuals(text);}
		// TODO: bool send_individuals(eureqa::solution_info soln);
		// TODO: bool send_individuals(const std::vector<eureqa::solution_info>& individuals);

		//  Wrapper for function sending server a population
		// TODO: bool send_population(const std::vector<eureqa::solution_info>& individuals);

		//  Wrapper for function querying server for information on the search progress
		// TODO: bool query_progress(eureqa::search_progress& progress);

		//  Wrapper for function querying server for its system information
		// TODO: bool query_server_info(eureqa::server_info& info);

		//  Wrappers for functions querying server for random individuals from its population
		// TODO: bool query_individuals(eureqa::solution_info& soln);
		// TODO: bool query_individuals(std::vector<eureqa::solution_info>& individuals, int count);

		//  Wrappers for function querying server for the current population
		// TODO: bool query_population(std::vector<eureqa::solution_info>& individuals);

		//  Wrapper for function querying the servers local solution frontier
		// TODO: bool query_frontier(eureqa::solution_frontier& front);

		//  Wrappers for functions telling server to start/pause/end searching
		bool StartSearch() {return instance.start_search();}
		bool PauseSearch() {return instance.pause_search();}
		bool EndSearch() {return instance.end_search();}

		//  Wrappers for functions calculating the solution info on the server
		// TODO: bool calc_solution_info(eureqa::solution_info& soln);
		// TODO: bool calc_solution_info(std::vector<eureqa::solution_info>& individuals);

		// returns are a short description of the connection
		std::string Summary() const {return instance.summary();}
		std::string RemoteAddress() const {return instance.remote_address();}
		int RemotePort() const {return instance.remote_port();}
};


#endif /* CONNECTION_H_ */
