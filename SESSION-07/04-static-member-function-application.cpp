#include <cstdio>

class Employee
{
    private:
        int empId;
        double empSal;
        char* empname;

        static int nextEmpId;

        static int getNextEmpId()
        {
            return ++nextEmpId;
        }
    public:
        Employee(double sal, char* name) : empSal(sal), empname(name)
        {
            // Allowed
            ++nextEmpId;
            empId = getNextEmpId();
        }
};

int Employee::nextEmpId = 0;

// Static member function -> No static members -> Unqualified access is not allowed.