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
    int a_int[] = {100, 49, 20, 50, 99};
    float a_float[] = {4.5, 2.9, 4.1, 9.9, 3.3};
    char a_char[] = {'C', 'o', 'r', 'e', 'c', 'o', 'd', 'e'}; 

    show_array<int>(a_int, (s_size_t)(sizeof(a_int) / sizeof(a_int[0])), "Int arr Before sort : ");
    show_array<float>(a_float, (s_size_t)(sizeof(a_float) / sizeof(a_float[0])), "float arr Before sort : ");
    show_array<char>(a_char, (s_size_t)(sizeof(a_char) / sizeof(a_char[0])), "Int arr Before sort : ");

    quick_sort<int>(a_int, 0, (s_size_t)(sizeof(a_int) / sizeof(a_int[0])) - 1);
    quick_sort<float>(a_float, 0, (s_size_t)(sizeof(a_float) / sizeof(a_float[0]))-1);
    quick_sort<char>(a_char, 0, (s_size_t)(sizeof(a_char) / sizeof(a_char[0]))-1);

    show_array<int>(a_int, (s_size_t)(sizeof(a_int) / sizeof(a_int[0])), "Int arr after sort : ");
    show_array<float>(a_float, (s_size_t)(sizeof(a_float) / sizeof(a_float[0])), "float arr after sort : ");
    show_array<char>(a_char, (s_size_t)(sizeof(a_char) / sizeof(a_char[0])), "Int arr after sort : ");
}