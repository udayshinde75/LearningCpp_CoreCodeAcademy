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
    HasPtr(int _n, int _val);
    HasPtr(const HasPtr& other);
    HasPtr& operator=(const HasPtr& other);
    ~HasPtr();

    int get_n() const;
    int get_val() const;
    void set_n(int new_n);
    void set_val(int new_val);
    int get_ref_count() const;
};

HasPtr::HasPtr(int _n, int _val) : n(_n), pIntPtr(new IntPtr)
{
    pIntPtr->ptr = new int(_val);
    pIntPtr->ref_count = 1;
}

HasPtr::HasPtr(const HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr)
{
    pIntPtr->ref_count += 1;
}

HasPtr& HasPtr::operator=(const HasPtr& other)
{
    if (this != &other)
    {
        this->n = other.n;
        if (--this->pIntPtr->ref_count == 0)
        {
            delete this->pIntPtr->ptr;
            delete this->pIntPtr;
        }
        this->pIntPtr = other.pIntPtr;
        this->pIntPtr->ref_count += 1;
    }
    return *this;
}

HasPtr::~HasPtr()
{
    if (--pIntPtr->ref_count == 0)
    {
        delete pIntPtr->ptr;
        delete pIntPtr;
    }
}
