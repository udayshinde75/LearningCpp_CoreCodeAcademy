#include <iostream>

class Rectangle
{
    private:
        double length;
        double width;

    private:
        double validateValue(double _value);

    public:
        Rectangle();
        Rectangle(double _length, double _width);

        // Getters
        double getLength();
        double getWidth();

        // Setters
        void setLength(double _length);
        void setWidth(double _value);

        // Calculate area
        double calculateArea();
};

// Default Constructor
Rectangle::Rectangle() : length(1.0), width(1.0) {};

// Parameterized Constructor
Rectangle::Rectangle(double _length, double _width) : length(validateValue(_length)), width(validateValue(_width)) {};

// Getters
double Rectangle::getLength()
{
    return this->length;
}

double Rectangle::getWidth()
{
    return this->width;
}

// Setters
void Rectangle::setLength(double _length)
{
    this->length = validateValue(_length);
}

void Rectangle::setWidth(double _width)
{
    this->width = validateValue(_width);
}

// Calculate area
double Rectangle::calculateArea()
{
    return (this->length) * (this->width);
}

// Private helper
double Rectangle::validateValue(double _value)
{
    return _value < 0.0 ? 1.0 : _value;
}


// Main function
int main(void)
{
    // Using default constructor
    puts("Creating bject using default constructor:\n");
    Rectangle rectangle_1;
    printf("Lenght of rectangle_1 : %f\n", rectangle_1.getLength());
    printf("Width of rectangle_1 : %f\n", rectangle_1.getWidth());

    printf("Updating Length of rectangle_1 to 200.0\n");
    rectangle_1.setLength(200.0);
    printf("Updating width of rectangle_1 to 300.0\n");
    rectangle_1.setWidth(300.0);

    printf("Calculating area of rectangle_1 : %f\n", rectangle_1.calculateArea());

    // Using parameterized constructor
    puts("Creating bject using parameterized constructor:\n");
    Rectangle rectangle_2(456, 256);
    printf("Lenght of rectangle_2 : %f\n", rectangle_2.getLength());
    printf("Width of rectangle_2 : %f\n", rectangle_2.getWidth());

    printf("Updating Length of rectangle_2 to 333.0\n");
    rectangle_2.setLength(333.0);
    printf("Updating width of rectangle_2 to 333.0\n");
    rectangle_2.setWidth(333.0);

    printf("Calculating area of rectangle_2 : %f\n", rectangle_2.calculateArea());

    return 0;
}

