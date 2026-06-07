#include <stdio.h>

// if made static it wont be accessible in src1.c
int num =100;

void test_function(void)
{
    printf("src2.c: num = %d\n", num);
}