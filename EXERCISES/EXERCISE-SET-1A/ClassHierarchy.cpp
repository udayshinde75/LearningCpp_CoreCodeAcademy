#include <string>
#include <atomic>
#include <iostream>

class Person
{
    private:
        std::string name;
        int age;
        const int ID;

    private:
        static int getNextID();

    public:
        Person();
        Person(const std::string& name, int age);
        Person(const Person& other) = delete;
        Person& operator=(const Person&) = delete;
        const std::string& getName() const;
        const int getAge() const;
        const int getID() const;
};

Person::Person() : name(""), age(0), ID(getNextID()) {}

Person::Person(const std::string& name, int age) : name(name), age(age), ID(getNextID()) {}

int Person::getNextID()
{
    static std::atomic<int> nextID {0};
    return ++nextID;
}

const std::string& Person::getName() const
{
    return name;
}

const int Person::getAge() const
{
    return age;
}

const int Person::getID() const
{
    return ID;
}

class Employee : public Person
{
    private:
        double salary;
        std::string department;
        int employeeCode;

    private:
        static int getNextEmpCode();

    public:
        Employee();
        Employee(const std::string& name, int age, double sal, const std::string& department);
        Employee(const Employee& other) = delete;
        Employee& operator= (const Employee&) = delete;
        const double getSalary() const;
        const std::string& getDepartment() const;
        const int getEmployeeCode() const;
};

Employee::Employee() : Person(), salary(0), department(""), employeeCode(getNextEmpCode()) {}

Employee::Employee(const std::string& name, int age, double sal, const std::string& department) : Person(name, age), salary(sal), department(department), employeeCode(getNextEmpCode()) {}

int Employee::getNextEmpCode()
{
    static std::atomic<int> nextID{1000};
    return ++nextID;
}

const double Employee::getSalary() const
{
    return salary;
}
const std::string& Employee::getDepartment() const
{
    return department;
}
const int Employee::getEmployeeCode() const
{
    return employeeCode;
}

int main(void)
{
    std::cout << "emp1 created with default constructor\n";
    Employee emp1;
    std::cout << "Person ID of emp1 : " << emp1.getID() << "\n";
    std::cout << "Person name of emp1 : " << emp1.getName() << "\n";
    std::cout << "Person age of emp1 : " << emp1.getAge() << "\n";
    std::cout << "Employee salary of emp1 : " << emp1.getSalary() << "\n";
    std::cout << "Employee department of emp1 : " << emp1.getDepartment() << "\n";
    std::cout << "Employee code of emp1 : " << emp1.getEmployeeCode() << "\n";

    std::cout << "emp2 created with parameterized constructor\n";
    Employee emp2("Uday Shinde", 23, 23000, "Information Technology");
    std::cout << "Person ID of emp2 : " << emp2.getID() << "\n";
    std::cout << "Person name of emp2 : " << emp2.getName() << "\n";
    std::cout << "Person age of emp2 : " << emp2.getAge() << "\n";
    std::cout << "Employee salary of emp2 : " << emp2.getSalary() << "\n";
    std::cout << "Employee department of emp2 : " << emp2.getDepartment() << "\n";
    std::cout << "Employee code of emp2 : " << emp2.getEmployeeCode() << "\n";

    return 0;
}