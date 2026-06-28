#include <iostream> 

class Date 
{
    friend class Test; 

    private: 
        int dd, mm, yy; 

    public: 
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy)
        {
        }

        Date() : dd(1), mm(1), yy(1970)
        {
        }  

        void show() 
        {
            std::cout << dd << "/" << mm << "/" << yy << std::endl; 
        }
}; 

class Test
{
    friend void myFunction(); 
    public: 
        void member_function() 
        {
            Date myDate; 

            myDate.dd = 11; //  No error 
            myDate.show(); 
        }

        static void static_member_function() 
        {
            Date myDate; 

            myDate.yy = 2028; //    Not error
            myDate.show(); 
        }
}; 

void myFunction()
{
    Date myDate; 

    //  myDate.dd = 1;  // friend ship is not transitive in C++ 

    std::cout << "BEFORE:" << std::endl; 
    myDate.show(); 

    *(int*)((char*)&myDate + 0)=  28; 
    *(int*)((char*)&myDate + 4)=  6; 
    *(int*)((char*)&myDate + 8)=  2026; 

    std::cout << "After:" << std::endl; 
    myDate.show(); 

}

int main() 
{
    Test t; 

    t.member_function(); 
    t.static_member_function(); 

    myFunction(); 

    return 0; 
}