#include <iostream> 

class Date 
{
    friend std::ostream& operator<<(std::ostream& os, const Date& dateObject); 
    friend std::istream& operator>>(std::istream& is, Date& dateObject);  
    private: 
        int dd, mm, yy; 

    public: 
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy)
        {
        }

        Date() : dd(1), mm(1), yy(1970)
        {
        }  
}; 

std::ostream& operator<<(std::ostream& os, const Date& dateObject)
{
    os << dateObject.dd << "/" << dateObject.mm << "/" << dateObject.yy 
        << std::endl; 
    return os; 
}

std::istream& operator>>(std::istream& is, Date& dateObject)
{
    std::cout << "Enter day:"; 
    is >> dateObject.dd; 
    std::cout << "Enter month:"; 
    is >> dateObject.mm; 
    std::cout << "Enter year:"; 
    is >> dateObject.yy;

    return is; 
}

void test(); 

int main() 
{
    test(); 
    return 0; 
}

void test() 
{
    Date myDate; 

    std::cin >> myDate; 
    std::cout << myDate; 
}



/* 
    type(N1) : CPA_int  type(N2) : CPA_int
    N1 + N2 
        CPA_int::operator+(&N1, N2); 

    N2 + N1
        CPA_int::operator+(&N2, N1); 

    Date myDate; 

    std::cout << myDate << num; 

    namespace std 
    {
        class ostream
        {

            std::ostream& operator<<(const Date& myDate)
            {

                return *this;
            }
        }
    }


*/