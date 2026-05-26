#include <ctime>
#include <stdexcept>
#include <string>
#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date();
        Date(int _day, int _month, int _year);
        Date(const Date& other);

        int isleapYear(int year);
        int daysInMonth(int month, int year);

        std::string displayDate();
};

Date::Date()
{
    std::time_t now = std::time(nullptr);
    std::tm* localtime = std::localtime(&now);

    day = localtime->tm_mday;
    month = localtime->tm_mon;
    year = localtime->tm_year;
}

Date::Date(int _day, int _month, int _year)
{
    if (_year < 1)
    {
        throw std::invalid_argument("Invalid Year");
    }

    if (_month < 1 || _month > 12)
    {
        throw std::invalid_argument("Invalid Month");
    }
    
    if (_day < 1 || _day > daysInMonth(_month, _year))
    {
        throw std::invalid_argument("Invalid day");
    }
    
    day = _day;
    month = _month;
    year = _year;
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

std::string Date::displayDate()
{
    return 
            (day < 10 ? "0" : "") + std::to_string(day) + "/" +
            (month < 10 ? "0" : "") + std::to_string(month) + "/" +
            std::to_string(year);
}

int Date::isleapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int Date::daysInMonth(int month, int year)
{
    if (month == 2)
    {
        return isleapYear(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }

    return 31;
}


int main()
{
    Date d(31, 2, 2026);

    std::cout << d.displayDate() << std::endl;
}