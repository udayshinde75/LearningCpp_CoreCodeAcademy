#include <cstdio> 

namespace X 
{
    int num = 100; 

    void test_function()
    {
        puts("Entered X::test_function()"); 
        puts("Leaving X::test_function()"); 
    }

    class MyType 
    {
        public: 
            MyType() 
            {
                puts("Entered X::MyType::MyType()"); 
                puts("Entered X::MyType::MyType()"); 
            }
    }; 
}

void test_namespace(); 

int main()
{
    test_namespace(); 
    return 0; 
}

void test_namespace()
{
    X::num = 500; 

    printf("X::num = %d\n", X::num); 

    X::test_function(); 

    X::MyType mt1, mt2; 

    X::MyType* p = new X::MyType; 
    delete p; 
    p = 0; 
}