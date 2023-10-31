#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

template <typename T>
void QuickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && arr[i] <= arr[pivot]) {
                i++;
            }
            while (j > low && arr[j] > arr[pivot]) {
                j--;
            }
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[pivot], arr[j]);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

template <typename T>
void QuickSort(std::vector<T>& arr) {
    QuickSort(arr, 0, arr.size() - 1);
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "Vector Size\tQuickSort Time\tstd::sort Time" << std::endl;

    for (int size : {100, 500, 1000, 5000, 10000}) {
        std::vector<int> data(size);

        for (int i = 0; i < size; ++i) {
            data[i] = gen();
        }

        auto quicksort_start = std::chrono::high_resolution_clock::now();
        QuickSort(data);
        auto quicksort_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> quicksort_time = quicksort_end - quicksort_start;

        std::vector<int> stl_data = data; // Copy data for std::sort
        auto stl_sort_start = std::chrono::high_resolution_clock::now();
        std::sort(stl_data.begin(), stl_data.end());
        auto stl_sort_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> stl_sort_time = stl_sort_end - stl_sort_start;

        std::cout << size << "\t\t" << quicksort_time.count() << "s\t\t" << stl_sort_time.count() << "s" << std::endl;
    }

    return 0;
}
