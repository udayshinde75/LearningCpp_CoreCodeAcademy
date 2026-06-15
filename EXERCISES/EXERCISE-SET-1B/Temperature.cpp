#include <iostream>

class Temperature
{
private:
    double celsius;
public:
    Temperature(double _celcius);
    ~Temperature() = default;

    void setCelcius(double c);
    double getCelcius() const;

    void setFahrenheit(double f);
    double getFahrenheit() const;

    void setKelvin(double k);
    double getKelvin() const;
};

Temperature::Temperature(double _celcius)
    : celsius(_celcius)
{
}

void Temperature::setCelcius(double c)
{
    this->celsius = c;
}
double Temperature::getCelcius() const
{
    return this->celsius;
}
void Temperature::setFahrenheit(double f)
{
    this->celsius = (5*(f - 32)) / 9;
}
double Temperature::getFahrenheit() const
{
    return (this->celsius * (9/5)) + 32;
}
void Temperature::setKelvin(double k)
{
    this->celsius = k - 273.15;
}
double Temperature::getKelvin() const
{
    return this->celsius + 273.15;
}