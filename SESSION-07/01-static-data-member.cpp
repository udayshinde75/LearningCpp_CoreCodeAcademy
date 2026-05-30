#include <cstdio>

/*
    Generic syntax

    class Test
    {
        pribate:
            static T var;
    }

    T Test::var [ = optional initializer];
*/
class Test
{
    private:
        int num1; // per object members
        int num2; // per object members

        // instatiated only once.
        // num3 is class level member. only one copy of this exist.
        static int num3; // Qualifier e.g. const, inline

};

// Static variables to not contribute to the size of object
// C++ 98 makes it compulsory to define static variables outside the class. Why?
int Test::num3 = 0; // Need mutex lock in multi threded environment

int main()
{
    printf("sizeof(test) : %zu\n", sizeof(Test));

    return 0;
}