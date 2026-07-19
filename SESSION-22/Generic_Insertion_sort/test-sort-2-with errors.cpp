#include <iostream> 
#include "sort.hpp"

class Date 
{
    private: 
        int day, month, year; 
        
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }

        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }

        void setDay(int val) { day = val; }
        void setMonth(int val) { month = val; }
        void setYear(int val) { year = val; }

        void show(const char* msg = 0) 
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
    Date a_date[] = 
    {
        Date(19, 7, 2026), 
        Date(17, 12, 2026), 
        Date(2, 6, 2023), 
        Date(1, 1, 1970), 
        Date(2, 4, 2024) 
    }; 

    show_array<Date>(a_date, (ssize_t)(sizeof(a_date)/sizeof(a_date[0])), "Before sort:"); 
    insertion_sort<Date>(a_date, (ssize_t)(sizeof(a_date)/sizeof(a_date[0]))); 
    //show_array<Date>(a_date, (ssize_t)(sizeof(a_date)/sizeof(a_date[0])), "Aftersort:"); 
}