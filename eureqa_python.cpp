#include <boost/python.hpp>
#include <string>

class DummyClass
{
	public:
		std::string Test(std::string text)
		{
		    return "Hello " + text;
		}
};

// class Connection
// {
//	private:
//		boost::scoped_ptr<connection> data;
//	public:
//		Connection() : data(new connection()) {}
//		Connection(std::string hostname, int port = default_port_tcp) : data(new connection(hostname, port)) {}
//
// };


BOOST_PYTHON_MODULE(eureqa_python)
{
	boost::python::class_<DummyClass>("DummyClass")
	.def("test", &DummyClass::Test)
	;
}


