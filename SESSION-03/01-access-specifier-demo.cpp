//
//  01-access-dpecifier-demo.cpp
//
//
//  Created by Uday Shinde on 16/05/26.
//

// In C++ -> standard header files do not have extensions
#include <cstdio>

struct CDate
{
    int day;
    int month;
    int year;
};

class CPPDate
{
private:
    int day;
    int month;
    int year;
    
public:
    
};

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    struct CDate D1;
    CPPDate D2;
    
    D1.day = 10;
    D2.day = 20; // Compile time Error : private variable not accessible
}

