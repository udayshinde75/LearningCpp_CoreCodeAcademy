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

        int getSize() const 
        {
            return size; 
        }

        int& operator[](int index)
        {
            return *(ptr+index);    
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
        A[i] = (i+1)*10;

    for(int i = 0; i != A.getSize(); ++i)
    {
        int val = A[i]; 
        std::cout << "Element at index:" << i << ", is:" << val << std::endl; 
    }
}