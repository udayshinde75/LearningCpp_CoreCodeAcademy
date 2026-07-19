#ifndef _SORT_HPP
#define _SORT_HPP

typedef long long s_size_t;

template <typename T>
void insertion_sort(T* a, s_size_t N)
{
    ssize_t i, j;
    T key;
    for (j = 1; j < N; ++j)
    {
        key = a[j];
        i = j - 1;
        while (i > -1 && a[i] > key)
        {
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }
}

template <typename T>
void show_array(T* a, s_size_t N, const char* msg = 0)
{
    if(msg)
        std::cout << msg << std::endl; 

    for(ssize_t i = 0; i != N; ++i) 
        std::cout << "a[" << i << "]:" << a[i] << std::endl; 
}
#endif //_SORT_HPP