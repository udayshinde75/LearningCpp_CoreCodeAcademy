#include <cstdio>
#include <iostream>

class Date
{
private:
    int day, month, year;
    mutable int getter_count;
public:
    Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy), getter_count(0)
    {}
    ~Date() = default;

    int getDay() const
    {
        //((Date*)this)->getter_count++; same as ++getter_count;
        /*
        Mutable typecasts the const const date* this, to date* this internally
        for that member variable for only
        */
        ++getter_count;
        return day;
    }

    int getMonth() const
    {
        //((Date*)this)->getter_count++; same as ++getter_count;
        /*
        Mutable typecasts the const const date* this, to date* this internally
        for that member variable for only
        */
        ++getter_count;
        return month;
    }

    int getYear() const
    {
        //((Date*)this)->getter_count++; same as ++getter_count;
        /*
        Mutable typecasts the const const date* this, to date* this internally
        for that member variable for only
        */
        ++getter_count;
        return year;
    }

    int getterCount() const
    {
        return getter_count;
    }
};


void test();

// Now myDate goes to BSS or data
// Consequence of mutable keyword that, because of ony 1 member,
// an object which should have been in hardware protected memory gets
// stored in read/write section

// When there is a mutable in a class, all of the objects created by that class, 
// mutable prevents them to go in RO section

// If one of class member is mutable then we can modify any member of class by type cast this pointer
// of const class member function
const Date myDate(20, 6, 2026);

int main()
{
    test();
    return 0;
}

void test()
{
    int dd = myDate.getDay();
    int mm = myDate.getMonth();
    int yy = myDate.getYear();

    std::cout<<myDate.getterCount() << std::endl;
}