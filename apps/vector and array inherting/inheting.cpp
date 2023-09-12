



#include <iostream>
#include <stdexcept>
#include"SeqContainer"
using namespace std;

template <typename T>
class vector : public SeqContainer<T> {
public:
    vector() : SeqContainer<T>() {
    }

    void push_back(T data) {
        this->insert(this->end(), data);
    }

    T& at(int index) {
        if (index < 0 || index >= this->size()) {
            cout << "Vector index is out of bounds";
        }
        return this->begin()[index];
    }

    int size() {
        int count = 0;
        for (auto i = this->begin(); i != this->end(); i++) {
            count++;
        }
        return count;
    }

    

    void traverse() {
        for (auto i = this->begin(); i != this->end(); i++) {
            cout << *i << endl;
        }
        
    }
};
template <typename T, size_t Size>
class Array : public SeqContainer<T> {
private:
    T seqarray[Size];
public:
    Array() : SeqContainer<T>() {
       
        for (size_t i = 0; i < Size; i++) {
            seqarray[i] = T();
        }
    }
    size_t size() {
        return Size;
    }
    void put(T data, int index) {
        if (index < 0 || index >= Size) {
            cout << "Array index out of bounds";
        }
       
        seqarray[index] = data;
    }
    void traverse() {
        for (size_t i = 0; i < Size; i++) {
            cout << seqarray[i] << endl;
        }
        
    }


};

int main() {
    vector<int> testingvector;
    for (int i = 0; i < 5; ++i) {
        testingvector.push_back(i);
    }
    cout << "here is you test vector size: " << testingvector.size() << endl;
    testingvector.traverse();
    Array<int, 3> testingarray;
    for (int i = 0; i < testingarray.size(); ++i ) {
        testingarray.put(i * 2, i);
    }
   cout <<" here is your test Array size: " << testingarray.size() << endl;
    testingarray.traverse();
    return 0;
}