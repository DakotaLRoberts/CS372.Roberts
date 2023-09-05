#include <iostream>
using namespace std;
#include"list.hpp"


void printItem(int& item) {
	std::cout << item << " ";
}

int main() {
	List<int> aListOfIntegers;
	if (aListOfIntegers.empty()) {
		std::cout << "Yep, the new list is empty. " << std::endl;
	}
	for (int i = 3; i >= 0; i--) {
		aListOfIntegers.push_front(i);
	}
	aListOfIntegers.traverse(printItem);
	std::cout << std::endl;

	std::cout << "Test iterators: Mutable -> ";
	for (auto iter = aListOfIntegers.begin();
		iter != aListOfIntegers.end();
		++iter) {
		std::cout << *iter << " ";
	}

	std::cout << "Test iterators: const -> ";
	for (auto iter = aListOfIntegers.cbegin();
		iter != aListOfIntegers.cend();
		++iter) {
		std::cout << *iter << " ";
	}

	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		int datum = aListOfIntegers.back();
		std::cout << datum << " ";
		aListOfIntegers.pop_back();
	}
	std::cout << std::endl;
	if (!aListOfIntegers.empty()) {
		aListOfIntegers.traverse(printItem);
		std::cout << std::endl;
	}
	aListOfIntegers.push_back(42);
	aListOfIntegers.traverse(printItem);
	std::cout << std::endl;
	List<int>::iterator itr = aListOfIntegers.begin();
	++itr; // Move itr to the second element (value 2)
	aListOfIntegers.insert(itr, 4); // Insert 4 before the element pointed to by itr

	for (int num : aListOfIntegers) {
		std::cout << num << " ";
	}

	return 0;
}