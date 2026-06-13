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
    const int local_const_var = 200;

    int* g_ptr = NULL;
    int* l_ptr = NULL;

    l_ptr = &local_const_var;
    // Warning : assigning to 'int *' from 'const int *' discards qualifiers 
    printf("Before *l_ptr = %d\n", *l_ptr);
    *l_ptr = 2000;
    printf("After *l_ptr = %d\n", *l_ptr);
}
