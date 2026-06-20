#include <cstdio>

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
};
