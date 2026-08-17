#include <iostream>
#include <string>
#include <utility>

// std::pair: holds two values of possibly different types
// foundation for map and multimap

void test_pair_creation(void);
void test_pair_comparison(void);
void test_pair_with_functions(void);

int main(void){
	test_pair_creation();
	test_pair_comparison();
	test_pair_with_functions();
	return (0);
}

void test_pair_creation(void){
	// direct construction
	std::pair<int, std::string> p1(1, "hello");
	std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;

	// make_pair (deduces types)
	std::pair<double, char> p2 = std::make_pair(3.14, 'A');
	std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

	// copy
	std::pair<int, std::string> p3(p1);
	std::cout << "p3: " << p3.first << ", " << p3.second << std::endl;

	// assignment
	p3.first = 42;
	p3.second = "world";
	std::cout << "p3 modified: " << p3.first << ", " << p3.second << std::endl;
}

void test_pair_comparison(void){
	// comparison is lexicographic: first compared first, then second
	std::pair<int, int> a(1, 10);
	std::pair<int, int> b(1, 20);
	std::pair<int, int> c(2, 5);

	std::cout << "(1,10) < (1,20) ? " << (a < b) << std::endl;	// true
	std::cout << "(1,10) < (2,5)  ? " << (a < c) << std::endl;	// true
	std::cout << "(1,10) == (1,10)? " << (a == a) << std::endl;	// true
}

// returning multiple values from a function
std::pair<int, bool> safe_divide(int a, int b){
	if(b == 0)
		return std::make_pair(0, false);
	return std::make_pair(a / b, true);
}

void test_pair_with_functions(void){
	std::pair<int, bool> result = safe_divide(10, 3);
	if(result.second)
		std::cout << "10 / 3 = " << result.first << std::endl;

	result = safe_divide(10, 0);
	if(!result.second)
		std::cout << "division by zero" << std::endl;
}
