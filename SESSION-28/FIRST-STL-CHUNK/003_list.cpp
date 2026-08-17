#include <iostream>
#include <list>
#include <cstdlib>

template <typename T>
void show_list(const std::list<T>& lst, const char* msg){
	std::cout << msg << std::endl;
	for(typename std::list<T>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void list_creation_ops(void);
void list_all_iterators(void);
void list_size_assignment_swap(void);
void list_addition_ops(void);
void list_access_ops(void);
void list_erase_ops(void);
void list_specific_ops(void);

int main(void){
	list_creation_ops();
	list_all_iterators();
	list_size_assignment_swap();
	list_addition_ops();
	list_access_ops();
	list_erase_ops();
	list_specific_ops();
	return (0);
}

void list_creation_ops(void){
	std::list<int> l1;						// empty
	std::list<int> l2{10, 20, 30, 40, 50};	// list-initialized
	std::list<int> l3(l2);					// copy
	std::list<int> l4(5, 100);				// 5 elements, all 100
	std::list<int> l5(l2.begin(), l2.end());

	show_list(l1, "l1 (empty):");
	show_list(l2, "l2 (list-init):");
	show_list(l3, "l3 (copy):");
	show_list(l4, "l4 (5x100):");
	show_list(l5, "l5 (range):");
}

void list_all_iterators(void){
	std::list<int> lst{10, 20, 30, 40, 50};

	std::cout << "forward: ";
	for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "reverse: ";
	for(std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "const forward: ";
	for(std::list<int>::const_iterator cit = lst.begin(); cit != lst.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
}

void list_size_assignment_swap(void){
	std::list<int> l1{1, 2, 3};
	std::list<int> l2{10, 20, 30, 40, 50};

	std::cout << "l1.size() = " << l1.size() << std::endl;
	std::cout << "l1.empty() = " << l1.empty() << std::endl;

	show_list(l1, "l1 before swap:");
	show_list(l2, "l2 before swap:");
	l1.swap(l2);
	show_list(l1, "l1 after swap:");
	show_list(l2, "l2 after swap:");

	l2.assign({100, 200, 300});
	show_list(l2, "l2 after assign:");
}

void list_addition_ops(void){
	std::list<int> lst;

	lst.push_back(30);
	lst.push_back(40);
	lst.push_front(20);
	lst.push_front(10);
	show_list(lst, "after push_back/push_front:");

	// insert before position
	std::list<int>::iterator it = lst.begin();
	++it; ++it;	// points to 30
	lst.insert(it, 25);
	show_list(lst, "after insert 25 before 30:");

	lst.emplace_back(50);
	lst.emplace_front(5);
	show_list(lst, "after emplace_back/front:");
}

void list_access_ops(void){
	std::list<int> lst{10, 20, 30, 40, 50};

	// list does NOT support operator[] or at() — no random access
	std::cout << "front = " << lst.front() << std::endl;
	std::cout << "back = " << lst.back() << std::endl;
}

void list_erase_ops(void){
	std::list<int> lst{10, 20, 30, 40, 50, 60};

	lst.pop_back();
	lst.pop_front();
	show_list(lst, "after pop_back and pop_front:");

	std::list<int>::iterator it = lst.begin();
	++it;	// points to 30
	lst.erase(it);
	show_list(lst, "after erase(30):");

	lst.clear();
	std::cout << "after clear, size = " << lst.size() << std::endl;
}

void list_specific_ops(void){
	// list has member functions that other containers don't
	std::list<int> lst{50, 10, 40, 20, 30, 10, 20};

	lst.sort();
	show_list(lst, "after sort:");

	lst.unique();	// removes consecutive duplicates (must be sorted first)
	show_list(lst, "after unique:");

	lst.reverse();
	show_list(lst, "after reverse:");

	std::list<int> lst2{5, 15, 25, 35, 45};
	lst.merge(lst2);	// both must be sorted; lst2 becomes empty
	show_list(lst, "after merge with lst2:");
	std::cout << "lst2.size() after merge = " << lst2.size() << std::endl;

	std::list<int> lst3{1, 2, 3, 4, 5, 3, 3, 6};
	lst3.remove(3);		// removes ALL elements equal to 3
	show_list(lst3, "after remove(3):");
}
