#include <iostream>
using namespace std;
#include"list.hpp"


template <typename T>
class CircularList : public List<T> {
public:
    using List<T>::List; 

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
						
                    }
                } while (current != start);
                return;
            }
            ++size;
        }

        
        std::cerr << "circle(): Starting position is out of bounds." << std::endl;
    }
};

int main() {
    CircularList<int> circle;

  
    circle.push_back(1);
    circle.push_back(2);
    circle.push_back(3);
    circle.push_back(4);
    circle.push_back(5);

   
    std::cout << "Circular List: ";
    circle.traverse([](int& data) {
        std::cout << data << " ";
        });
    std::cout << std::endl;

  
    std::cout << "Circle Traverse (starting from index 1): ";
    circle.circle(1);
    std::cout << std::endl;

    return 0;
}
