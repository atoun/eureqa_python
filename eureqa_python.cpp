#include <boost/python.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>
#include <eureqa/connection.h>


#include "Connection.h"
#include "DataSet.h"
#include "SearchOptions.h"
#include "SearchProgress.h"
#include "ServerInfo.h"
#include "SolutionFrontier.h"




BOOST_PYTHON_MODULE(eureqa_python)
{
	// ServerInfo
	boost::python::class_<ServerInfo>("ServerInfo")
	.def("is_valid", &ServerInfo::IsValid)
	.def("summary", &ServerInfo::Summary)
	.def("get_hostname", &ServerInfo::GetHostname)
	.def("set_hostname", &ServerInfo::SetHostname)
	.def("get_operating_system", &ServerInfo::GetOperatingSystem)
	.def("set_operating_system", &ServerInfo::SetOperatingSystem)
	.def("get_eureqa_version", &ServerInfo::GetEureqaVersion)
	.def("set_eureqa_version", &ServerInfo::SetEureqaVersion)
	.def("get_cpu_cores", &ServerInfo::GetCpuCores)
	.def("set_cpu_cores", &ServerInfo::SetCpuCores)
	.add_property("hostname", &ServerInfo::GetHostname, &ServerInfo::SetHostname)
	.add_property("operating_system", &ServerInfo::GetOperatingSystem, &ServerInfo::SetOperatingSystem)
	.add_property("eureqa_version", &ServerInfo::GetEureqaVersion, &ServerInfo::SetEureqaVersion)
	.add_property("cpu_cores", &ServerInfo::GetCpuCores, &ServerInfo::SetCpuCores)
	;

	// SearchProgress
	boost::python::class_<SearchProgress>("SearchProgress")
	.def("is_valid", &SearchProgress::IsValid)
	.def("summary", &SearchProgress::Summary)
	// TODO: Solution
	.def("get_generations", &SearchProgress::GetGenerations)
	.def("set_generations", &SearchProgress::SetGenerations)
	.def("get_evaluations", &SearchProgress::GetEvaluations)
	.def("set_evaluations", &SearchProgress::SetEvaluations)
	.def("get_evaluations_per_sec", &SearchProgress::GetEvaluationsPerSec)
	.def("set_evaluations_per_sec", &SearchProgress::SetEvaluationsPerSec)
	.def("get_total_population_size", &SearchProgress::GetTotalPopulationSize)
	.def("set_total_population_size", &SearchProgress::SetTotalPopulationSize)
	.def("get_generations_per_sec", &SearchProgress::GetGenerationsPerSec)
	.def("set_generations_per_sec", &SearchProgress::SetGenerationsPerSec)
	// TODO: Solution
	.add_property("generations", &SearchProgress::GetGenerations, &SearchProgress::SetGenerations)
	.add_property("evaluations", &SearchProgress::GetEvaluations, &SearchProgress::SetEvaluations)
	.add_property("evaluations_per_sec", &SearchProgress::GetEvaluationsPerSec, &SearchProgress::SetEvaluationsPerSec)
	.add_property("total_population_size", &SearchProgress::GetTotalPopulationSize, &SearchProgress::SetTotalPopulationSize)
	.add_property("generations_per_sec", &SearchProgress::GetGenerationsPerSec, &SearchProgress::SetGenerationsPerSec)
	;

}



