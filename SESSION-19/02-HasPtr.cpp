#include <iostream> 

struct IntPtr
{
    int* ptr; 
    int ref_count; 
}; 

class HasPtr
{
    private: 
        int n; 
        struct IntPtr* pIntPtr; 

    public: 
        HasPtr(int _n, int _val) : n(_n), pIntPtr(new IntPtr)
        {
            pIntPtr->ptr = new int(_val); 
            pIntPtr->ref_count = 1; 
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
                this->pIntPtr->ref_count -= 1; 
                if(this->pIntPtr->ref_count == 0)
                {
                    delete this->pIntPtr->ptr; 
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
                delete pIntPtr->ptr; 
                delete pIntPtr; 
            }
        }
}; 