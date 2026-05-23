#include <stdio.h>

void test(int a, int b, int c = 100);
// Non-default parameter after default parameter is not allowed
int main(void)
{
    test(100, 200);
    test(100, 200, 49999);

    return 0; 
}

void test(int a, int b, int c)
{
    printf("a = %d, b = %d, c = %d\n", a, b, c);
}












// Research
// Reference variable