#include <stdio.h>

const int global_const_num = 100;

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    // this is treated as symbolic constant if initializer is typed statistically
    const int local_const_var = 200;

    int* g_ptr = NULL;
    int* l_ptr = NULL;

    // C++ needs explicit type casting
    l_ptr = (int*)&local_const_var;
    // Warning : assigning to 'int *' from 'const int *' discards qualifiers 
    printf("Before local_const_var = %d\n", local_const_var);
    *l_ptr = 2000;
    printf("After local_const_var = %d\n", local_const_var);
}

/*
Before local_const_var = 200
After local_const_var = 200
*/
