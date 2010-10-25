#include <boost/python.hpp>
#include <string>

std::string test(std::string text)
{
    return "Hello " + text;
}

BOOST_PYTHON_MODULE(eureqa_python)
{
    using namespace boost::python;
    def("test", test);
}


