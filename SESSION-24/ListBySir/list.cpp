#include <iostream> 
#include "list.hpp"

//  Node ctor 
node::node(int _data) : data(_data), prev(0), next(0)
{
}

//  Helper functions of class list 
void list::generic_insert(node* start_node, node* mid_node, node* end_node)
{
    mid_node->next = end_node; 
    mid_node->prev = start_node; 
    start_node->next = mid_node; 
    end_node->prev = mid_node; 
}

void list::generic_delete(node* delete_node)
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    delete delete_node; 
}

node* list::search_node(data_t search_data) const 
{
    node* run = this->head_node->next; 
    while(run != this->head_node)
    {
        if(run->data == search_data)
            return run; 
        run = run->next; 
    }

    return 0; 
}

//  Interface functions of class list 

//  Ctor of list 
list::list() : head_node(new node)
{
    head_node->prev = head_node; 
    head_node->next = head_node; 
}

//  Dtor of list 
list::~list() 
{
    node* run = this->head_node->next; 
    node* run_next; 

    while(run != this->head_node)
    {
        run_next = run->next; 
        delete run; 
        run = run_next; 
    }

    delete head_node; 
    head_node = 0; 
}

status_t list::insert_start(data_t new_data)
{
    generic_insert(this->head_node, new node(new_data), this->head_node->next); 
    return SUCCESS; 
}

status_t list::insert_end(data_t new_data)
{
    generic_insert(this->head_node->prev, new node(new_data), this->head_node); 
    return SUCCESS; 
}

status_t list::insert_after(data_t existing_data, data_t new_data)
{
    node* existing_node = this->search_node(existing_data); 
    if(0 == existing_node)
        return INVALID_DATA; 
    generic_insert(existing_node, new node(new_data), existing_node->next); 
    return SUCCESS; 
}

status_t list::insert_before(data_t existing_data, data_t new_data)
{
    node* existing_node = search_node(existing_data); 
    if(0 == existing_node)
        return INVALID_DATA; 
    generic_insert(existing_node->prev, new node(new_data), existing_node); 
    return SUCCESS; 
}

status_t list::get_start(data_t* p_start_data) const 
{
    if(empty())
        return LIST_EMPTY; 
    *p_start_data = this->head_node->next->data; 
    return SUCCESS; 
}

status_t list::get_end(data_t* p_end_data) const 
{
    if(empty())
        return LIST_EMPTY; 
    *p_end_data = this->head_node->prev->data; 
    return SUCCESS; 
}

status_t list::pop_start(data_t* p_start_data) 
{
    if(empty())
        return LIST_EMPTY; 
    *p_start_data = this->head_node->next->data; 
    generic_delete(this->head_node->next); 
    return SUCCESS; 
}

status_t list::pop_end(data_t* p_end_data) 
{
    if(empty())
        return LIST_EMPTY; 
    *p_end_data = this->head_node->prev->data; 
    generic_delete(this->head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_start()
{
    if(empty())
        return LIST_EMPTY; 
    generic_delete(this->head_node->next); 
    return SUCCESS; 
}

status_t list::remove_end() 
{
    if(empty())
        return LIST_EMPTY; 
    generic_delete(this->head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_data(data_t r_data)
{
    node* r_node = search_node(r_data); 
    if(0 == r_node)
        return INVALID_DATA; 
    generic_delete(r_node); 
    return SUCCESS; 
}

bool list::find(data_t search_data) const 
{
    node* existing_node = search_node(search_data); 
    return existing_node != 0; 
}

bool list::empty() const 
{
    return (this->head_node->next == this->head_node && 
            this->head_node->prev == this->head_node); 
}

len_t list::size() const 
{
    len_t L = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next)
        L += 1; 

    return L; 
}

std::ostream& operator<<(std::ostream& os, const list& list_object)
{   
    node* head_node = list_object.head_node; 

    os << "[START]<->"; 
    for(node* run = head_node->next; run != head_node; run = run->next)
        os << "[" << run->data << "]<->"; 
    os << "[END]" << std::endl; 

    return os; 
}

