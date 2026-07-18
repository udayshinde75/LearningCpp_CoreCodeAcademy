#include <iostream>

template<typename T> // template parameter list
T max(T a, T b) // Function template for function. Class template for class
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    int ret_int = ::max<int>(10, 20);
    std::cout << "ret_int : " << ret_int << std::endl;
    std::string ret_str = ::max<std::string>(std::string("aaa"), std::string("zzz"));
    std::cout << "ret_str : " << ret_str << std::endl;
}