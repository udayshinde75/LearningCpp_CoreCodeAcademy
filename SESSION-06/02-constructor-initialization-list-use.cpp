// sometimes initialization is compulsory

// const variables
const int num = 100; // Const data definition statement cannot be left uninitialized

//reference variables
int y = 100;
int& ref = y;
// int& ref; Refeerence vaiables must be initialized in its definition

// if a base class does not have a default constructor.
// then its constructor must be called explicitely from
// Derived class constructor

class Test
{
    private:
        const int num;
        int& ref;

    public:
        Test(int num, int y) : num(num), ref(y)
        {
            // num = 100; Error
        }
};

