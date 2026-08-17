#include <iostream>
#include <cassert>

class list;

class node {
    friend class list;
    friend std::ostream& operator<<(std::ostream& os, const list& list_object);
    private:
        int data;
        node* prev;
        node* next;
        node(int _data = 0) : data(_data), next(nullptr), prev(nullptr) {}
};

class list {
    friend std::ostream& operator<<(std::ostream& os, const list& list_object);
    public:
        list() : head_node(new node)
        {
            head_node->next = head_node;
            head_node->prev = head_node;
        }

        ~list()
        {
            node* run = head_node->next;
            node* run_next;

            while (run != head_node)
            {
                run_next = run->next;
                delete run;
                run = run_next;
            }
            delete head_node;
            head_node = nullptr;
        }

        void insert_start(int new_data)
        {
            generic_insert(head_node, new node(new_data), head_node->next);
        }

        void insert_end(int new_data)
        {
            generic_insert(head_node->prev, new node(new_data), head_node);
        }

        class iterator
        {
            public:
                iterator(node* _current_node) : current_node(_current_node)
                {

                }

                iterator& operator++()
                {
                    current_node = current_node->next;
                    return *this;
                }

                iterator& operator--()
                {
                    current_node = current_node->prev;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator temp(current_node);
                    current_node = current_node->next;
                    return temp;
                }

                iterator operator--(int)
                {
                    iterator temp(current_node);
                    current_node = current_node->prev;
                    return temp;
                }

                bool operator==(const iterator& other)
                {
                    return (current_node == other.current_node);
                }

                bool operator!=(const iterator& other)
                {
                    return (current_node != other.current_node);
                }

                int operator*()
                {
                    return current_node->data;
                }
            private:
                node* current_node;
        };

        iterator begin()
        {
            return iterator(head_node->next);
        }

        iterator end()
        {
            return iterator(head_node);
        }
    private:
        node* head_node;
        static void generic_insert(node* start_node, node* mid_node, node* end_node)
        {
            mid_node->next = end_node;
            mid_node->prev = start_node;
            start_node->next = mid_node;
            end_node->prev = mid_node;
        }

        static void generic_delete(node* delete_node)
        {
            delete_node->prev->next = delete_node->next;
            delete_node->next->prev = delete_node->prev;
            delete delete_node;
        }

        node* search_node(int data)
        {
            for(node* run = head_node->next; run != head_node; run = run->next)
                if (run->data == data)
                {
                    return run;
                }
            return nullptr;
        }
};

std::ostream& operator<<(std::ostream& os, const list& list_object)
{
    os << "[START]<->";
    node* run = list_object.head_node->next;
    while (run != list_object.head_node)
    {
        os << "[" << run->data << "]<->";
        run = run->next;
    }
    os << "[END]" << std::endl;
    return os;
}

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    list L;
    for (int data = 10; data <= 50; data+=10)
    {
        std::cout << "Inserting data : " << data << std::endl; 
        L.insert_end(data);
    }
    
    std::cout << "List Iterator : " << std::endl;

    for(list::iterator iter = L.begin();iter != L.end();++iter)
    {
        std::cout << "*iter : " << *iter << std::endl;
    }

    std::cout << "L:" << L << std::endl;
}

