#include <stdexcept> 
#include "list_exceptions.hpp" 

invalid_data::invalid_data(const char* msg) : std::runtime_error(msg)
{

}

list_empty::list_empty(const char* msg) : std::runtime_error(msg)
{
    
}

