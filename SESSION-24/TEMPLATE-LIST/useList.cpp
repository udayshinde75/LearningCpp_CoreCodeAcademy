#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include "list.hpp"

using namespace MYLIST;

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

    assert(pList->getStart(data) == Status::LIST_EMPTY); 
    assert(pList->getEnd(data) == Status::LIST_EMPTY);
    assert(pList->popStart(data) == Status::LIST_EMPTY);
    assert(pList->popEnd(data) == Status::LIST_EMPTY);
    assert(pList->removeStart() == Status::LIST_EMPTY);
    assert(pList->removeEnd() == Status::LIST_EMPTY);
    assert(pList->size() == 0);

    for(data = 10; data <= 50; data += 10)
        assert(pList->insertStart(data) == Status::SUCCESS);   
    std::cout << "After insert_start():" << std::endl << *pList; 

    for(data = 60; data <= 100; data += 10)
        assert(pList->insertEnd(data) == Status::SUCCESS); 
    std::cout << "After insert_end():" << std::endl << *pList; 

    assert(pList->insertAfter(-100, 1000) == Status::INVALID_DATA); 
    assert(pList->insertAfter(10, 1000) == Status::SUCCESS); 
    std::cout << "After insert_after():" << std::endl << *pList; 

    assert(pList->insertBefore(-100, 1000) == Status::INVALID_DATA); 
    assert(pList->insertBefore(10, 2000) == Status::SUCCESS); 
    std::cout << "After insert_before():" << std::endl << *pList; 

    assert(pList->getStart(data) == Status::SUCCESS); 
    std::cout << "Start Data:" << data << std::endl; 
    std::cout << "After get_start():" << std::endl << *pList; 

    assert(pList->getEnd(data) == Status::SUCCESS); 
    std::cout << "End Data:" << data << std::endl; 
    std::cout << "After get_end():" << std::endl << *pList; 

    assert(pList->popStart(data) == Status::SUCCESS); 
    std::cout << "Start Data:" << data << std::endl; 
    std::cout << "After pop_start():" << std::endl << *pList; 

    assert(pList->popEnd(data) == Status::SUCCESS); 
    std::cout << "End Data:" << data << std::endl; 
    std::cout << "After pop_end():" << std::endl << *pList; 

    assert(pList->removeStart() == Status::SUCCESS); 
    std::cout << "After remove_start():" << std::endl << *pList; 

    assert(pList->removeEnd() == Status::SUCCESS); 
    std::cout << "After remove_end():" << std::endl << *pList; 

    assert(pList->removeData(-1000) == Status::INVALID_DATA); 
    assert(pList->removeData(10) == Status::SUCCESS); 

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

