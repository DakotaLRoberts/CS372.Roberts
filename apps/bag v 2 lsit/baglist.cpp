#include <iostream>
using namespace std;
#include <functional>
#include "list.hpp"

template <typename Thing>
class Bag {
public:
    void insert(Thing aThing) {
        bagContents.push_back(aThing);
        bagSize++;
    }

    Thing pop() {
        if (bagSize > 0) {
            Thing aThing = bagContents.back();
            bagContents.pop_back();
            bagSize--;
            return aThing;
        }
        else {
            throw std::runtime_error("Can't pop out of an empty bag");
        }
    }

    int size() const {
        return bagSize;
    }

    int count(Thing aThing) const {
        int bagCount = 0;
        for (const Thing& item : bagContents) {
            if (item == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }

private:
    List<Thing> bagContents;
    int bagSize = 0;
};

int main() {
	Bag<int> bag;

	// Insert some values into the bag
	bag.insert(5);
	bag.insert(10);
	bag.insert(5);
	bag.insert(20);

	std::cout << "Bag size: " << bag.size() << std::endl;

	// Count occurrences
	//std::cout << "Count of 5: " << bag.count(5) << std::endl;
	//std::cout << "Count of 10: " << bag.count(10) << std::endl;
	//std::cout << "Count of 20: " << bag.count(20) << std::endl;

	// Pop elements from the bag
	try {
		while (bag.size() > 1) {
			std::cout << "Popped: " << bag.pop() << std::endl;
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Bag size after popping: " << bag.size() << std::endl;

	return 0;
}