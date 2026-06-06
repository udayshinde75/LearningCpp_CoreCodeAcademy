#include <cstdio>

void test();

int main(void)
{
    test();
    return 0;
}

void test()
{
    // direct access
    int num = 100;  // M [x : x + 3] &num = x;
                    //num is name bound with addr x;

    num = 500;


    // Indirect access
    int* p = &num;

    *p = 50000;

    printf("*p = %d\n", *p);

    // Reference variable
    // initialization is mandatory
    int& ref = num; //ref is a refernce of type int. attach a another name to existing memory block
    printf("ref = %d\n", ref);

    ref = 10000;

    printf("num = %d\n", num);

    // uses
    /*
    - 
    */



}