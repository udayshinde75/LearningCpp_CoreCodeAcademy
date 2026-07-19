#include <iostream> 
#include "sort.hpp"

class Date 
{
    private: 
        int day, month, year; 
        
    public: 
        Date() : day(0), month(0), year(0)
        {

        }

        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }

        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }

        void setDay(int val) { day = val; }
        void setMonth(int val) { month = val; }
        void setYear(int val) { year = val; }

        bool operator>(const Date& other)
        {
            if(this->year > other.year)
                return true; 
            else if(this->year < other.year)
                return false; 
            
            if(this->month > other.month)
                return true; 
            else if(this->month < other.month)
                return false; 

            if(this->day > other.day)
                return true; 
            else 
                return false; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& dateObject); 
}; 

std::ostream& operator<<(std::ostream& os, const Date& dateObject)
{
    os << dateObject.day << "/" << dateObject.month << "/" << dateObject.year << std::endl;  
    return os; 
}

void test(); 

int main() 
{
    test(); 
    return 0; 
}

void test() 
{
    Date a_date[] = 
    {
        Date(19, 7, 2026), 
        Date(17, 12, 2026), 
        Date(2, 6, 2023), 
        Date(1, 1, 1970), 
        Date(2, 4, 2024) 
    }; 

    show_array(a_date, (s_size_t)(sizeof(a_date)/sizeof(a_date[0])), "Before sort:"); 
    insertion_sort(a_date, (s_size_t)(sizeof(a_date)/sizeof(a_date[0]))); 
    show_array(a_date, (s_size_t)(sizeof(a_date)/sizeof(a_date[0])), "Aftersort:"); 
}