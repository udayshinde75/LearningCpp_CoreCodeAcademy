#ifndef _SORT_HPP
#define _SORT_HPP

typedef long long s_size_t;

template<typename T>
s_size_t partition(T* a, s_size_t p, s_size_t r)
{
    T pivot = a[r];
    T tmp;
    s_size_t i, j;

    i = p - 1;
    j = p;
    while (j < r)
    {
        if (a[j] < pivot)
        {
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        j = j + 1;
    }

    tmp = a[r];
    a[r] = a[i + 1];
    a[i + 1] = tmp;

    return (i + 1);
}

template <typename T>
void quick_sort(T* a, s_size_t p, s_size_t r)
{
    if (p < r)
    {
        s_size_t q = partition<T>(a, p, r);
        quick_sort<T>(a, p, q - 1);
        quick_sort<T>(a, q + 1, r);
    }
}

template <typename T>
void show_array(T* a, s_size_t N, const char* msg = 0)
{
    if (msg)
    {
        std::cout << msg << std::endl;
    }

    for (s_size_t i = 0; i != N; i++)
    {
        std::cout << "a[" << i << "]:" << a[i] << std::endl;
    }
}

#endif