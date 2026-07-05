#include <iostream> 
#include <stdexcept> 
#include <typeinfo> 

class ArithmeticOperator 
{
    private: 
        int (*pfn)(int, int);   // data member 
                                //  ptr to a function accepting two integers and returning 
                                //  an integer 
    public: 

        ArithmeticOperator( int (*_pfn)(int, int)) : pfn(_pfn)
        {
        }

        int operator()(int a, int b) 
        {
            if(!pfn)
                throw std::runtime_error("invalid function addr"); 
            return pfn(a, b); 
        }
}; 

void test(); 

int my_add(int, int); 
int my_sub(int, int); 
int my_mul(int, int); 

int main() 
{
    test(); 
    return 0; 
}

void test() 
{
    ArithmeticOperator add(my_add), sub(my_sub), mul(my_mul); 

    int p = 100, q = 21; 

    int result; 

    result = add(p, q); 
    std::cout << "add(p, q):" << result << std::endl; 
    result = sub(p, q); 
    std::cout << "sub(p, q):" << result << std::endl; 
    result = mul(p, q); 
    std::cout << "mul(p, q):" << result << std::endl; 

    std::cout << "type(add):" << typeid(add).name() << std::endl; 
    std::cout << "type(sub):" << typeid(sub).name() << std::endl; 
    std::cout << "type(mul):" << typeid(mul).name() << std::endl; 
}


int my_add(int x, int y)
{
    return x + y; 
}

int my_sub(int x, int y)
{
    return x - y; 
}

int my_mul(int x, int y) 
{
    return x * y;
}