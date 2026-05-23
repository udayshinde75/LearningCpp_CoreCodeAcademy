#include <cstdio>
#include <cstring>

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int _day, int _month, int _year)
    {
        this->day = _day;
        this->month = _month;
        this->year = _year;
    }

    Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }

    Date(char* datestr)
    {
        char* sep = "/";
        char* daytoken = strtok(datestr, sep);
        char* monthtoken = strtok(NULL, sep);
        char* yeartoken = strtok(NULL, sep);

        this->day = 
    }


};



