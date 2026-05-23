#include <stdio.h>

void test();
void test(int);
void test(int, float);

class X
{
    public:
        void member_funct()
        {
            puts("in X::member_funct()");
        }

        void member_funct(int x, int y)
        {
            puts("in X::member_funct(int x, int y)");
        }
};


void function_overloadingdemo1();
void function_overloadingdemo2();

int main(void)
{
    function_overloadingdemo1();
    function_overloadingdemo2();

    return 0;
}

void function_overloadingdemo1()
{
    test();
    test(10);
    test(10, 1.0f);
}

void function_overloadingdemo2()
{
    X objx;
    objx.member_funct();
    objx.member_funct(10, 20);
}

void test()
{
    puts("in gloabal scope in function test()");
}
void test(int)
{
    puts("in gloabal scope in function test(int)");
}
void test(int, float)
{
    puts("in gloabal scope in function test(int, float)");
}
