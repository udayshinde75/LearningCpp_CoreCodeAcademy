#include <cstdio>
#include <iostream>

class Complex
{
private:
    double re, im;
public:
    Complex() : re(0.0), im(0.0) {}
    Complex(double _re, double _im) : re(_re), im(_im) {}
    ~Complex() = default;

    Complex add(const Complex& other) const
    {
        return Complex(this->re + other.re, this->im + other.im);
    }

    Complex sub(const Complex& other) const
    {
        return Complex(re-other.re, im - other.im);
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(this->re + other.re, this->im + other.im);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(re-other.re, im - other.im);
    }

    double getRealPart() const {return re;}
    double getImPart() const {return im;}
};

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    Complex c1(1.1, 8.4);
    Complex c2(2.4, 5.3);

    //Complex sum = c1.add(c2); // Complex::add(&c1, c2)
    Complex sum = c1 + c2;
    std::cout << "Sum : " << sum.getRealPart() << "+" << sum.getImPart() << std::endl;
}