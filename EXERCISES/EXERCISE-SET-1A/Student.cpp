#include <iostream>
#include <string>

class Student
{
private:
    std::string studentName;
    int studentAge;

public:
    Student();
    Student(const std::string& _studentName, int _studentAge);

    void Display() const;
};

// Constructors
Student::Student()
    : studentName("Unknown"), studentAge(0)
{
}

Student::Student(const std::string& _studentName, int _studentAge)
    : studentName(_studentName), studentAge(_studentAge)
{
}

// Public function
void Student::Display() const
{
    std::cout << "Student Details are as follows:\n";
    std::cout << studentName << ", " << studentAge << '\n';
}

// Main
int main()
{
    Student student_1;

    std::cout << "Details of student_1\n";

    student_1.Display();

    Student student_2("Dada Shinde", 22);

    std::cout << "Details of student_2\n";

    student_2.Display();

    return 0;
}