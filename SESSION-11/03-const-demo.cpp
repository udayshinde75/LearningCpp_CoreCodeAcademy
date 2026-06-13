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

    // a value of type "const int *" cannot be assigned to an entity of type "int *"
    l_ptr = &local_const_var;
    printf("Before *l_ptr = %d\n", *l_ptr);
    *l_ptr = 2000;
    printf("After *l_ptr = %d\n", *l_ptr);
}

// C++ : strongly typed programming language
// C : weakly typed programming language
