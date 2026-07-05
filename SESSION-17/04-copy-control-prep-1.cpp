#include <iostream> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {
            std::cout << "----Date::Date() Entered" << std::endl; 
            std::cout << "----Date::Date() Leaving" << std::endl; 
        }

        Date() : day(1), month(1), year(1970)
        {
        }

        //  Copy Constructor
        Date(const Date& other) : day(other.day), month(other.month), year(other.year)
        {

        }

        Date& operator=(const Date& other)
        {
            if(this != &other)
            {
                this->day = other.day; 
                this->month = other.month; 
                this->year = other.year; 
            }
            return *this; 
        }

        int getDay() const 
        {
            return day; 
        }

        void setDay(int new_day)
        {
            this->day = new_day; 
        }

        void show(const char* msg = 0) const  
        {
            if(msg)
                std::cout << msg << std::endl;
            std::cout << day << "/" << month << "/" << year << std::endl; 
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
    Date D1(4, 7, 2026); 

    Date D2(D1);    // Date D2 = D1; 

    Date D3(5, 9, 2028); 

    D2 = D3; 

}

/* 
    Date D2 = D1;   //  Data definition statement 


    D2 = D1;        //  Assignment Statement 


    class T
    {
        public: 
            //  Copy Constructor
            T(const T& other) : memberwise initialization 
            {
                //  assignments for memberwise copying 
            }
    }

    int i, j, k; 

    i = j = k = 0; 

    D3 = D2 = D1; 
*/