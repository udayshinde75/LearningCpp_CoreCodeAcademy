#include <stdio.h> 
#include <stdlib.h> 

//  SERVER SIDE CODE - PART 1 - START 
typedef struct Date Date; 

struct Date 
{   
    int day; 
    int month; 
    int year; 
}; 

Date* createDate(int init_day, int init_month, int init_year); 
int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 
void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 
void showDate(Date* pDate); 
void releaseDate(Date* pDate); 

//  SERVER SIDE CODE - PART 1 - END 

void testDate(void); 

int main(void)
{
    testDate(); 
    //  Code that would break extendability 
    /* 
    Date D = {15, 3, 2026}; 
    printf("%d / %d / %d\n", D.day, D.month, D.year); 
    D.day = 16;
    D.month = 4; 
    D.year = 2027; 
    printf("%d / %d / %d\n", D.day, D.month, D.year); 
    */

    return (0); 
}

void testDate(void)
{
    //  CLIENT SIDE CODE - START 
    Date* myDate = NULL; 

    myDate = createDate(10, 5, 2026); 

    int dd = getDay(myDate); 
    int mm = getMonth(myDate); 
    int yy = getYear(myDate); 

    printf("dd = %d, mm = %d, yy = %d\n", dd, mm, yy); 
    
    setDay(myDate, 30); 
    setMonth(myDate, 6); 
    setYear(myDate, 2027); 

    showDate(myDate); 

    releaseDate(myDate); 
    myDate = NULL; 

    //  CLIENT SIDE CODE - END
}

//  SERVER SIDE CODE - PART 2 - START 
Date* createDate(int init_day, int init_month, int init_year)
{
    Date* pDate = (Date*)malloc(sizeof(Date)); 
    if(NULL == pDate)
    {
        fprintf(stderr, "fatal:malloc():out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

int getDay(Date* pDate)
{
    return (pDate->day); 
}

int getMonth(Date* pDate)
{
    return (pDate->month); 
}

int getYear(Date* pDate)
{
    return (pDate->year); 
}

void setDay(Date* pDate, int new_day)
{
    pDate->day = new_day; 
}

void setMonth(Date* pDate, int new_month)
{
    pDate->month = new_month; 
}

void setYear(Date* pDate, int new_year)
{
    pDate->year = new_year; 

}
void showDate(Date* pDate)
{
    printf("%d / %d / %d\n", pDate->day, pDate->month, pDate->year); 
}

void releaseDate(Date* pDate)
{
    free(pDate); 
    pDate = NULL;
}

//  SERVER SIDE CODE - PART 2 - END