#include <cstdio>
#include <cmath>

class Dada_int
{
    private:
        int n;

    public:
        // Constructor
        Dada_int(int _n = 0) : n(_n) {}

        // Arithmetic operators
        Dada_int operator+(const Dada_int& other) const
        {
            return Dada_int(n + other.n);
        }
        Dada_int operator-(const Dada_int& other) const
        {
            return Dada_int(n - other.n);
        }
        Dada_int operator*(const Dada_int& other) const
        {
            return Dada_int(n * other.n);
        }
        Dada_int operator/(const Dada_int& other) const
        {
            if (n == 0 && other.n == 0)
            {
                return Dada_int(NAN);
            }
            if (n != 0 && other.n == 0)
            {
                return Dada_int(INFINITY);
            }
            return Dada_int(n / other.n);
        }
        Dada_int operator%(const Dada_int& other) const
        {
            if (n == 0 && other.n == 0)
            {
                return Dada_int(NAN);
            }
            if (n != 0 && other.n == 0)
            {
                return(INFINITY);
            }
            return Dada_int(n % other.n);
        }

        //Comparison operators
        bool operator>(const Dada_int& other) const
        {
            return (n > other.n);
        }
        bool operator>=(const Dada_int& other) const
        {
            return (n >= other.n);
        }
        bool operator<(const Dada_int& other) const
        {
            return (n < other.n);
        }
        bool operator<=(const Dada_int& other) const
        {
            return (n <= other.n);
        }
        bool operator==(const Dada_int& other) const
        {
            return (n == other.n);
        }
        bool operator!=(const Dada_int& other) const
        {
            return (n != other.n);
        }

        //Logic operators
        bool operator&&(const Dada_int& other) const
        {
            return (n && other.n);
        }
        bool operator||(const Dada_int& other) const
        {
            return (n || other.n);
        }
        bool operator!()
        {
            return !n;
        }

        //Bitwise operators
        Dada_int operator&(const Dada_int& other) const
        {
            return Dada_int(n & other.n);
        }
        Dada_int operator|(const Dada_int& other) const
        {
            return Dada_int(n & other.n);
        }
        Dada_int operator^(const Dada_int& other) const
        {
            return Dada_int(n ^ other.n);
        }
        Dada_int operator~() const
        {
            return Dada_int(~n);
        }

        //Shift operators
        Dada_int operator<<(const Dada_int& other) const
        {
            return Dada_int(n << other.n);
        }
        Dada_int operator>>(const Dada_int& other) const
        {
            return Dada_int(n >> other.n);
        }

        Dada_int operator++()
        {
            n = n + 1;
            return *this;
        }

        Dada_int operator++(int)
        {
            Dada_int temp(this->n);
            this->n = this->n + 1;
            return temp;
        }

        Dada_int operator--()
        {
            n = n - 1;
            return *this;
        }

        Dada_int operator--(int)
        {
            Dada_int temp(this->n);
            this->n = this->n - 1;
            return temp;
        }
};