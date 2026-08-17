#include <iostream>
#include "list.hpp"

namespace MYLIST {
    class node {
        friend class list;
        friend std::ostream& operator<<(std::ostream& os, const list& listobject);

        private:
            data_t data;
            node* prev = nullptr;
            node* next = nullptr;

            node(int _data = 0) : data(_data) {}
    };

    // Helper functions of class list
    void list::genericInsert(node* startNode, node* midNode, node* endNode) { 
        midNode->next = endNode;
        midNode->prev = startNode;
        startNode->next = midNode;
        endNode->prev = midNode;
    }

    void list::genericDelete(node* deleteNode) {
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        delete deleteNode;
    }

    node* list::searchNode(const data_t& searchData) const {
        node* run = headNode->next;
        while (run != headNode)
        {
            if (run->data == searchData)
            {
                return run;
            }
            run = run->next;
        }
        return nullptr;
    }

    // Interface functions of class list
    list::list() : headNode(new node{0}) {
        headNode->prev = headNode;
        headNode->next = headNode;
    }

    list::~list() {
        node* run = headNode->next;
        node* run_next;

        while (run != headNode)
        {
            run_next = run->next;
            delete run;
            run = run_next;
        }
        
        delete headNode;
        headNode = nullptr;
    }

    status_t list::insertStart(data_t newData) {
        genericInsert(headNode, new node{newData}, headNode->next);
        return Status::SUCCESS;
    }
    status_t list::insertEnd(data_t newData) {
        genericInsert(headNode->prev, new node{newData}, headNode);
        return Status::SUCCESS;
    }
    status_t list::insertAfter(data_t existingData, data_t newData) {
        node* existingNode = searchNode(existingData);
        if (!existingNode)
        {
            return Status::INVALID_DATA;
        }
        genericInsert(existingNode, new node{newData}, existingNode->next);
        return Status::SUCCESS;
    }
    status_t list::insertBefore(data_t existingData, data_t newData) {
        node* existingNode = searchNode(existingData);
        if (!existingNode)
        {
            return Status::INVALID_DATA;
        }
        genericInsert(existingNode->prev, new node{newData}, existingNode);
        return Status::SUCCESS;
    }

    // Get & Pop functions
    status_t list::getStart(data_t& startData) const {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        startData = headNode->next->data;
        return Status::SUCCESS;
    }
    status_t list::getEnd(data_t& endData) const {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        endData = headNode->prev->data;
        return Status::SUCCESS;
    }
    status_t list::popEnd(data_t& endData) {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        endData = headNode->prev->data;
        genericDelete(headNode->prev);
        return Status::SUCCESS;
    }
    status_t list::popStart(data_t& startData) {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        startData = headNode->next->data;
        genericDelete(headNode->next);
        return Status::SUCCESS;
    }

    // Remove functions
    status_t list::removeStart() {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        genericDelete(headNode->next);
        return Status::SUCCESS;
    }
    status_t list::removeEnd() {
        if (empty())
        {
            return Status::LIST_EMPTY;
        }
        genericDelete(headNode->prev);
        return Status::SUCCESS;
    }
    status_t list::removeData(data_t rData) {
        node* rNode = searchNode(rData);
        if (!rNode)
        {
            return Status::INVALID_DATA;
        }
        genericDelete(rNode);
        return Status::SUCCESS;
    }

    // Misc
    bool list::find(const data_t& searchData) const {
        node* existing_node = searchNode(searchData); 
        return existing_node != nullptr; 
    }
    bool list::empty() const {
        return (this->headNode->next == this->headNode && 
                this->headNode->prev == this->headNode); 
    }
    len_t list::size() const {
        len_t L = 0; 

        for(node* run = headNode->next; run != headNode; run = run->next)
            L += 1; 

        return L; 
    }

    std::ostream& operator<<(std::ostream& os, const list& listobject) {
        node* headNode = listobject.headNode;
        os << "[START]<->";
        for(node* run = headNode->next; run != headNode; run = run->next)
            os << "[" << run->data << "]<->"; 
        os << "[END]" << std::endl;

        return os;
    }
}