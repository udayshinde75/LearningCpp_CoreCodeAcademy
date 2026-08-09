#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// helper function declaractions
static void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node);
static void generic_delete(node_t* p_delete_node);
static node_t* search_node(node_t* start_node, data_t search_data);

static node_t* get_node(data_t new_data);
static void* xmalloc(size_t size_in_bytes);

// function definations -----------------------
// Interface
list_t* create_list(void){
    list_t* p_list = NULL;
    p_list = get_node(0);
    p_list->prev = p_list;
    p_list->next = p_list;
    return (p_list);
}
status_t destroy_list(list_t** pp_list){
    if (pp_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    list_t* p_list = *pp_list;

    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    node_t* run = p_list->next;
    node_t* run_next;

    while (run != p_list)
    {
        run_next = run->next;
        free(run);
        run = run_next;
    }
    free(p_list);
    *pp_list = NULL;
    return (SUCCESS);
}

// Insert
status_t insert_end(list_t* p_list, data_t new_data) {
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    generic_insert(p_list->prev, get_node(new_data), p_list);

    return (SUCCESS);
}
status_t insert_start(list_t* p_list, data_t new_data) {
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    generic_insert(p_list, get_node(new_data), p_list->next);

    return (SUCCESS);
}
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }

    node_t* existing_node = search_node(p_list, existing_data);

    if (existing_node == NULL)
    {
        return (INVALID_DATA);
    }
    
    generic_insert(existing_node, get_node(new_data), existing_node->next);

    return (SUCCESS);
}
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    node_t* existing_node = search_node(p_list, existing_data);

    if (existing_node == NULL)
    {
        return (INVALID_DATA);
    }
    
    generic_insert(existing_node->prev, get_node(new_data), existing_node);

    return (SUCCESS);
}

// Get And Pop
status_t get_start(list_t* p_list, data_t* p_start_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    *p_start_data = p_list->next->data;

    return (SUCCESS);
}
status_t get_end(list_t* p_list, data_t* p_end_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    *p_end_data = p_list->prev->data;

    return (SUCCESS);
}
status_t pop_start(list_t* p_list, data_t* p_start_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    *p_start_data = p_list->next->data;

    generic_delete(p_list->next);

    return (SUCCESS);
}
status_t pop_end(list_t* p_list, data_t* p_end_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }

    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);

    return (SUCCESS);
}

// Remove functions
status_t remove_start(list_t* p_list){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    generic_delete(p_list->next);

    return (SUCCESS);
}
status_t remove_end(list_t* p_list){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (is_list_empty(p_list))
    {
        return (LIST_EMPTY);
    }
    
    generic_delete(p_list->prev);

    return (SUCCESS);
}
status_t remove_data(list_t* p_list, data_t r_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    node_t* existing_node = search_node(p_list, r_data);

    if (existing_node == NULL)
    {
        return (INVALID_DATA);
    }
    
    generic_delete(existing_node);

    return (SUCCESS);
}

// Misc Functions
status_t find(list_t* p_list, data_t f_data){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    node_t* find_node = search_node(p_list, f_data);

    return (find_node != NULL);
}
len_t get_length(list_t* p_list){
    len_t length = 0;
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }

    node_t* run = p_list->next;

    while (run != p_list)
    {
        length = length + 1;
        run = run->next;
    }
    
    return (length);
}
status_t is_list_empty(list_t* p_list){
    return (p_list->prev == p_list && p_list->next == p_list);
}
status_t show_list(list_t* p_list, const char* msg){
    if (p_list == NULL)
    {
        return (INVALID_LIST);
    }
    
    if (msg)
    {
        puts(msg);
    }
    
    printf("[START]<->");

    node_t* run = p_list->next;

    while (run != p_list)
    {
        printf("[%d]<->", run->data);
        run = run->next;
    }
    puts("[END]");

    return (SUCCESS);
}

// helper function definitions
static void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node){
    mid_node->next = end_node;
    mid_node->prev = start_node;
    start_node->next = mid_node;
    end_node->prev = mid_node;
}
static void generic_delete(node_t* p_delete_node){
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
}
static node_t* search_node(node_t* p_list, data_t search_data){
    node_t* run = NULL;
    run = p_list -> next;

    while (run != p_list)
    {
        if (run->data == search_data)
        {
            return (run);
        }
        run = run->next;
    }
    return (NULL);
}

static node_t* get_node(data_t new_data){
    node_t* p_new_node = NULL;

    p_new_node = (node_t*)xmalloc(sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;

    return (p_new_node);
}
static void* xmalloc(size_t size_in_bytes){
    void* ptr = NULL;
    ptr = malloc(size_in_bytes);
    if (NULL == ptr)
    {
        fprintf(stderr, "malloc() : fatal : out of memory\n");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}
// function definations -----------------------
