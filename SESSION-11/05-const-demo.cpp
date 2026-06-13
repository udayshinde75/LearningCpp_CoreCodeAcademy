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

    l_ptr = (int*)&local_const_var;
    // Warning : assigning to 'int *' from 'const int *' discards qualifiers 
    printf("Before local_const_var = %d\n", *l_ptr);
    *l_ptr = 2000;
    printf("After local_const_var = %d\n", *l_ptr);
}

/*
Before local_const_var = 200
After local_const_var = 2000
*/