#include<iostream>
#include "vector.hpp"

using namespace std;
template <typename T, size_t Size>
class Array {
public:

    Array() {

        array.expand(Size);
    };
    void put(T fill, int index) {
        array.put(fill, index);

    }
    T operator[](size_t index) {

        return array.at(index);
    }



    size_t size() {
        return Size;
    }

private:
    vector<T>array;
};