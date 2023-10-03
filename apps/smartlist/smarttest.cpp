#include <iostream>
#include <memory>
#include"smartlist"

void printInt(int& data) {
    std::cout << data << " ";
}

int main() {
    List<int> myList;

    if (myList.empty()) {
        std::cout << "List is empty." << std::endl;
    }
    else {
        std::cout << "List is not empty." << std::endl;
    }

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    myList.traverse(printInt);
    std::cout << std::endl;

    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;

    myList.pop_back();

    myList.traverse(printInt);
    std::cout << std::endl;

    return 0;
}

