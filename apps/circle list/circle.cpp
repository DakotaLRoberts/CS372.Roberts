#include <iostream>
using namespace std;
#include"list.hpp"



template <typename T>
class CircularList : public List<T> {
public:
    using List<T>::List; // Inherit constructors from List class

    void circle(int startingPos) {
        if (this->empty()) {
            std::cerr << "circle(): Cannot circle an empty list." << std::endl;
            return;
        }

        int size = 0;
        for (typename List<T>::iterator it = this->begin(); it != this->end(); ++it) {
            if (size == startingPos) {
                typename List<T>::iterator start = it;
                typename List<T>::iterator current = it;
                do {
                    
                    std::cout << *current << " ";

                    ++current;
                    if (current == this->end()) {
                        current = this->begin();
						//cout << current << endl;
                    }
                } while (current != start);
                return;
            }
            ++size;
        }

        // If startingPos is out of bounds, handle the error
        std::cerr << "circle(): Starting position is out of bounds." << std::endl;
    }
};

int main() {
    CircularList<int> circularList;

    // Populate the circular list
    circularList.push_back(1);
    circularList.push_back(2);
    circularList.push_back(3);
    circularList.push_back(4);
    circularList.push_back(5);

    // Traverse and print the circular list
    std::cout << "Circular List: ";
    circularList.traverse([](int& data) {
        std::cout << data << " ";
        });
    std::cout << std::endl;

    // Perform a circular traversal starting from index 2
    std::cout << "Circular Traversal (starting from index 1): ";
    circularList.circle(1);
    std::cout << std::endl;

    return 0;
}