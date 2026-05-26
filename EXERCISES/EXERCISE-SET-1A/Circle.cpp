#include <iostream>
class Circle
{
    private:
        double radius;
    public:
        Circle();
        Circle(double r);
        Circle(const Circle& other);

        void Display();
        double getArea();
        double getCircumference();
};

Circle::Circle() : radius(0.0) {}
Circle::Circle(double r) : radius(r) {}
Circle::Circle(const Circle& other) : radius(other.radius) {}
void Circle::Display() {
    std::cout << "Radius of the Circle : " << radius << std::endl;
    std::cout << "Area of the Circle : " << getArea() << std::endl;
    std::cout << "Circumference of the Circle : " << getCircumference() << std::endl;
}
double Circle::getArea() {
    return 22/7 * radius * radius;
}
double Circle::getCircumference() {
    return 44/7 * radius;
}

int main(void)
{
    std::cout << "Created an object C with default constructor" << std::endl; 
    Circle C;
    std::cout << "Circle C : " << std::endl;
    C.Display();

    std::cout << "Created an object C1 with parameterized constructor" << std::endl; 
    Circle C1(5);
    std::cout << "Circle C1" << std::endl;
    C1.Display();

    std::cout << "Created an object C2 with copy constructor" << std::endl; 
    Circle C2(C1);
    std::cout << "Circle C2" << std::endl;
    C2.Display();

    return 0;
}