#include <iostream>

// stack of integers
template <int N>
class stack
{
private:
    int* p;
    int stack_size;
public:
    stack(): p(new int[N]), stack_size(N)
    {

    }
    ~stack();
};

int main()
{
    stack<10> s1;
    return 0;
}
