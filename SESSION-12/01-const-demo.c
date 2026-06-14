#include <stdio.h>

void pointer_to_const_demo(void);
void const_pointer_demo(void);
void const_pointer_to_pointer_to_const_demo(void);

const int gc_num = 500;
int main(void)
{
    pointer_to_const_demo();
    const_pointer_demo();
    const_pointer_to_pointer_to_const_demo();
    return 0;
}

void pointer_to_const_demo(void)
{
    // Majorly used

    int n1 = 100;
    int n2 = 200;
    const int n3 = 300;
    // pointer to const pointee
    const int* ptr;
    int val;

    ptr = &n1;
    val = *ptr;
    printf("val = %d\n", val);
    //*ptr = 1000; //CTE : expression must be a modifiable lvalue

    ptr = &n2;
    val = *ptr;
    printf("val = %d\n", val);
    //*ptr = 1000; //CTE : expression must be a modifiable lvalue

    ptr = &n3;
    val = *ptr;
    printf("val = %d\n", val);
    //*ptr = 1000; //CTE : expression must be a modifiable lvalue

    ptr = &gc_num;
    val = *ptr;
    printf("val = %d\n", val);
    //*ptr = 1000; //CTE : expression must be a modifiable lvalue

}
void const_pointer_demo(void)
{
    int n1;
    int n2;
    // ptr will keep pointing to n1;
    int* const ptr = &n1;

    *ptr = 100; // Possible;
    //ptr = &n2; // CTE : expression must be a modifiable lvalue

    const int local = 500;
    int* const ptr1 = &local; // In C++, need type casting
    // Same semantics as int* ptr;
    // Any attempt to load address of constant variable
    // In pointer to non-const type(meaning pointer which allows modification in pointers)
    // will trigger warning in C, error in C++ can be eliminated by explicit type casting
    *ptr = 500; // Possible
}
void const_pointer_to_pointer_to_const_demo(void)
{
    int n1;
    int n2;
    const int* const ptr = &n1;

    //ptr = &n2; // CTE : ptr is a const pointer -> therfore it cannot change address stored in it
                 // at the time of initialization
    //*ptr = 500;// CTE : ptr is pointer to const as well -> therfore moification of pointee
                 // is not possible
}

/*
Type system analysis

int* ptr;
unsigned long long

int* ptr is an unsigned long long type

type(ptr) = int*;
type(*ptr) = int;

const int* ptr;
type(ptr) = const int*
type(*ptr) = const int;
*/

// haskell route to magic maths and programming
// Discreate mathemathics using computer


/*
int a[5];
int (*pa)[5] = &a;

a = &n1; // not possible.  a is const pointer 

for(int i = 0; i < 5; ++i)
    (*pa)[i] = (i+1) * 100;

int* ptr = a; // wrong ptr is pointer to int not to an array
*/