#include "list.hpp"

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _day, int _month, int _year) : day(_day), 
                                                month(_month), 
                                                year(_year){                                        
        }

        Date() : day(1), month(1), year(1970){
        }

        bool operator==(const Date& other){
            return day == other.day && month == other.month && year == other.year; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& date_object); 
}; 

std::ostream& operator<<(std::ostream& os, const Date& date_object){
    os << date_object.day << "/" << date_object.month << "/" << date_object.year; 
    return os; 
}

int main(void){
    list<int> intList; 
    list<float> floatList; 
    list<Date> dateList; 

    intList.insert_end(10); 
    intList.insert_end(20); 
    intList.insert_end(30); 

    floatList.insert_end(1.1f); 
    floatList.insert_end(2.2f); 
    floatList.insert_end(3.3f); 

    Date D1(12, 9, 2024); 
    Date D2(13, 9, 2024); 
    Date D3(14, 9, 2024); 

    dateList.insert_end(D1); 
    dateList.insert_end(D2); 
    dateList.insert_end(D3); 

    std::cout << "intList:" << intList; 
    std::cout << "floatList:" << floatList; 
    std::cout << "dateList:" << dateList; 

    std::cout << "intList using iterator" << std::endl; 
    for(
        list<int>::iterator iter = intList.begin(); 
        iter != intList.end(); 
        ++iter 
    )
        std::cout << "*iter=" << *iter << std::endl; 

    std::cout << "floatList using iterator" << std::endl; 
    for(
        list<float>::iterator iter = floatList.begin(); 
        iter != floatList.end(); 
        ++iter 
    )
        std::cout << "*iter=" << *iter << std::endl; 


    std::cout << "dateList using iterator" << std::endl; 
    for(
        list<Date>::iterator iter = dateList.begin(); 
        iter != dateList.end(); 
        ++iter 
    )
        std::cout << "*iter=" << *iter << std::endl; 

    return 0; 
}