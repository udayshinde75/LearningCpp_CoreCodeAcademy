//  Using reference variable, we can attach instance varaible like name to 
//  anonymous memory blocks 

#include <cstdio> 

void test(); 

int main() 
{
    test(); 
    return 0; 
}

void test() 
{
    int num = 100; 
    int& ref1 = num; 

    int* p = new int(200); 

    *p = 500;   //  I can write on dynamically allocated 
                //  int
                
    int& ref2 = *p; 

    printf("BEFORE ref2 = 700:*p = %d\n", *p); 
    ref2 = 700; 
    printf("AFTER ref2 = 700:*p = %d\n", *p); 

    delete &ref2; 
}

//  T& v = ANY RHS EXPRESSION WHICH DEPICTS LOCATION VALUE OF TYPE T

/* 
    int* p = new int(100); 

    type(p) ==  int* 
    type(*p) == int 

    is *p not an expression depicting a memory location of type int? 

    int& ref = *p; 

    int& ref2 = *(new int(100)); 

    ref2 = 500; 
    printf("ref2 = %d\n", ref2); 

    delete &ref2; 
*/

/* 

class list 
{
    class iterator 
    {
        public: 

            iterator& operator++() 
            {
                this->run = this->run->next; 
                return *this; 
            }
    }; 
}; 

*/