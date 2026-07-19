#include <iostream>
#include "sort.hpp"

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    int a_int[] = {30, 20, 40, 10, 49, 39};
    float a_float[] = {4.5f, 20.5f, 100.4f, 67.4f, 469.5f, 89.3f};
    char a_char[] = {'r', 'e', 'y', 'a', 'g', 'b'};

    show_array<int>(a_int, (s_size_t)(sizeof(a_int)/sizeof(a_int[0])), "Int arr before sort");
    show_array<float>(a_float, (s_size_t)(sizeof(a_float)/sizeof(a_float[0])), "float arr before sort");
    show_array<char>(a_char, (s_size_t)(sizeof(a_char)/sizeof(a_char[0])), "char arr before sort");

    insertion_sort<int>(a_int, (s_size_t)(sizeof(a_int)/sizeof(a_int[0])));
    insertion_sort<float>(a_float, (s_size_t)(sizeof(a_float)/sizeof(a_float[0])));
    insertion_sort<char>(a_char, (s_size_t)(sizeof(a_char)/sizeof(a_char[0])));

    show_array<int>(a_int, (s_size_t)(sizeof(a_int)/sizeof(a_int[0])), "Int arr after sort");
    show_array<float>(a_float, (s_size_t)(sizeof(a_float)/sizeof(a_float[0])), "float arr after sort");
    show_array<char>(a_char, (s_size_t)(sizeof(a_char)/sizeof(a_char[0])), "char arr after sort");
}