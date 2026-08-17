#include <iostream>
#include <map>
#include <string>

// std::map: sorted key-value container, unique keys, O(log n) operations
// internally implemented as a balanced BST (red-black tree)

template <typename K, typename V>
void show_map(const std::map<K, V>& m, const char* msg){
	std::cout << msg << std::endl;
	for(typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		std::cout << "  [" << it->first << "] = " << it->second << std::endl;
}

void map_creation_and_insert(void);
void map_access_and_find(void);
void map_iteration(void);
void map_erase_ops(void);
void map_size_ops(void);

int main(void){
	map_creation_and_insert();
	map_access_and_find();
	map_iteration();
	map_erase_ops();
	map_size_ops();
	return (0);
}

void map_creation_and_insert(void){
	// list initialization
	std::map<std::string, int> ages{
		{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}
	};
	show_map(ages, "ages (list-init):");

	// insert using operator[]
	ages["Dave"] = 28;

	// insert using insert() — returns pair<iterator, bool>
	std::pair<std::map<std::string, int>::iterator, bool> result;
	result = ages.insert(std::make_pair("Eve", 22));
	std::cout << "Eve inserted? " << result.second << std::endl;

	// duplicate key: insert fails, operator[] overwrites
	result = ages.insert(std::make_pair("Alice", 99));
	std::cout << "Alice re-insert? " << result.second << std::endl;	// false
	std::cout << "Alice age: " << ages["Alice"] << std::endl;			// still 25

	ages["Alice"] = 26;	// operator[] overwrites
	std::cout << "Alice age after []=: " << ages["Alice"] << std::endl;	// 26

	show_map(ages, "final ages:");
}

void map_access_and_find(void){
	std::map<int, std::string> codes{
		{200, "OK"}, {404, "Not Found"}, {500, "Server Error"}
	};

	// operator[] creates entry if key doesn't exist
	std::cout << "codes[200] = " << codes[200] << std::endl;

	// find() returns iterator, end() if not found
	std::map<int, std::string>::iterator it = codes.find(404);
	if(it != codes.end())
		std::cout << "found: " << it->first << " -> " << it->second << std::endl;

	it = codes.find(999);
	if(it == codes.end())
		std::cout << "999 not found" << std::endl;

	// count(): 0 or 1 for map (unique keys)
	std::cout << "count(200) = " << codes.count(200) << std::endl;
	std::cout << "count(999) = " << codes.count(999) << std::endl;
}

void map_iteration(void){
	std::map<std::string, double> prices{
		{"apple", 1.50}, {"banana", 0.75}, {"cherry", 3.00}
	};

	// forward iteration (sorted by key)
	std::cout << "forward:" << std::endl;
	for(std::map<std::string, double>::iterator it = prices.begin();
		it != prices.end(); ++it)
		std::cout << "  " << it->first << ": " << it->second << std::endl;

	// reverse iteration
	std::cout << "reverse:" << std::endl;
	for(std::map<std::string, double>::reverse_iterator rit = prices.rbegin();
		rit != prices.rend(); ++rit)
		std::cout << "  " << rit->first << ": " << rit->second << std::endl;
}

void map_erase_ops(void){
	std::map<int, std::string> m{
		{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}
	};

	// erase by key
	m.erase(3);
	show_map(m, "after erase(3):");

	// erase by iterator
	std::map<int, std::string>::iterator it = m.find(2);
	if(it != m.end())
		m.erase(it);
	show_map(m, "after erase(iter to 2):");

	m.clear();
	std::cout << "after clear, size = " << m.size() << std::endl;
}

void map_size_ops(void){
	std::map<char, int> m{{'a', 1}, {'b', 2}, {'c', 3}};
	std::cout << "size = " << m.size() << std::endl;
	std::cout << "empty? " << m.empty() << std::endl;
}
