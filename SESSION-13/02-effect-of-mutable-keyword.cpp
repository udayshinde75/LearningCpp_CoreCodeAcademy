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

int main()
{
    test();
    return 0;
}

void test()
{
    Date myDate(20, 6, 2026);

    int dd = myDate.getDay();
    int mm = myDate.getMonth();
    int yy = myDate.getYear();

    std::cout<<myDate.getterCount() << std::endl;
}