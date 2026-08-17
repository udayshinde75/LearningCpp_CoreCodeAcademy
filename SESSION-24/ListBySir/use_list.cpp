#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include "list.hpp"

void test_list(); 

int main() 
{
    test_list();
    return EXIT_SUCCESS; 
}

void test_list() 
{
    list* pList = new list; 
    data_t data; 
    status_t status; 

    std::cout << "List just after creation" << std::endl << *pList; 

    assert(pList->get_start(&data) == LIST_EMPTY); 
    assert(pList->get_end(&data) == LIST_EMPTY);
    assert(pList->pop_start(&data) == LIST_EMPTY);
    assert(pList->pop_end(&data) == LIST_EMPTY);
    assert(pList->remove_start() == LIST_EMPTY);
    assert(pList->remove_end() == LIST_EMPTY);
    assert(pList->size() == 0);

    for(data = 10; data <= 50; data += 10)
        assert(pList->insert_start(data)); 
    std::cout << "After insert_start():" << std::endl << *pList; 

    for(data = 60; data <= 100; data += 10)
        assert(pList->insert_end(data)); 
    std::cout << "After insert_end():" << std::endl << *pList; 

    assert(pList->insert_after(-100, 1000) == INVALID_DATA); 
    assert(pList->insert_after(10, 1000) == SUCCESS); 
    std::cout << "After insert_after():" << std::endl << *pList; 

    assert(pList->insert_before(-100, 1000) == INVALID_DATA); 
    assert(pList->insert_before(10, 2000) == SUCCESS); 
    std::cout << "After insert_before():" << std::endl << *pList; 

    assert(pList->get_start(&data)); 
    std::cout << "Start Data:" << data << std::endl; 
    std::cout << "After get_start():" << std::endl << *pList; 

    assert(pList->get_end(&data)); 
    std::cout << "End Data:" << data << std::endl; 
    std::cout << "After get_end():" << std::endl << *pList; 

    assert(pList->pop_start(&data)); 
    std::cout << "Start Data:" << data << std::endl; 
    std::cout << "After pop_start():" << std::endl << *pList; 

    assert(pList->pop_end(&data)); 
    std::cout << "End Data:" << data << std::endl; 
    std::cout << "After pop_end():" << std::endl << *pList; 

    assert(pList->remove_start()); 
    std::cout << "After remove_start():" << std::endl << *pList; 

    assert(pList->remove_end()); 
    std::cout << "After remove_end():" << std::endl << *pList; 

    assert(pList->remove_data(-1000) == INVALID_DATA); 
    assert(pList->remove_data(10) == SUCCESS); 

    assert(pList->find(-1000) == false); 
    std::cout << "-1000 is not present in list" << std::endl; 

    assert(pList->find(70) == true); 
    std::cout << "70 is present in list" << std::endl; 

    assert(pList->empty() == false); 
    std::cout << "List is not empty" << std::endl; 

    std::cout << "Number of elements in list:" << pList->size() << std::endl; 

    delete pList; 
    pList = 0;  

    std::cout << "List is destroyed successfully" << std::endl; 
    std::cout << "Unit testing of list is successful" << std::endl; 
}

