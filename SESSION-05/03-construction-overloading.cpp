#include <cstdio> 
#include <cstdlib> 
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

        //  Date D("23/5/2026");
        Date(char dateStr[])
        {
            const char* sep = "/";
            char* day_token = strtok(dateStr, sep); 
            char* month_token = strtok(NULL, sep); 
            char* year_token = strtok(NULL, sep); 

            this->day = atoi(day_token); 
            this->month = atoi(month_token); 
            this->year = atoi(year_token); 
        }

        void show(const char* msg = 0)
        {
            if(msg)
                puts(msg); 

            printf("%d / %d / %d\n", this->day, this->month, this->year); 

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
    Date D1; 
    Date D2(23, 5, 2026); 
    char dateStr[] = "23/5/2026"; 
    Date D3(dateStr); 

    D1.show("Default CC"); 
    D2.show("Parameterised CC: int, int, int"); 
    D3.show("Parameterised CC: char[]"); 
}