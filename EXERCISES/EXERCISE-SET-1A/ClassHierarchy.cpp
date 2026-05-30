#include <string>
#include <atomic>
class Person
{
    private:
        std::string name;
        int age;
        const int ID;

    private:
        static std::atomic<int> nextID;

    public:
        Person();
        Person(const std::string& name, int age);
        Person(const Person& other) = delete;
        Person& operator=(const Person&) = delete;
        const std::string& getName() const;
        const int getAge() const;
        
};

// definition of static member
std::atomic<int> Person::nextID{0};