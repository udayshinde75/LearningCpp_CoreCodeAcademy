#include <cstdio> 
#include <cstdlib> 

class Date 
{
    private: 
        int day, month, year; 
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }

        Date() 
        {

        }
};

void test(); 

int main()
{
    test(); 
    return EXIT_SUCCESS; 
}

void test() 
{
    Date* pDate_1 = new Date;               // No - initialization data - Empowered by Default Ctor 
    Date* pDate_2 = new Date(31, 5, 2026);  //  Initialization data - Empowered by 
                                            //  Parameterized constructor 

    delete pDate_1; 
    pDate_1 = 0; 

    delete pDate_2; 
    pDate_2 = 0; 
}

/* 
    MyType *ptr = new MyType(InitializationData); 
    == 
    MyType* ptr = (MyType*)malloc(sizeof(MyType)); 
    MyType::MyType(ptr, InitializationData)
    INFERENCE : new = malloc() + automated call to ctor 

    delete ptr; 
    == 
    Date::~Date(ptr);   //  automated call to dtor  
    free(ptr)           //  free 
    INFERENCE : delete = automated call to dtor + free

*/