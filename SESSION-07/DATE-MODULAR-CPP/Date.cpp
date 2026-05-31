#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <stdexcept> 
#include "Date.hpp"

Date::Date() : day(1), month(1), year(1970)
{
}

Date::Date(day_t init_day, month_t init_month, year_t init_year) 
{
    if(! is_date_valid(init_day, init_month, init_year))
        throw std::domain_error("invalid date"); 

    this->day = init_day; 
    this->month = init_month; 
    this->year = init_year; 
}   

Date::Date(char* dateStr)
{
    size_t len = strlen(dateStr); 
    char* p = (char*)malloc(len + 1); 
    assert(p); 

    strncpy(p, dateStr, len); 
    p[len] = '\0'; 

    char* sep = "/"; 

    day_t init_day = atoi(strtok(p, sep)); 
    month_t init_month = atoi(strtok(NULL, sep)); 
    year_t init_year = atoi(strtok(NULL, sep)); 
    
    if(! is_date_valid(init_day, init_month, init_year))
        throw std::domain_error("invalid date"); 

    this->day = init_day; 
    this->month = init_month; 
    this->year = init_year; 

    free(p); 
    p = NULL; 
}

bool Date::is_date_valid(day_t day, month_t month, year_t year)
{
    //  Step 1: Determine whether year is leap or not. Store it in a flag variable 
    //  Step 2: If month == 2 then depending on whether year is leap or not 
    //          check the date range (1-29 if leap, 1-28 if not leap)
    //  Step 3: If month is not 2: 
    //          Then for 30 day month : day value range 1-30 
    //          for 31 day month: day value 1 - 31 

    return true;
}

day_t Date::get_day()
{
    return this->day; 
}

month_t Date::get_month()
{
    return this->month; 
}

year_t Date::get_year()
{
    return this->year; 
}

void Date::set_day(day_t new_day)
{
    if(! is_date_valid(new_day, this->month, this->year))
        throw std::domain_error("New day value is not valid"); 
    this->day = new_day; 
}

void Date::set_month(month_t new_month)
{
    if(! is_date_valid(this->day, new_month, this->year))
        throw std::domain_error("New month value is not valid"); 
    this->month = new_month; 
}

void Date::set_year(year_t new_year)
{
    this->year = new_year; 
}

void Date::show(const char* msg)
{
    if (msg)
    {
        puts("msg");
    }
    
    printf("%d/%d/%d\n", this->day, this->month, this->year);
}

