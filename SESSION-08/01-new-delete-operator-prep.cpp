#include <cstdio>
#include <cstdlib>

struct Date
{
    int day;
    int month;
    int year;

};


void test();

int main(void)
{
    test();
    return EXIT_SUCCESS;
}

void test()
{
    int* ptr = NULL;

    struct Date* dateptr = NULL;

    ptr = (int*)malloc(sizeof(int));
    dateptr = (struct Date*)malloc(sizeof(struct Date));

    if (NULL == ptr || NULL == dateptr)
    {
        exit(EXIT_FAILURE);
    }

    *ptr = 100;
    dateptr->day = 24;
    dateptr->month = 2;
    dateptr->year = 2345;

    printf("*ptr = %d, %d/%d/%d\n", *ptr, dateptr->day, dateptr->month, dateptr->year);

    free(ptr);
    ptr = NULL;
    free(dateptr);
    dateptr = NULL;
    

}