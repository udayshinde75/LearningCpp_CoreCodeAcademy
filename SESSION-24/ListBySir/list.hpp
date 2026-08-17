#ifndef _LIST_HPP 
#define _LIST_HPP 

#include <iostream>     // for std::ostream

//  Global constants (instead of symbolic constants in C)
const int SUCCESS = 1;          //  #define SUCCESS 1 
const int INVALID_DATA = -1;    //  #define INVALID_DATA    (-2) 
const int LIST_EMPTY = -2;       //  #define LIST_EMPTY      (-3)

//  Typedef 
typedef int data_t;     //  In modern C++   using data_t = int; 
typedef int status_t; 
typedef unsigned long long len_t; 

class node 
{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
    private: 
        data_t data; 
        node* prev; 
        node* next; 

        node(int _data = 0); 
}; 

class list 
{
    private: 
        //  Data 
        node* head_node; 

        static void generic_insert(node* start_node, node* mid_node, node* end_node); 
        static void generic_delete(node* delete_node); 
        node* search_node(data_t search_data) const; 

    public: 
        //  create_list() 
        list(); 
        //  destroy_list() 
        ~list(); 

        //  Insert functions 
        status_t insert_start(data_t new_data); 
        status_t insert_end(data_t new_data); 
        status_t insert_after(data_t existing_data, data_t new_data); 
        status_t insert_before(data_t existing_data, data_t new_data); 

        //  Get & Pop functions 
        status_t get_start(data_t* p_start_data) const; 
        status_t get_end(data_t* p_end_data) const; 
        status_t pop_start(data_t* p_start_data); 
        status_t pop_end(data_t* p_end_data); 

        //  Remove functions 
        status_t remove_start(); 
        status_t remove_end(); 
        status_t remove_data(data_t r_data); 
        
        //  Misc 
        bool find(data_t search_data) const; 
        bool empty() const; 
        len_t size() const; 

        //  show_list() -> cout operator overload function 
        friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
}; 




#endif  //  _LIST_HPP 