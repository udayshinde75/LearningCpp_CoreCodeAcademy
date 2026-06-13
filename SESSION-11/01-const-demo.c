#include <stdio.h>

const int num2 = 100; 
// Initializer is compulsory
// Cannot be modofied using variable name
// num2 = 200; // Not possible. error : left side statement should be modifiable lvalue

void test();

int main(void)
{
    test();
    return 0;
}

void test()
{
    const int local_const = 200;

    // CTE : expression must be a modifiable lvalue
    // local_const = 1000;
    // num2 = 2000;
}