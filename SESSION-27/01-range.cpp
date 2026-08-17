 #include <iostream>
 #include <stdexcept>

 class range {
    public:
        range(int _start_number, int _end_number) :
            start_number(_start_number), end_number(_end_number) 
        {
            if (start_number < 0 || end_number < 0)
            {
                throw std::out_of_range("Both start and end number must be positive");
            }
            if (start_number >= end_number)
            {
                throw std::out_of_range("Start number must be less than that of end number");
            }
        }
        
        range(int _end_number) : start_number(0), end_number(_end_number)
        {
            if (start_number < 0 || end_number < 0)
            {
                throw std::out_of_range("Both start and end number must be positive");
            }
            if (start_number >= end_number)
            {
                throw std::out_of_range("Start number must be less than that of end number");
            }
        }

        class iterator {
            public:
                // Default + parameterized 
                explicit iterator(int _n = 0) : n(_n) {}

                iterator operator++()
                {
                    ++n;
                    return *this;
                }

                iterator operator--()
                {
                    --n;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator temp(n);
                    ++n;
                    return temp;
                }

                iterator operator--(int)
                {
                    iterator temp(n);
                    --n;
                    return temp;
                }

                bool operator==(const iterator& other)
                {
                    return (this->n == other.n);
                }

                bool operator!=(const iterator& other)
                {
                    return (this->n != other.n);
                }

                int operator*() const
                {
                    return this->n;
                }
            private:
                int n;
        };

        iterator begin()
        {
            return iterator(this->start_number);
        }

        iterator end()
        {
            return iterator(this->end_number);
        }
    private:
        int start_number, end_number;
 };

 void test();

 int main()
 {
    test();
    return 0;
 }

 void test()
 {
    range R1(10, 20);
    range R2(30);

    std::cout << "Iterating over R1 using range::iterator" << std::endl;
    for (
        range::iterator iter = R1.begin();
        iter != R1.end();
        ++iter
    )
    {
        std::cout << "*iter = " << *iter << std::endl;  
    }

    std::cout << "Iterating over R2 using range::iterator" << std::endl;
    for (
        range::iterator iter = R2.begin();
        iter != R2.end();
        ++iter
    )
    {
        std::cout << "*iter = " << *iter << std::endl;  
    }
 }