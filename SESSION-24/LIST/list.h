#ifndef _LIST_H
#define _LIST_H

// Symbolic constants
#define SUCCESS         1
#define TRUE            1
#define FALSE           0
#define INVALID_LIST    -1
#define INVALID_DATA    -2
#define LIST_EMPTY      -3

// Typedefs
typedef int data_t;
typedef int status_t;
typedef unsigned long long len_t;
typedef struct node node_t;
typedef node_t list_t;

typedef struct node node_t;

// Data layout
struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

// Interface
list_t* create_list(void);
status_t destroy_list(list_t** pp_list);

// Insert
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t new_data, data_t existing_data);
status_t insert_before(list_t* p_list, data_t new_data, data_t existing_data);

// Get And Pop
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

// Remove functions
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

// Misc Functions
status_t find(list_t* p_list, data_t f_data);
len_t get_length(list_t* p_list);
status_t is_list_empty(list_t* p_list);
status_t show_list(list_t* p_list, const char* msg);

#endif // _LIST_H