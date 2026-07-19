#include <cstdio> 
#define _CRT_RAND_S 
#include <cstdlib> 
#include <ctime> 

typedef long long int s_size_t; 

void insertion_sort(int* a, s_size_t N); 
void input_array(int* a, s_size_t N); 
void output_array(int* a, s_size_t N, const char* msg); 

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "UsagerError:%s number_of_ints\n", argv[0]); 
        exit(EXIT_FAILURE); 
    }

    s_size_t N = atoll(argv[1]); 
    if(N <= 0)
    {
        fprintf(stderr, "UsageError: Number of ints must be positive\n"); 
        exit(EXIT_FAILURE); 
    }

    int* a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    input_array(a, N); 
    //output_array(a, N, "Before sort:"); 
    time_t t_start = time(0); 
    insertion_sort(a, N); 
    time_t t_end = time(0); 
    //output_array(a, N, "After sort:"); 

    time_t t_delta = t_end - t_start; 
    printf("Physical time for sorting function:%ld\n", t_delta); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
}

void insertion_sort(int* a, s_size_t N)
{
    s_size_t i, j; 
    int key; 

    for(j = 1; j < N; ++j)
    {
        key = a[j]; 
        i = j - 1; 
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i]; 
            i = i - 1; 
        }

        a[i+1] = key; 
    }
}

void input_array(int* a, s_size_t N)
{
    s_size_t i; 
    unsigned int num; 

    for(i = 0; i < N; ++i)
    {
        rand_r(&num); 
        a[i] = num; 
    }
}

void output_array(int* a, s_size_t N, const char* msg)
{
    if(msg)
        puts(msg); 

    s_size_t i; 

    for(i = 0; i < N; ++i)
        printf("arr[%lld]:%d\n", i, a[i]); 
}