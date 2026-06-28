#include <iostream>

class Date
{
    private:
        int  dd, mm, yy;

    public:
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy)
        {

        }
    
        Date() : dd(1), mm(1), yy(1970)
        {

        }

    friend void test_2();
};

void test_1();
void test_2();

int main()
{
    test_1();
    test_2();
}

void test_1()
{
    Date myDate;

    Date* pDate = new Date();

    myDate.mm = 10; // Error
    myDate.dd = 20; // Error

    delete pDate;
}

void test_2()
{
    Date myDate;

    Date* pDate = new Date();

    myDate.mm = 10;
    myDate.dd = 20; 

    delete pDate;
}