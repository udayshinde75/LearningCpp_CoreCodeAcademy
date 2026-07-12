#include <stdio.h>

int max_int(int a, int b)
{
    if (a > b)  
    {
        return a;
    }
    return b;
}

float max_float(float a, float b)
{
    if (a > b)  
    {
        return a;
    }
    return b;
}

#define MAX(a, b)   ((a) > (b) ? (a) : (b))