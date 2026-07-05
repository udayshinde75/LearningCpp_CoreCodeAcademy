#include <iostream> 

class HasPtr 
{
    private: 
        int m; 
        int* ptr; 

    public: 
        HasPtr(int _m, int _n) : m(_m), ptr(new int(_n))
        {
        }

        int get_val() const 
        {
            return m; 
        }

        int get_ptr_val() const 
        {
            return *ptr; 
        }

        void set_val(int new_val)
        {
            m = new_val; 
        }

        void set_ptr_val(int new_val)
        {
            *ptr = new_val; 
        }

        //  If we do not implement dtor then object pointed by ptr will be leaked 
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
    HasPtr* p_hp1 = new HasPtr(100, 200); 
    HasPtr* p_hp2 = new HasPtr(*p_hp1); 

    delete p_hp2;   //  Because of dtor p_hp2->ptr has been freed 
                    //  Making p_hp1->ptr a dangling pointer 
                    //  Whenever it will be de-referenced it will bring a disaster
    p_hp2 = 0; 

    p_hp1->get_ptr_val();   //  segfault 

    //  Counter Lets not access p_hp1 at all 

    //  If you let test() return without deleting p_hp1 -> leads to -> memory leak of entire object 

    //  and if we delete it 

    delete p_hp1;   //  In dtor delete p_hp1->ptr will happen -> again bringing disaster.   
    p_hp1 = 0; 

    //  Assignment will also bring a disaster 
    HasPtr* p_hp3 = new HasPtr(100, 200); 
    HasPtr* p_hp4 = new HasPtr(1000, 2000); 

    *p_hp3 = *p_hp4; 
    //  Synthesized version of copy assignment operator will be used 
    //  HasPtr::operator=(p_hp3, *p_hp4)
    //  this-> address in p_hp3 
    //  implicit pointer of other reference variable -> address of p_hp4

    //  this->m = other.m       //  actually -> p_hp3->m = p_hp4->m; 
    //  this->ptr = other.ptr;  //  actually -> p_hp3->ptr = p_hp4->ptr; 
    //  Memory leak: Integer object on heap containing 200 will be leaked 
}

