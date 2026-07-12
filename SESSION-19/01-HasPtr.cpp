#include <iostream> 
#include <cassert> 

class HasPtr
{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _val) : n(_n), ptr(new int(_val))
        {   
        }

        HasPtr(const HasPtr& other) : n(other.n), ptr(new int(*other.ptr))
        {
        }

        HasPtr& operator=(const HasPtr& other) 
        {
            if(this != &other)
            {
                this->n = other.n; 
                *this->ptr = *other.ptr; 
            }
            
            return *this; 
        }

        int getn() const 
        {
            return n; 
        }

        int get_ptr_val() const 
        {
            return *ptr; 
        }

        void setn(int new_n)
        {
            n = new_n; 
        }

        void set_ptr_val(int new_val) 
        {
            *ptr = new_val; 
        }

        int* get_ptr() const 
        {
            return ptr; 
        }

        ~HasPtr() 
        {
            if(ptr)
            {
                delete ptr; 
                ptr = 0; 
            }
        }
}; 

void test();    

int main()
{
    test(); 
    return 0; 
}

void test()
{
    HasPtr hp1(100, 200); 
    HasPtr hp2(hp1);    //  Copy Ctor: HasPtr::HasPtr(&hp2, hp1); 

    ///HasPtr hp2(hp1);    //  This is not a call operator overload case 
    ///HasPtr hp2 = hp1;   //  This is not a copy assignment case 

    std::cout << "n:" << hp1.getn() << ", *ptr:" << hp1.get_ptr_val() << std::endl; 
    std::cout << "n:" << hp2.getn() << ", *ptr:" << hp2.get_ptr_val() << std::endl; 
    
    if(&hp1 != &hp2)
    {
        int* p1 = hp1.get_ptr(); 
        int* p2 = hp2.get_ptr(); 
        assert(p1 != p2); 
        std::cout << "Invariant holds (Copy Ctor)" << std::endl; 
    }

    HasPtr hp3(300, 400); 

    hp1 = hp3;  //  Copy assignment operator:   HasPtr::operator=(&hp1, hp3)

    std::cout << "n:" << hp1.getn() << ", *ptr:" << hp1.get_ptr_val() << std::endl; 
    std::cout << "n:" << hp3.getn() << ", *ptr:" << hp3.get_ptr_val() << std::endl; 

    if(&hp1 != &hp3)
    {
        int* p1 = hp1.get_ptr(); 
        int* p2 = hp3.get_ptr(); 
        assert(p1 != p2); 
        std::cout << "Invariant holds (Copy Assignment)" << std::endl; 
    }
}

/* 
    Let O1 and O2 be two objects of type HasPtr 

    INVARIANT: 
        O1 != O2    ->  O1.ptr != O2.ptr 
*/

/* 
    C++ Primer 
        1000

    Essential C++ 
        Programming Idioms (250)

    A Tour of C++ 

    Don't Panic.
*/