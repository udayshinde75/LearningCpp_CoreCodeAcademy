#include <cstddef>
#include <cstdio>
#include <iostream>

#define SUCCESS 0
#define FAILURE 1
class SmartArray
{
    private:
        int* data;
        std::size_t size;

    private:
        void allocateMemory(int s);
        void deallocateMemory();

    public:
        SmartArray(std::size_t size);
        SmartArray(const SmartArray& other) noexcept;
        SmartArray(SmartArray&& other) noexcept;
        ~SmartArray();
        int setValue(int index, int& value);
        int getValue(int index, int& value);
        int getSize();
        int setSize(size_t newSize);
};

// Constructor/Destructors
SmartArray::SmartArray(std::size_t size) : size(size)
{
    data = new int[size];
}

SmartArray::SmartArray(const SmartArray& other) noexcept : size(other.size)
{
    data = new int[size];

    for (std::size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

SmartArray::SmartArray(SmartArray&& other) noexcept
    : data(other.data), size(other.size)
{
    other.data = nullptr;
    other.size = 0;
}

SmartArray::~SmartArray()
{
    delete[] data;
    data = nullptr;
}

int SmartArray::setValue(int index, int& value)
{
    if (size == 0 || size <= index)
    {
        return FAILURE;
    }
    else
    {
        data[index] = value;
        return SUCCESS;
    }
}

int SmartArray::getValue(int index, int& value)
{
    if (size == 0 || size <= index)
    {
        return FAILURE;
    }
    else
    {
        value = data[index];
        return SUCCESS;
    }
}

int SmartArray::getSize()
{
    return size;
}

int SmartArray::setSize(size_t newSize)
{
    if (newSize == size )
    {
        return SUCCESS;
    }

    int* newData = (newSize > 0) ? new int[newSize] : nullptr;

    size_t elementsToCopy = newSize > size ? size : newSize;

    for (size_t i = 0; i < elementsToCopy; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;

    return SUCCESS;
}

int main()
{
    SmartArray array(4);

    int choice;
    int index;
    int value;
    while (true)
    {
        std::cout << "Select choice : 1)get Value, 2)set value, 3) get size 4)incrase size. Ctrl+C to stop : ";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1)
        {
            std::cout << "Enter index for which to retrive value : ";
            std::cin >> index;
            while (index < 0)
            {
                std::cout << "Enter index for which to retrive value : ";
                std::cin >> index;
            }
            std::cout << "\n";
            int Success = array.getValue(index, value);
            if (Success == SUCCESS)
            {
                std::cout << "Value is : " << value << "\n";
            }
            else
            {
                std::cout << "Invalid index\n";
            }
        }
        if (choice == 2)
        {
            std::cout << "Enter index for which to set value : ";
            std::cin >> index;
            while (index < 0)
            {
                std::cout << "Enter index for which to set value : ";
                std::cin >> index;
            }
            std::cout << "Enter value to insert : ";
            std::cin >> value;
            int success = array.setValue(index, value);
            if (success == SUCCESS)
            {
                std::cout << "Value inserted successfully\n";
            }
            else
            {
                std::cout << "Invalid index\n";
            }
        }
        if (choice == 3)
        {
            std::cout << "Size of the array : " << array.getSize() << "\n";
        }
        if (choice == 4)    
        {
            std::cout << "Enter the value to which size should increase or decrease : ";
            std::cin >> value;
            while (value < 0)
            {
                std::cout << "Enter the value to which size should increase or decrease : ";
                std::cin >> value;
            }
            int success = array.setSize(value);
            if (success == SUCCESS)
            {
                std::cout << "Size increased successfully\n";
            }
            else
            {
                std::cout << "Failed\n";
            }
        }
    }
}