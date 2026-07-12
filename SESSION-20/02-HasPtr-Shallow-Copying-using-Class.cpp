#include <iostream> 

class IntPtr
{
    friend class HasPtr; 
    private: 
        int *ptr; 
        int ref_count; 

        IntPtr(int val) : ptr(new int(val)), ref_count(1)
        {
        }

        ~IntPtr() 
        {
            std::cout << "IntPtr::~IntPtr()" << std::endl; 
            delete ptr; 
            ptr = 0; 
        }
}; 

class HasPtr 
{
    private: 
        int n; 
        IntPtr* pIntPtr; 

    public: 
        HasPtr(int _n, int _val) : n(_n), pIntPtr(new IntPtr(_val))
        {
        }

        HasPtr(const HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr)
        {
            this->pIntPtr->ref_count += 1; 
        }

        HasPtr& operator=(const HasPtr& other) 
        {
            if(this != &other)
            {
                this->n = other.n; 

                if(--this->pIntPtr->ref_count == 0)
                {
                    delete this->pIntPtr; 
                }

                this->pIntPtr = other.pIntPtr; 
                this->pIntPtr->ref_count += 1; 
            }

            return *this; 
        }

        ~HasPtr() 
        {
            if(--pIntPtr->ref_count == 0)
            {
                delete this->pIntPtr; 
            }
        }

        int getn() const 
        {
            return this->n; 
        }

        int get_val() const 
        {
            return *this->pIntPtr->ptr; 
        }

        void setn(int new_n)
        {
            this->n = new_n; 
        }

        void set_val(int new_val)
        {
            *this->pIntPtr->ptr = new_val; 
        }

        int get_ref_count() const 
        {
            return this->pIntPtr->ref_count; 
        }
}; 

void test_shallow_copying(); 

int main() 
{
    test_shallow_copying(); 
    return 0; 
}

void test_shallow_copying() 
{
    //  Group 1 
    std::cout << "Group 1 object ref counts progressively incrementing" << std::endl; 
    HasPtr* php1 = new HasPtr(100, 200);    //  Group OG object 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 1 
    HasPtr* php2 = new HasPtr(*php1);       //  Copy Ctor
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 2 
    HasPtr* php3 = new HasPtr(*php2); 
    std::cout << "php2->get_ref_count():" << php2->get_ref_count() << std::endl;    // 3 
    HasPtr* php4 = new HasPtr(*php1); 
    std::cout << "php4->get_ref_count():" << php4->get_ref_count() << std::endl;    // 4 

    //  Group 2 
    HasPtr* g2_php1 = new HasPtr(500, 600); //  Group OG object 
    HasPtr* g2_php2 = new HasPtr(*g2_php1);     
    HasPtr* g2_php3 = new HasPtr(*g2_php2); 

    std::cout << "Group 2 objects ref counts displayed all at once" << std::endl; 
    std::cout << "g2_php1->get_ref_count():" << g2_php1->get_ref_count() << std::endl; 
    std::cout << "g2_php2->get_ref_count():" << g2_php2->get_ref_count() << std::endl; 
    std::cout << "g2_php3->get_ref_count():" << g2_php3->get_ref_count() << std::endl; 

    //  Steal object g2_php2 in group 2 
    *g2_php2 = *php3; 

    //  Print refcounts from all members of group 1 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;        // 5
    std::cout << "php2->get_ref_count():" << php2->get_ref_count() << std::endl;        // 5
    std::cout << "php3->get_ref_count():" << php3->get_ref_count() << std::endl;        // 5 
    std::cout << "php4->get_ref_count():" << php4->get_ref_count() << std::endl;        // 5 
    std::cout << "g2_php2->get_ref_count():" << g2_php2->get_ref_count() << std::endl;  // 5 
 
    //  Print refcounts from all members of group 2 
    std::cout << "g2_php1->get_ref_count():" << g2_php1->get_ref_count() << std::endl;  //  2 
    std::cout << "g2_php3->get_ref_count():" << g2_php3->get_ref_count() << std::endl;  //  2 

    std::cout << "Starting deletion of objects in Group 1" << std::endl; 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 5 
   
    delete g2_php2; 
    g2_php2 = 0; 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 4 
    
    delete php4; 
    php4 = 0;
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 3 
   
    delete php3;  
    php3 = 0; 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 2 
   
    delete php2; 
    php2 = 0; 
    std::cout << "php1->get_ref_count():" << php1->get_ref_count() << std::endl;    // 1 
 
    delete php1; 
    php1 = 0; 
    std::cout << "Message above this must be from dtor()" << std::endl; 


    //  Group 2 deletion 
    delete g2_php3; 
    g2_php3 = 0; 
    std::cout << "g2_php1->get_ref_count():" << g2_php1->get_ref_count() << std::endl;  //  1 

    delete g2_php1; 
    g2_php1 = 0; 
    std::cout << "Message above this must be from dtor()" << std::endl; 
}   
   