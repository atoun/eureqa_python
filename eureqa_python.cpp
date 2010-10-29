#include <boost/python.hpp>

#include <eureqa/eureqa.h>

#include <string>


/**
 * Python's wrapper for connection class
 **/
class _connection
{
    
};





std::string test(std::string text)
{
    return "Hello " + text;
}

BOOST_PYTHON_MODULE(eureqa_python)
{
    using namespace boost::python;
    def("test", test);
}


