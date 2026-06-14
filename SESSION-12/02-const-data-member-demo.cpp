#include <stdio.h>

class Test
{
private:
    const int num;
    static const int num1;
public:
    Test(int _num) : num(_num)
    {
        //num = _num; // CTE : expression must be a modifiable lvalue
    }
    ~Test();
};

// C++ 98
const int Test::num1 = 100;

// C++ 11 onwards
class Test
{
private:
    const int num;
    static const int num1 = 100;
public:
    Test(int _num) : num(_num)
    {
        //num = _num; // CTE : expression must be a modifiable lvalue
    }
    ~Test();
};
