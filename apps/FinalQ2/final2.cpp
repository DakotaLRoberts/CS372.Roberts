#include <iostream>
#include <list>
#include <vector>

template <typename T>
void partitionList(const T& splittingValue, const std::vector<T>& inputList, std::list<T>* lessThanList, std::list<T>* greaterThanList) {
    for (const T& element : inputList) {
        if (element < splittingValue) {
            lessThanList->push_back(element);
        }
        else if (element > splittingValue) {
            greaterThanList->push_back(element);
        }
       
    }
}

template <typename T>
std::list<T>* quicksort(const std::vector<T>& inputList) {
    if (inputList.size() <= 1) {
    
        return new std::list<T>(inputList.begin(), inputList.end());
    }


    T pivot = inputList[0];

 
    std::list<T> lessThanList;
    std::list<T> greaterThanList;
    partitionList(pivot, inputList, &lessThanList, &greaterThanList);


    std::list<T>* sortedLessThan = quicksort(std::vector<T>(lessThanList.begin(), lessThanList.end()));
    std::list<T>* sortedGreaterThan = quicksort(std::vector<T>(greaterThanList.begin(), greaterThanList.end()));


    std::list<T>* result = new std::list<T>();
    result->insert(result->end(), sortedLessThan->begin(), sortedLessThan->end());
    result->push_back(pivot);
    result->insert(result->end(), sortedGreaterThan->begin(), sortedGreaterThan->end());

   
    delete sortedLessThan;
    delete sortedGreaterThan;

    return result;
}

int main() {
  
    std::vector<int> inputList = { 3, 8, 2, 6, 1, 7, 9, 4 };

   
    std::list<int>* sortedList = quicksort(inputList);

 
    std::cout << "Sorted List: ";
    for (const auto& element : *sortedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

 
    delete sortedList;

    return 0;
}
