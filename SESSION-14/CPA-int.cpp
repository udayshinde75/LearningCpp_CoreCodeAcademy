#include <cstdio> 
#include <cmath> 

class CPA_int 
{
    private: 
        int n; 

    public: 
        CPA_int(int _n = 0) : n(_n)
        {

        }

        //  Arithmetic operators 
        CPA_int operator+(const CPA_int& other) const 
        {
            return CPA_int(n + other.n); 
        }

        CPA_int operator-(const CPA_int& other) const 
        {
            return CPA_int(n - other.n); 
        }

        CPA_int operator*(const CPA_int& other) const 
        {
            return CPA_int(n * other.n); 
        }

        CPA_int operator/(const CPA_int& other) const 
        {
            if(n == 0 && other.n == 0)
                return CPA_int(NAN); 

            if(n != 0 && other.n == 0)
                return CPA_int(INFINITY); 

            return CPA_int(n / other.n); 
        }

        CPA_int operator%(const CPA_int& other) const
        {
             if(n == 0 && other.n == 0)
                return CPA_int(NAN); 

            if(n != 0 && other.n == 0)
                return CPA_int(INFINITY); 

            return CPA_int(n % other.n); 
        }

        //  Comparison operators 
        bool operator>(const CPA_int& other) const
        {
            return n > other.n; 
        }

        bool operator>=(const CPA_int& other) const 
        {
            return n >= other.n; 
        }

        bool operator<(const CPA_int& other) const 
        {
            return n < other.n; 
        }

        bool operator<=(const CPA_int& other) const 
        {
            return n <= other.n; 
        }

        bool operator==(const CPA_int& other) const 
        {
            return n == other.n; 
        }

        bool operator!=(const CPA_int& other) const 
        {
            return n != other.n; 
        }

        //  Logic operator 
        bool operator&&(const CPA_int& other) const 
        {
            return n && other.n; 
        }

        bool operator||(const CPA_int& other) const 
        {
            return n || other.n; 
        }

        bool operator!() const 
        {
            return !n; 
        }

        //  Bitwise operators 
        CPA_int operator&(const CPA_int& other) const 
        {
            return CPA_int(n & other.n); 
        }

        CPA_int operator|(const CPA_int& other) const 
        {
            return CPA_int(n | other.n); 
        }

        CPA_int operator^(const CPA_int& other) const 
        {
            return CPA_int(n ^ other.n); 
        }

        CPA_int operator~() const 
        {
            return CPA_int(~n); 
        }

        //  shift operators 
        CPA_int operator<<(const CPA_int& other) const 
        {
            return CPA_int(n << other.n); 
        }

        CPA_int operator>>(const CPA_int& other) const 
        {
            return CPA_int(n >> other.n); 
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
    CPA_int n1(10); 
    CPA_int n2(4); 
    CPA_int result; 

    //  test - addition 
    result = n1 + n2; 
    result = n1 - n2; 
    result = n1 * n2;
    result = n1 / n2;
    result = n1 % n2;

    bool b; 
    b = n1 > n2;
    b = n1 >= n2; 
    b = n1 <n2; 
    b = n1 <= n2; 
    b = n1 == n2; 
    b = n1 != n2; 
}