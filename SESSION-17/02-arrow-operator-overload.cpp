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

class DatePtr 
{
    private: 
        Date* pDate; 

    public: 
        DatePtr(int dd, int mm, int yy) : pDate(new Date(dd, mm, yy))
        {
            std::cout << "----DatePtr::DatePtr() Entered" << std::endl; 
            std::cout << "----DatePtr::DatePtr() Leaving" << std::endl; 
        }

        Date* operator->()
        {
            return this->pDate; 
        }

        ~DatePtr() 
        {
            std::cout << "----DatePtr::~DatePtr() Entered" << std::endl; 
            if(pDate)
            {
                std::cout << "----DatePtr::~DatePtr():Freeing pDate" << std::endl; 
                delete pDate; 
                pDate = 0; 
            }
            std::cout << "----DatePtr::~DatePtr() Leaving" << std::endl; 
        }
}; 

void testDatePtr(); 

int main() 
{
    testDatePtr(); 
    return 0; 
}

void testDatePtr() 
{
    DatePtr dptr(4, 7, 2026);

    int day = dptr->getDay();   // dptr->->getDay() | (dptr->)->getDay() | 
    std::cout << "testDatePtr():day:" << day << std::endl; 

    dptr->setDay(15); 

    dptr->show("Date after setting day to 15:"); 
}

