#include <cstdio>

class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date(int day, int month, int year)
        : day(day), month(month), year(year)
    {

    }

    void setValues(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

Date myDate(24, 5, 2023);

int main(void)
{
    myDate.setValues(25, 6, 2024); // Date::setValues(&myDate, 25, 6, 2024)
    return 0;
}