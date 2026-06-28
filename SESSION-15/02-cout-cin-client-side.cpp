// Function to print on output devices in C++ : ostream::operator<< not cout
#include <iostream> // ostream, istream, cout, cin
#include <cstdio> // EXIT_SUCCESS
 
void test();

int main()
{
    test();
    return EXIT_SUCCESS;
}

void test()
{
    const char* msg = "hello";
    int num = 100;
    double d_num = 3.14;

    // << name:cout operator
    std::cout << "\n";
    std::cout << msg << '\t' << num << '\t' << d_num << std::endl;
}

//ostream
//ofstream
//ostringstream
//istream
//ifstream
//istringstream
//iostream
//fstream
//stringstream