#include <stdio.h>

extern void test_function(void);
extern int num;

void modify_num(int new);

int main(void)
{
    test_function();
    modify_num(5000);
    test_function();
    return 0;
}

void modify_num(int new)
{
    num = new;
}