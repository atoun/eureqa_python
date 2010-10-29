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

BOOST_PYTHON_MODULE(eureqa_python)
{
	boost::python::class_<DummyClass>("DummyClass")
	.def("test", &DummyClass::Test)
	;
}


