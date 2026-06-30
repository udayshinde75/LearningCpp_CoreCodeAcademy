// Advaced operator overloading
#include <stdio.h>
#include <cstdio>

class CPA_int
{
private:
    int n; 
public:
    CPA_int(int _n = 0) : n(_n) {}
    ~CPA_int() = default;

    CPA_int operator++()
    {
        n = n + 1;
        return *this;
    }

    CPA_int operator++(int)
    {
        CPA_int temp(this->n);
        this->n = this->n + 1;
        return temp;
    }

    CPA_int operator--()
    {
        n = n - 1;
        return *this;
    }

    CPA_int operator--(int)
    {
        CPA_int temp(this->n);
        this->n = this->n - 1;
        return temp;
    }

    void show(const char* msg = 0) const
    {
        if (msg)
        {
            puts(msg);
        }
        printf("%d", n);
    }
};

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    CPA_int n(10);
    CPA_int result;

    n.show("Before result = ++n1: \nn : ");
    result.show("before result = ++n1: \n result:");
    result = ++n;
    n.show("After results = ++n: \nn : ");
    result.show("After results = ++n1: \n result:");
}