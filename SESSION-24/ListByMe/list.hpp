#pragma once

#include <iostream>
#include <cstdint>

namespace MYLIST {
    enum class Status : uint8_t {
        SUCCESS,
        INVALID_DATA,
        LIST_EMPTY
    };

    class node;

    using data_t = int;
    using status_t = Status;
    using len_t = unsigned long long;

    class list {
        public:
            list();
            ~list();

            // Insert Functions
            status_t insertStart(data_t newData);
            status_t insertEnd(data_t newData);
            status_t insertAfter(data_t existingData, data_t newData);
            status_t insertBefore(data_t existingData, data_t newData);

            // Get & Pop functions
            status_t getStart(data_t& startData) const;
            status_t getEnd(data_t& endData) const;
            status_t popEnd(data_t& endData);
            status_t popStart(data_t& startData);

            // Remove functions
            status_t removeStart();
            status_t removeEnd();
            status_t removeData(data_t rData);

            // Misc
            bool find(const data_t& searchData) const;
            bool empty() const;
            len_t size() const;

            // cout
            friend std::ostream& operator<<(std::ostream& os, const list& listObject);

        private:
            node* headNode;
            static void genericInsert(node* startNode, node* midNode, node* endNode);
            static void genericDelete(node* deleteNode);
            node* searchNode(const data_t& searchData) const;
    };
}