#include <string>
#include <iostream>

class Employee
{
    private:
        const int employeeID;
        std::string& department;
    
    public:
        std::string name;
        double salary;
    
    public:
        Employee(int _ID, std::string& _dept, std::string _name, double _salary);
        std::string& getDepartment();
        int getEmployeeID();
};

Employee::Employee(int _ID, std::string& _dept, std::string _name, double _salary) 
    : employeeID(_ID), department(_dept), name(_name), salary(_salary)
    { }
std::string& Employee::getDepartment() {
    return department;
}
int Employee::getEmployeeID() {
    return employeeID;
}


int main(void)
{
    std::string dept = "Admin";
    Employee emp(1001, dept, "Uday", 20000);

    std::cout << "Employee Name : " << emp.name << std::endl;
    std::cout << "Employee department : " << emp.getDepartment() << std::endl;
    std::cout << "Employee ID : " << emp.getEmployeeID() << std::endl;
    std::cout << "Employee salary : " << emp.salary << std::endl;

    return 0;
}