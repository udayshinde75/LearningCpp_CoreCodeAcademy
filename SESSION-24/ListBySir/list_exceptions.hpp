#include <iostream> 
#include <stdexcept> 

class invalid_data : public std::runtime_error
{
    public: 
        invalid_data(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 