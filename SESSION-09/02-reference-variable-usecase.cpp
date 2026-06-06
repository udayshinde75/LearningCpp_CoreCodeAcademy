#include <cstdio> 

void swap_1(int* p1, int *p2); 
void swap_2(int& ref1, int& ref2); 
void test_swap_1(); 
void test_swap_2(); 

int main()
{
    test_swap_1(); 
    test_swap_2(); 

    return 0; 
}

void test_swap_1()
{
    int a = 10, b = 20; 
    printf("BEFORE:a = %d, b = %d\n", a, b); 
    swap_1(&a, &b); 
    printf("AFTER:a = %d, b = %d\n", a, b); 
}

void test_swap_2()
{
    int a = 10, b = 20; 
    printf("BEFORE:a = %d, b = %d\n", a, b); 
    swap_2(a, b); 
    printf("AFTER:a = %d, b = %d\n", a, b); 
}

void swap_1(int* p1, int* p2)
{
    int tmp = *p1; 
    *p1 = *p2; 
    *p2 = tmp; 
}

void swap_2(int& ref1, int& ref2)
{
    int tmp = ref1; 
    ref1 = ref2; 
    ref2 = tmp; 
}
