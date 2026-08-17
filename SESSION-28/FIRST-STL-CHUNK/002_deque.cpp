#include <iostream>
#include <cstdlib>
#include <deque>

class Point3d{
private: 
	double x, y, z; 
public: 
	Point3d(double init_x, double init_y, double init_z) : x(init_x), y(init_y), z(init_z) {} 
	Point3d() : x(0.0), y(0.0), z(0.0) {}
	friend std::ostream& operator<<(std::ostream& os, const Point3d& pt); 
}; 

 std::ostream& operator<<(std::ostream& os, const Point3d& pt){
 	os << "(" << pt.x << "," << pt.y << "," << pt.z << ")" << std::endl; 
 	return os; 
 }

template <typename T>
void print_deque_by_index(std::deque<T>& D, const char* msg){
	std::cout << msg << std::endl; 
	for(typename std::deque<T>::size_type i = 0; i != D.size(); ++i)
		std::cout << "D[" << i << "]:" << D[i] << std::endl; 
	std::cout << "------------[END]------------" << std::endl; 
}

template <typename T> 
void print_deque_by_iterator(std::deque<T>& D, const char* msg){
	std::cout << msg << std::endl; 
	for(typename std::deque<T>::iterator iter = D.begin(); iter != D.end(); ++iter){
		std::cout << "*iter=" << *iter << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl; 
}

void deque_of_different_types(); 
void deque_all_iterators(); 
void deque_size_and_swap(); 
void deque_relational_operators(); 
void deque_addition_ops(); 
void deque_access_ops(); 
void deque_deletion_ops(); 

int main(){
	deque_of_different_types(); 
	deque_all_iterators(); 
	deque_size_and_swap(); 
	deque_relational_operators();
	deque_addition_ops();
	deque_access_ops(); 
	deque_deletion_ops(); 

	return 0; 
}

void deque_of_different_types(){
	std::deque<int> D_int; 
	std::deque<char> D_char{'a', 'b', 'c', 'd'}; 
	std::deque<Point3d> D_points{{1.1,2.2,3.3},{2.2,3.3,4.4},{5.5, 6.6, 7.7}}; 

	print_deque_by_index(D_int, "Empty Deuque of integers"); 
	print_deque_by_iterator(D_char, "d eque of chars"); 
	print_deque_by_iterator(D_points, "deque of Point3d"); 

	std::deque<int> D1_int(5);
	// Point3d -> default  
	std::deque<Point3d> D2_points(5);
	// Point3d -> parameterized ctor  
	std::deque<Point3d> D3_points(5, {1.1, 2.2, 3.3}); 
	std::deque<char> D4_char(5, 'A'); 

	print_deque_by_index(D1_int, "deque with 5 0's"); 
	print_deque_by_index(D2_points, "deque with 5 default initialized Point3d objects"); 
	print_deque_by_index(D3_points, "deque with 5 explicitly initialized Point3d objects"); 
	print_deque_by_index(D4_char, "deque with 5 chars, all A's"); 

	// copy constructor 
	std::deque<Point3d> D5_points(D3_points); 
	print_deque_by_index(D5_points, "deque constructor by another deque"); 
}

void deque_all_iterators(){
	std::deque<int> D{100, 200, 300, 400, 500}; 

	// RW + forward iterator
	std::cout << "R/W and Forward moving iterator:" << std::endl; 
	for(std::deque<int>::iterator iter = D.begin(); iter != D.end(); ++iter){
		*iter = *iter + 5; 
		std::cout << "*iter = " << *iter << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl;

	// R only forward iterator 
	std::cout << "R only and Forward moving iterator" << std::endl; 
	for(std::deque<int>::const_iterator c_iter = D.cbegin(); c_iter != D.cend(); ++c_iter){
		// 	*iter = *iter + 5; //CTE 
		std::cout << "*c_iter = " << *c_iter << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl;

	// R/W & backward moving 
	std::cout << "R/W and backward moving iterator" << std::endl; 
	for(std::deque<int>::reverse_iterator iter = D.rbegin(); iter != D.rend(); ++iter){
		*iter = *iter - 5; 
		std::cout << "*iter = " << *iter << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl;
	// R only and backward moving 
	std::cout << "Ronly and backward moving" << std::endl; 
	for(std::deque<int>::const_reverse_iterator iter = D.crbegin(); iter != D.crend(); ++iter){
		//	*iter = *iter + 5; 	// CTE 
		std::cout << "*iter = " << *iter << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl;	
}

void deque_size_and_swap(){
	std::deque<int> D1 {100, 200, 300, 400, 500};
	std::deque<int> D2 {-1, -2, -3}; 
	std::deque<int> D3; 

	std::cout 	<< "D1.size():" << D1.size() << std::endl 
				<< "D1.max_size():" << D1.max_size() << std::endl; 

	if(!D1.empty())
		std::cout << "D1 is not empty" << std::endl; 

	if(D3.empty())
		std::cout << "D3 is empty" << std::endl; 

	print_deque_by_index(D1, "D1 before swap"); 
	print_deque_by_index(D2, "D2 before swap"); 
	D1.swap(D2); 	// std::swap(D1, D2); 
	print_deque_by_index(D1, "D1 after swap"); 
	print_deque_by_index(D2, "D2 after swap"); 

	print_deque_by_index(D3, "D3 before assignment"); 
	D3 = D2; 
	print_deque_by_index(D3, "D3 after assignment 1"); 
	D3 = D2;
	
	std::deque<int> D4 {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000}; 
	std::deque<int>::iterator iter_b = D4.begin() + 1; 
	std::deque<int>::iterator iter_e = D4.end() - 1; 
	D3.assign(iter_b, iter_e); 
	print_deque_by_index(D3, "D3 after assignment by iterator"); 
	D3.assign(5, 73); 
	print_deque_by_index(D3, "D3 after assigned by 5 times 73"); 
	D3.assign({2, 3, 5, 7, 11, 13, 17, 19}); 
	print_deque_by_index(D3, "D3 assigned by primes between 1 to 20");

}

void deque_relational_operators(){
	std::deque<int> D1 {10, 20, 30, 40}; 
	std::deque<int> D2 {10, 200}; 

	if(D2 > D1)
		std::cout << "D2 > D1" << std::endl; 

	D1.assign({10, 20, 30, 40}); 
	D2.assign({10, 20, 30, 40, 50}); 
	if(D2 > D1)
		std::cout << "D2 > D1" << std::endl; 

	if(D1 != D2)
		std::cout << "D1 != D2" << std::endl; 

	D1.assign({10, 20, 30}); 
	D2.assign({10, 20, 30}); 
	if(D1 == D2)
		std::cout << "D1 == D2" << std::endl; 

	std::cout << "------------[END]------------" << std::endl;	
}

void deque_addition_ops(){
	std::deque<int> D; 
	
	//	push_back & push_front
	for(int i = 0; i < 3; ++i)
		D.push_back(i); 
	print_deque_by_index(D, "after push_back"); 
	for(int i = 3; i < 6; ++i)
		D.push_front(i); 
	print_deque_by_index(D, "after push_front"); 
	
	std::deque<int>::iterator iter = D.begin();
	iter = D.insert(iter, 300);
	std::cout << "*iter :" << std::endl; 
	//	insert(p, t)
	//	insert(p, n, t)
	//	insert(p, b, e)
	//	insert(p, {})

	iter = D.insert(iter+3, 100); 
	std::cout << "*iter = " << *iter << std::endl; 
	print_deque_by_index(D, "after insert(p, t)"); 

	iter = D.insert(iter+2, 200); 
	print_deque_by_index(D, "after insert(p, t)"); 

	iter = D.insert(iter-1, 4, -10); 
	print_deque_by_index(D, "after insert(p, n, t)"); 

	std::deque<int> E {1000, 2000, 3000, 4000, 5000, 6000, 7000}; 
	std::deque<int>::iterator b_iter = E.begin(), e_iter = E.end(); 
	iter = D.insert(iter, b_iter+1, e_iter-1); 
	print_deque_by_index(D, "after D.insert(p, b, e)"); 

	iter = D.insert(iter, {12, 14, 16, 18}); 
	print_deque_by_index(D, "after D.insert(p, {})"); 

	std::deque<Point3d> P; 

	P.push_back({1.1, 2.2, 3.3}); 
	P.push_front({0.0, 0.0, 0.0}); 
	print_deque_by_index(P, "after push_back and front"); 

	P.emplace_back(10.5, 11.5, 12.5); 
	P.emplace_front(-10.5, -11.5, -12.5); 
	print_deque_by_index(P, "after emplace_back and emplace_front"); 

}

void deque_access_ops(){
	std::deque<int> D{10, 20, 30, 40, 50, 60, 70, 80}; 
	
	int& ref_back = D.back(); 
	int& ref_front = D.front(); 

	std::cout << "Front element:" << ref_front << std::endl << "Back element:" << ref_back << std::endl; 

	std::cout << "Using D.at(0):" << D.at(0) << std::endl; 

	try{
		std::cout << D.at(500) << std::endl; 
	}catch(std::out_of_range& ref){
		std::cout << ref.what() << std::endl; 
	}
	std::cout << "------------[END]------------" << std::endl;
}

void deque_deletion_ops(){
	std::deque<int> D {10, 20, 30, 40, 50, 60, 70, 80}; 

	print_deque_by_index(D, "before any deletion"); 
	D.pop_back(); 
	D.pop_front(); 
	print_deque_by_index(D, "after pop_back and pop_front"); 

	std::deque<int>::iterator iter = D.begin();
	iter = D.erase(iter); 
	print_deque_by_index(D, "after erase(p)"); 

	iter = D.begin(); 

	iter = D.erase(iter + 1, iter + D.size() - 2); 
	print_deque_by_index(D, "after erase(b, e)"); 

	D.clear(); 
	print_deque_by_index(D, "after deleting all elements"); 
}

/* 
[0]	[0]	[0]	[0]	[0]	[end]

[(0.0, 0.0, 0.0)]	[(0.0, 0.0, 0.0)]	[(0.0, 0.0, 0.0)]	[(0.0, 0.0, 0.0)]	[(0.0, 0.0, 0.0)]	[end]

['A']	['A']	['A']	['A']	['A']	[end]
*/  