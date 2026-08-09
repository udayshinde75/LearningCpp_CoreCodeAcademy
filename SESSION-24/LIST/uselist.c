#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "list.h"

void test_list(void); 

int main(void)
{
    test_list(); 
    return (EXIT_SUCCESS); 
}

void test_list(void)
{
    list_t* p_list = NULL; 
    data_t data; 
    status_t status; 

    p_list = create_list(); 
    show_list(p_list, "List just after creation:"); 

    assert(get_start(p_list, &data) == LIST_EMPTY); 
    assert(get_end(p_list, &data) == LIST_EMPTY); 
    assert(pop_start(p_list, &data) == LIST_EMPTY); 
    assert(pop_end(p_list, &data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(get_length(p_list) == 0); 

    for(data = 10; data <= 50; data += 10)
    {
        status = insert_start(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "after insert_start():"); 

    for(data = 60; data <= 100; data += 10)
    {
        status = insert_end(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "after insert_end():"); 

    status = insert_after(p_list, -100, 1000); 
    assert(status == INVALID_DATA); 

    status = insert_after(p_list, 10, 1000); 
    assert(status == SUCCESS); 

    show_list(p_list, "After insert_after():"); 

    status = insert_before(p_list, -100, 2000); 
    assert(status == INVALID_DATA); 

    status = insert_before(p_list, 10, 2000); 
    assert(status == SUCCESS); 

    show_list(p_list, "After insert_before():"); 

    status = get_start(p_list, &data); 
    assert(status == SUCCESS); 

    printf("start data:%d\n", data); 
    show_list(p_list, "After get_start():"); 

    status = get_end(p_list, &data); 
    assert(status == SUCCESS); 

    printf("end data:%d\n", data); 
    show_list(p_list, "After get_end():"); 

    status = pop_start(p_list, &data); 
    assert(status == SUCCESS); 

    printf("Poped start data:%d\n", data); 
    show_list(p_list, "After pop_start():"); 

    status = pop_end(p_list, &data); 
    assert(status == SUCCESS); 

    printf("Poped end data:%d\n", data); 
    show_list(p_list, "After pop_end():"); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "After remove_start():"); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    
    status = remove_data(p_list, -100); 
    assert(status == INVALID_DATA); 

    status = remove_data(p_list, 10); 
    assert(status == SUCCESS); 
    show_list(p_list, "after remove_data():"); 

    status = find(p_list, 70); 
    assert(status == TRUE); 
    puts("70 exists in list");

    status = find(p_list, -100); 
    assert(status == FALSE); 
    puts("-100 does not exist in list"); 

    len_t length = get_length(p_list); 
    printf("length of list : %llu\n", length); 

    status = is_list_empty(p_list); 
    assert(status == FALSE); 
    puts("List is not empty now"); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 
    puts("List is destroyed successfully"); 

    puts("Unit testing of doubly circular linked list"); 
}


