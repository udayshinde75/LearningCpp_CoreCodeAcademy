#include <cstdio>

class Test
{
    private:
        int num1;
        int num2;

    public:
        Test() : num1(100), num2(200)
        {

        }

        int get_num1()
        {
            return this->num1;
        }

        void set_num1(int new_num1)
        {
            num1 = new_num1;
            // gets converted to 
            this->num1 = new_num1;

            test_function(45.0f, 60.f); // Why
            this->test_function(45.0f, 60.f); // Why
            // Allowing call to static function from object
            // helps us to call static function of class within
            // any other member function of class without qualification
            // because unqualified member names are qualified by this->, an unqualified call to static member will implicitely qualified by this->

        }

        // No hidden 'this' pointer. this function do not need the class object to operate.
        static void test_function(float x, float y)
        {
            printf("x = %.2f, y = %.2f\n", x, y);
        }
};

int main()
{
    Test t;

    // non static member function
    t.get_num1();
    t.set_num1(199);

    // static member function
    Test::test_function(1.0f, 3.0f);

    // this allowed. why?
    t.test_function(45.0f, 89.0f);
    return 0;
}