#include <iostream>
#include <vector>

template <typename T>
bool binarySearch(const std::vector<T>& sortedVector, const T& target, bool printDebugData = false) {
    int left = 0;
    int right = sortedVector.size() - 1;
    int comparisons = 0;  

    while (left <= right) {
        int middle = left + (right - left) / 2;
        comparisons++;  

        if (sortedVector[middle] == target) {
            if (printDebugData) {
                std::cout << "Number of comparisons: " << comparisons << std::endl;
            }
            return true; 
        }
        else if (sortedVector[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    if (printDebugData) {
        std::cout << "Number of comparisons: " << comparisons << std::endl;
    }

    return false;  
}

int main() {
    std::vector<int> sortedVector = { 1, 3, 5, 7, 9, 11, 13, 15, 26, 22, 28 , 29 ,20 };
    int target = 22;

    bool found = binarySearch(sortedVector, target, true);

    if (found) {
        std::cout << "Element " << target << " found in the vector." << std::endl;
    }
    else {
        std::cout << "Element " << target << " not found in the vector." << std::endl;
    }

    return 0;
}
