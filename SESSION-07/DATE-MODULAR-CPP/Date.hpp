#ifndef _DATE_HPP_
#define _DATE_HPP_

// typdef section
typedef int day_t;
typedef int month_t;
typedef int year_t;

class Date
{
    private:
        day_t day;
        month_t month;
        year_t year;

        static bool is_date_valid(day_t day, month_t month, year_t year);

    public:
        // Constructor
        Date();
        Date(day_t init_day, month_t init_month, year_t init_year);
        Date(char* datestr);

        // Getters
        day_t get_day();
        month_t get_month();
        year_t get_year();

        // Setters
        void set_day(day_t new_day);
        void set_month(month_t new_month);
        void set_year(year_t new_year);

        void show(const char* msg = 0);
};

#endif /* _DATE_HPP_ */