#include "Date.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

// Getters
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

