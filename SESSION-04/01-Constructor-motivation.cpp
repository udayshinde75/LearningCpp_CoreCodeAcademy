#include "cstdio"

class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    void Initiate_Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }

    void show()
    {
        printf("%d/%d/%d\n", this->day, this->month, this->year);
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
    Date d1; // Allocated memory
    d1.Initiate_Date(); /// Date::Initiate_Date(&d1);
    d1.show(); /// Date::show(&d1);
}

