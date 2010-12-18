#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "Connection.h"
#include "DataSet.h"
#include "SearchOptions.h"
#include "SearchProgress.h"
#include "ServerInfo.h"
#include "SolutionFrontier.h"

#include "EureqaServerController.h"


BOOST_PYTHON_MODULE(eureqa_python)
{
	// Utility class -- std::vector<std::string>
	boost::python::class_<std::vector<std::string> >("StringVector")
	.def(boost::python::vector_indexing_suite<std::vector<std::string> >())
	;

	// Utility class -- std::vector<int>
	boost::python::class_<std::vector<int> >("IntegerVector")
	.def(boost::python::vector_indexing_suite<std::vector<int> >())
	;

	// Utility class -- std::vector<std::float>
	boost::python::class_<std::vector<float> >("FloatVector")
	.def(boost::python::vector_indexing_suite<std::vector<float> >())
	;

	// SearchOptions
	boost::python::class_<SearchOptions>("SearchOptions")
	.def(boost::python::init<std::string>())
	.def("is_valid", &SearchOptions::IsValid)
	.def("set_default_options", &SearchOptions::SetDefaultOptions)
	.def("set_default_building_blocks", &SearchOptions::SetDefaultBuildingBlocks)
	.def("summary", &SearchOptions::Summary)
	.def("get_building_blocks", &SearchOptions::GetBuildingBlocks)
	.def("set_building_blocks", &SearchOptions::SetBuildingBlocks)
	.def("get_fitness_metric", &SearchOptions::GetFitnessMetric)
	.def("set_fitness_metric", &SearchOptions::SetFitnessMetric)
	.def("get_implicit_derivative_dependencies", &SearchOptions::GetImplicitDerivativeDependencies)
	.def("set_implicit_derivative_dependencies", &SearchOptions::SetImplicitDerivativeDependencies)
	.def("get_max_delays_per_variable", &SearchOptions::GetMaxDelaysPerVariable)
	.def("set_max_delays_per_variable", &SearchOptions::SetMaxDelaysPerVariable)
	.def("get_max_history_fraction", &SearchOptions::GetMaxHistoryFraction)
	.def("set_max_history_fraction", &SearchOptions::SetMaxHistoryFraction)
	.def("get_min_implicit_variables_used", &SearchOptions::GetMinImplicitVariablesUsed)
	.def("set_min_implicit_variables_used", &SearchOptions::SetMinImplicitVariablesUsed)
	.def("get_normalize_fitness_by", &SearchOptions::GetNormalizeFitnessBy)
	.def("set_normalize_fitness_by", &SearchOptions::SetNormalizeFitnessBy)
	.def("get_predictor_crossover_probability", &SearchOptions::GetPredictorCrossoverProbability)
	.def("set_predictor_crossover_probability", &SearchOptions::SetPredictorCrossoverProbability)
	.def("get_predictor_mutation_probability", &SearchOptions::GetPredictorMutationProbability)
	.def("set_predictor_mutation_probability", &SearchOptions::SetPredictorMutationProbability)
	.def("get_predictor_population_size", &SearchOptions::GetPredictorPopulationSize)
	.def("set_predictor_population_size", &SearchOptions::SetPredictorPopulationSize)
	.def("get_search_relationship", &SearchOptions::GetSearchRelationship)
	.def("set_search_relationship", &SearchOptions::SetSearchRelationship)
	.def("get_solution_crossover_probability", &SearchOptions::GetSolutionCrossoverProbability)
	.def("set_solution_crossover_probability", &SearchOptions::SetSolutionCrossoverProbability)
	.def("get_solution_mutation_probability", &SearchOptions::GetSolutionMutationProbability)
	.def("set_solution_mutation_probability", &SearchOptions::SetSolutionMutationProbability)
	.def("get_solution_population_size", &SearchOptions::GetSolutionPopulationSize)
	.def("set_solution_population_size", &SearchOptions::SetSolutionPopulationSize)
	.def("get_trainer_population_size", &SearchOptions::GetTrainerPopulationSize)
	.def("set_trainer_population_size", &SearchOptions::SetTrainerPopulationSize)
	.add_property("building_blocks", &SearchOptions::GetBuildingBlocks, &SearchOptions::SetBuildingBlocks)
	.add_property("fitness_metric", &SearchOptions::GetFitnessMetric, &SearchOptions::SetFitnessMetric)
	.add_property("implicit_derivative_dependencies", &SearchOptions::GetImplicitDerivativeDependencies, &SearchOptions::SetImplicitDerivativeDependencies)
	.add_property("max_delays_per_variable", &SearchOptions::GetMaxDelaysPerVariable, &SearchOptions::SetMaxDelaysPerVariable)
	.add_property("max_history_fraction", &SearchOptions::GetMaxHistoryFraction, &SearchOptions::SetMaxHistoryFraction)
	.add_property("min_implicit_variables_used", &SearchOptions::GetMinImplicitVariablesUsed, &SearchOptions::SetMinImplicitVariablesUsed)
	.add_property("normalize_fitness_by", &SearchOptions::GetNormalizeFitnessBy, &SearchOptions::SetNormalizeFitnessBy)
	.add_property("predictor_crossover_probability", &SearchOptions::GetPredictorCrossoverProbability, &SearchOptions::SetPredictorCrossoverProbability)
	.add_property("predictor_mutation_probability", &SearchOptions::GetPredictorMutationProbability, &SearchOptions::SetPredictorMutationProbability)
	.add_property("predictor_population_size", &SearchOptions::GetPredictorPopulationSize, &SearchOptions::SetPredictorPopulationSize)
	.add_property("search_relationship", &SearchOptions::GetSearchRelationship, &SearchOptions::SetSearchRelationship)
	.add_property("solution_crossover_probability", &SearchOptions::GetSolutionCrossoverProbability, &SearchOptions::SetSolutionCrossoverProbability)
	.add_property("solution_mutation_probability", &SearchOptions::GetSolutionMutationProbability, &SearchOptions::SetSolutionMutationProbability)
	.add_property("solution_population_size", &SearchOptions::GetSolutionPopulationSize, &SearchOptions::SetSolutionPopulationSize)
	.add_property("trainer_population_size", &SearchOptions::GetTrainerPopulationSize, &SearchOptions::SetTrainerPopulationSize)
	;

	// SolutionInfo
	boost::python::class_<SolutionInfo>("SolutionInfo")
	.def(boost::python::init<std::string>())
	.def("dominates", &SolutionInfo::Dominates)
	.def("matches", &SolutionInfo::Matches)
	.def("get_age", &SolutionInfo::GetAge)
	.def("set_age", &SolutionInfo::SetAge)
	.def("get_complexity", &SolutionInfo::GetComplexity)
	.def("set_complexity", &SolutionInfo::SetComplexity)
	.def("get_fitness", &SolutionInfo::GetFitness)
	.def("set_fitness", &SolutionInfo::SetFitness)
	.def("get_score", &SolutionInfo::GetScore)
	.def("set_score", &SolutionInfo::SetScore)
	.def("get_text", &SolutionInfo::GetText)
	.def("set_text", &SolutionInfo::SetText)
	.add_property("age", &SolutionInfo::GetAge, &SolutionInfo::SetAge)
	.add_property("complexity", &SolutionInfo::GetComplexity, &SolutionInfo::SetComplexity)
	.add_property("fitness", &SolutionInfo::GetFitness, &SolutionInfo::SetFitness)
	.add_property("score", &SolutionInfo::GetScore, &SolutionInfo::SetScore)
	.add_property("text", &SolutionInfo::GetText, &SolutionInfo::SetText)
	;

	// SolutionFrontier
	boost::python::class_<SolutionFrontier>("SolutionFrontier")
	.def("add", &SolutionFrontier::Add)
	.def("test", &SolutionFrontier::Test)
	.def("to_string", &SolutionFrontier::ToString)
	.def("size", &SolutionFrontier::Size)
	// TODO: operator []
	.def("clear", &SolutionFrontier::Clear)
	.def("remove", &SolutionFrontier::Remove)
	;

	// ServerInfo
	boost::python::class_<ServerInfo>("ServerInfo")
	.def("is_valid", &ServerInfo::IsValid)
	.def("summary", &ServerInfo::Summary)
	.def("get_cpu_cores", &ServerInfo::GetCpuCores)
	.def("set_cpu_cores", &ServerInfo::SetCpuCores)
	.def("get_eureqa_version", &ServerInfo::GetEureqaVersion)
	.def("set_eureqa_version", &ServerInfo::SetEureqaVersion)
	.def("get_hostname", &ServerInfo::GetHostname)
	.def("set_hostname", &ServerInfo::SetHostname)
	.def("get_operating_system", &ServerInfo::GetOperatingSystem)
	.def("set_operating_system", &ServerInfo::SetOperatingSystem)
	.add_property("cpu_cores", &ServerInfo::GetCpuCores, &ServerInfo::SetCpuCores)
	.add_property("eureqa_version", &ServerInfo::GetEureqaVersion, &ServerInfo::SetEureqaVersion)
	.add_property("hostname", &ServerInfo::GetHostname, &ServerInfo::SetHostname)
	.add_property("operating_system", &ServerInfo::GetOperatingSystem, &ServerInfo::SetOperatingSystem)
	;

	// SearchProgress
	boost::python::class_<SearchProgress>("SearchProgress")
	.def("is_valid", &SearchProgress::IsValid)
	.def("summary", &SearchProgress::Summary)
	.def("get_evaluations", &SearchProgress::GetEvaluations)
	.def("set_evaluations", &SearchProgress::SetEvaluations)
	.def("get_evaluations_per_sec", &SearchProgress::GetEvaluationsPerSec)
	.def("set_evaluations_per_sec", &SearchProgress::SetEvaluationsPerSec)
	.def("get_generations", &SearchProgress::GetGenerations)
	.def("set_generations", &SearchProgress::SetGenerations)
	.def("get_generations_per_sec", &SearchProgress::GetGenerationsPerSec)
	.def("set_generations_per_sec", &SearchProgress::SetGenerationsPerSec)
	.def("get_solution", &SearchProgress::GetSolution)
	.def("set_solution", &SearchProgress::SetSolution)
	.def("get_total_population_size", &SearchProgress::GetTotalPopulationSize)
	.def("set_total_population_size", &SearchProgress::SetTotalPopulationSize)
	.add_property("evaluations", &SearchProgress::GetEvaluations, &SearchProgress::SetEvaluations)
	.add_property("evaluations_per_sec", &SearchProgress::GetEvaluationsPerSec, &SearchProgress::SetEvaluationsPerSec)
	.add_property("generations", &SearchProgress::GetGenerations, &SearchProgress::SetGenerations)
	.add_property("generations_per_sec", &SearchProgress::GetGenerationsPerSec, &SearchProgress::SetGenerationsPerSec)
	.add_property("solution", &SearchProgress::GetSolution, &SearchProgress::SetSolution)
	.add_property("total_population_size", &SearchProgress::GetTotalPopulationSize, &SearchProgress::SetTotalPopulationSize)
	;

	// DataSet -- function pointers which enable overloading
    bool (DataSet::*ImportAscii_1)(std::string) = &DataSet::ImportAscii;
    bool (DataSet::*ImportAscii_2)(std::string, std::string&) = &DataSet::ImportAscii;

	// DataSet
	boost::python::class_<DataSet>("DataSet")
	.def(boost::python::init<std::string>())
	.def(boost::python::init<int, int>())
	.def("is_valid", &DataSet::IsValid)
	.def("set_default_symbols", &DataSet::SetDefaultSymbols)
	.def("size", &DataSet::Size)
	.def("num_vars", &DataSet::NumVars)
	.def("special_vars", &DataSet::SpecialVars)
	.def("clear", &DataSet::Clear)
	.def("swap", &DataSet::Swap)
	.def("resize", &DataSet::Resize)
	.def("empty", &DataSet::Empty)
	.def("import_ascii", ImportAscii_1)
	.def("import_ascii", ImportAscii_2)
	.def("export_ascii", &DataSet::ExportAscii)
	.def("summary", &DataSet::Summary)
	.def("get_r", &DataSet::GetR)
	.def("set_r", &DataSet::SetR)
	.def("get_t", &DataSet::GetT)
	.def("set_t", &DataSet::SetT)
	.def("get_w", &DataSet::GetW)
	.def("set_w", &DataSet::SetW)
	.def("get_x_symbols", &DataSet::GetXSymbols)
	.def("set_x_symbols", &DataSet::SetXSymbols)
	.def("get_y_symbols", &DataSet::GetYSymbols)
	.def("set_y_symbols", &DataSet::SetYSymbols)
	.add_property("r", &DataSet::GetR, &DataSet::SetR)
	.add_property("t", &DataSet::GetT, &DataSet::SetT)
	.add_property("w", &DataSet::GetW, &DataSet::SetW)
	.add_property("x_symbols", &DataSet::GetXSymbols, &DataSet::SetXSymbols)
	.add_property("y_symbols", &DataSet::GetYSymbols, &DataSet::SetYSymbols)
	;

	// CommandResult
	boost::python::class_<CommandResult>("CommandResult")
	.def(boost::python::init<int, std::string>())
	.def("get_value", &CommandResult::GetValue)
	.def("set_value", &CommandResult::SetValue)
	.def("get_message", &CommandResult::GetMessage)
	.def("set_message", &CommandResult::SetMessage)
	.add_property("value", &CommandResult::GetValue, &CommandResult::SetValue)
	.add_property("message", &CommandResult::GetMessage, &CommandResult::SetMessage)
	;

	// Connection -- function pointers which enable overloading
	bool (Connection::*SendIndividuals_1)(std::string) = &Connection::SendIndividuals;
	bool (Connection::*SendIndividuals_2)(SolutionInfo) = &Connection::SendIndividuals;
	bool (Connection::*SendIndividuals_3)(std::vector<SolutionInfo>) = &Connection::SendIndividuals;

	boost::tuple<bool, SolutionInfo> (Connection::*QueryIndividuals_1)() = &Connection::QueryIndividuals;
	boost::tuple<bool, std::vector<SolutionInfo> > (Connection::*QueryIndividuals_2)(unsigned int count) = &Connection::QueryIndividuals;

	boost::tuple<bool, SolutionInfo> (Connection::*CalcSolutionInfo_1)(SolutionInfo) = &Connection::CalcSolutionInfo;
	boost::tuple<bool, std::vector<SolutionInfo> > (Connection::*CalcSolutionInfo_2)(std::vector<SolutionInfo>) = &Connection::CalcSolutionInfo;

	bool (Connection::*Connect_1)(std::string) = &Connection::Connect;
	bool (Connection::*Connect_2)(std::string, unsigned int) = &Connection::Connect;
	bool (Connection::*Connect_3)(unsigned int) = &Connection::Connect;

	// Connection
	boost::python::class_<Connection>("Connection")
	.def(boost::python::init<std::string>())
	.def(boost::python::init<std::string, int>())
	.def("is_connected", &Connection::IsConnected)
	.def("last_result", &Connection::LastResult)
	.def("connect", Connect_1)
	.def("connect", Connect_2)
	.def("connect", Connect_3)
	.def("disconnect", &Connection::Disconnect)
	.def("send_data", &Connection::SendData)
	.def("send_data_location", &Connection::SendDataLocation)
	.def("send_options", &Connection::SendOptions)
	.def("send_individuals", SendIndividuals_1)
	.def("send_individuals", SendIndividuals_2)
	.def("send_individuals", SendIndividuals_3)
	.def("send_population", &Connection::SendPopulation)
	.def("query_progress", &Connection::QueryProgress)
	.def("query_server_info", &Connection::QueryServerInfo)
	.def("query_individuals", QueryIndividuals_1)
	.def("query_individuals", QueryIndividuals_2)
	.def("query_population", &Connection::QueryPopulation)
	.def("query_frontier", &Connection::QueryFrontier)
	.def("start_search", &Connection::StartSearch)
	.def("pause_search", &Connection::PauseSearch)
	.def("end_search", &Connection::EndSearch)
	.def("calc_solution_info", CalcSolutionInfo_1)
	.def("calc_solution_info", CalcSolutionInfo_2)
	.def("summary", &Connection::Summary)
	.def("remote_address", &Connection::RemoteAddress)
	.def("remote_port", &Connection::RemotePort)
	;

	// EureqaServerController
	boost::python::class_<EureqaServerController>("EureqaServerController")
	.def("start_server", EureqaServerController::StartServer)
	.staticmethod("start_server")
	.def("stop_server", EureqaServerController::StopServer)
	.staticmethod("stop_server")
	;
}



