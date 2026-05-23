#include "cstdio"

class Date
{
    private:
    int day;
    int month;
    int year;

    public:

    Date(int init_day, int init_month, int init_year)
    {
        this->day = init_day;
        this->month = init_month;
        this->year = init_year;
    }

    void show()
    {
        printf("%d/%d/%d\n", this->day, this->month, this->year);
    }

};

void testDate();

Date myDate(17, 5, 2026);


int main()
{
    testDate();
    return 0;
}

void testDate()
{
    Date myDate(17, 5, 2026);
    myDate.show();

    puts("Accessing private variables");

    int* ptr = (int*)&myDate; // Accessing private variables using pointer arithmetic

    printf("Day: %d\n", *(ptr)); // Accessing day
    printf("Month: %d\n", *(++ptr)); // Accessing month
    printf("Year: %d\n", *(++ptr)); // Accessing year

}

