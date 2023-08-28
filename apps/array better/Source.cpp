#include<iostream>
#include "array.hpp"



int main() {
    Array<int, 6> intArray;
    std::cout << "Size of intArray: " << intArray.size() << std::endl;

    for (int i = 0; i < intArray.size(); i++) {
        intArray.put(i,i);
       
        
    }

    std::cout << "Modified intArray: " << endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " " << endl;
    }
    std::cout << std::endl;

    Array<std::string, 3> strArray;
    std::cout << "Size of strArray: " << strArray.size() << std::endl;

    strArray.put("Hello", 0);
    strArray.put("World", 2);
   

    std::cout << "Modified strArray: ";
    for (size_t i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}