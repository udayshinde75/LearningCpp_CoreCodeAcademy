#include <iostream> 
#include <cstdlib> 

// Destructor theory
class array 
{
    private: 
        int* ptr; 
        int size; 

    public: 
        array(int _size) 
        {
            if(_size < 0)
            {
                std::cerr << "Size cannot be negative" << std::endl; 
                exit(EXIT_FAILURE);     // ideally throw an exception 
            }

            this->size = _size; 
            ptr = new int[this->size]; 
        }

        ~array() 
        {
            delete[] ptr;   
            ptr = 0; 
            size = 0; 
        }

        int get(int index) const 
        {
            if(index < 0 || index >= size)
            {
                std::cout << "Array index out of range" << std::endl; 
                exit(EXIT_FAILURE); 
            }
            return this->ptr[index]; 
        }

        void set(int index, int val)
        {
            if(index < 0 || index >= size)
            {
                std::cout << "Array index out of range" << std::endl; 
                exit(EXIT_FAILURE); 
            }
            
            this->ptr[index] = val; 
        }

        int getSize() const 
        {
            return size; 
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
    array A(10); 

    for(int i = 0; i != A.getSize(); ++i)
        A.set(i, (i+1) * 10); 

    for(int i = 0; i != A.getSize(); ++i)
    {
        int val = A.get(i); 
        std::cout << "Element at index:" << i << ", is:" << val << std::endl; 
    }
}

/* 
    T* ptr = new T[Size];   // Size may a run-time evaluable expression 

    //  Allocate contiguous block of sizeof(T) * Size bytes. 
    //  Return its address 
    //  Which we are storing in ptr 

    //  In order to free this block of sizeof(T) * Size bytes 
    //  the following syntax must be used 

    //  delete[] ptr; 


*/