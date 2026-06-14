class Date
{
private:
    int day, month, year;
public:
    Date(int _day, int _month, int _year);
    ~Date();

    int getDay() const //const make hidden this pointer const, which means we cant use const on static member functions
    {
        return this->day;
    }

    void setDay(int newDay)
    {
        this->day = newDay;
    }
};

Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year)
{
}

Date::~Date()
{
}

void test()
{
    Date myDate(14, 6, 2020);

    int dd = myDate.getDay();
    const Date* ptr = &myDate;

    ptr->getDay();

    // CTE : the object has type qualifiers that are not compatible with the member function "Date::setDay"
    //ptr->setDay(20);
}



