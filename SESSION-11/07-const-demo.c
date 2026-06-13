#include <stdio.h>

const int g_num = 100;

void test();

int main()
 {

    test();
    return 0;
 }
void test()
{
    int* ptr = &g_num;
    // In C++ this must be achieved by explicit type casting 
    // int* ptr = (int*) &g_num;

    printf("BEFORE : *ptr = %d\n", *ptr);
    *ptr = 1000;
    // WINDOWS :MEMORY VIOLATION EXCEPTION
    // LINUX / MACOS : seg fault / bus error
    // Program will ABNORMALLY TERMINATE at this point
    // Globals const are stored on RO Data section(static+const local variable also follow same behaviour)
    printf("After : *ptr = %d\n", *ptr);
}