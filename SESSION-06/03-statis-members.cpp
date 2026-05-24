#include <cstdio>

class Test
{
    private:
    int y; // non static data member 
    static int num; // static data member
    static int num2; // static data member

    public:
    void non_static_member()
    {
        num = 200;
        y = 500;
    }

    static void static_member_function()
    {
        num = 200;
        //y = 500; //CTE : non static members cannot be accessed through static member functions.

    }
};

int Test::num = 100;
int Test::num2 = 300;

int main()
{
    return 0;
}

