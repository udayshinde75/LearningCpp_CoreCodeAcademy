//  FIRST C++ CODE -> A journey of thousand miles starts but with one step - Lao Tzu 

//  Header file inclusion for std::cout 
#include <iostream> 

//  Definition of class Date 
class Date 
{
    //  Date layout is made private. 
    private: 
        int day; 
        int month; 
        int year; 

    public: 
    //  Interface functions are made public 
    
    //  Constructor 
    Date(int init_day, int init_month, int init_year)
    {
        //  Using 'this' pointer qualification for understanding 
        this->day = init_day; 
        this->month = init_month; 
        this->year = init_year; 
    }

    //  Getters 
    int getDay() const 
    {
        return this->day; 
    }

    int getMonth() const 
    {
        return this->month; 
    }

    int getYear() const 
    {
        return this->year; 
    }

    //  Setters 
    void setDay(int new_day)
    {
        this->day = new_day; 
    }

    void set_month(int new_month)
    {
        this->month = new_month; 
    }

    void set_year(int new_year) 
    {
        this->year = new_year; 
    }

    //  Display function
    void show() const 
    {
        std::cout << day << "/" << month << "/" << year << std::endl; 
    }

    //  Not required for this class, but writing for conceptual understanding 
    //  Destructor 
    ~Date() 
    {
        //  Empty definition 
    }
}; 

void testDate(); 

int main() 
{
    testDate(); 
    return 0; 
}

void testDate() 
{
    Date* pDate = new Date(10, 5, 2026); 

    int dd = pDate->getDay(); 
    int mm = pDate->getMonth(); 
    int yy = pDate->getYear(); 

    std::cout << dd << "/" << mm << "/" << yy << std::endl; 

    pDate->setDay(30); 
    pDate->set_month(6); 
    pDate->set_year(2027); 

    pDate->show(); 

    delete pDate; 
    pDate = 0; 
}


