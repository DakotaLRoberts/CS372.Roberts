#include <iostream>

struct Record {
    int key;
    
};

template <class RecordType>
class Table {
public:
    static const std::size_t CAPACITY = 811;
    Table();
    void insert(const RecordType& entry);
    void remove(int key);
    bool isPresent(int key) const;
    void find(int key, bool& found, RecordType& result) const;
    std::size_t size() const;

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;
    std::size_t hash(int key) const;
    std::size_t quadProbe(std::size_t originalIndex, std::size_t i) const;
    void findIndex(int key, bool& found, std::size_t& index) const;
    bool neverUsed(std::size_t index) const;
    bool isVacant(std::size_t index) const;
};

template <class RecordType>
Table<RecordType>::Table() : used(0) {}

template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry) {
    bool alreadyPresent;
    std::size_t index;
    if (entry.key < 0) {
        std::cerr << "Invalid key: " << entry.key << std::endl;
        return;
    }
    findIndex(entry.key, alreadyPresent, index);
    if (!alreadyPresent) {
        if (used < CAPACITY) {
            index = hash(entry.key);
            std::size_t originalIndex = index;
            std::size_t i = 1;
            while (!isVacant(index)) {
                index = quadProbe(originalIndex, i);
                ++i;
            }
            ++used;
            data[index] = entry;
        }
        else {
            std::cerr << "Table is full." << std::endl;
        }
    }
}

template <class RecordType>
void Table<RecordType>::remove(int key) {
    bool found;
    std::size_t index;
    if (key < 0) {
        std::cerr << "Invalid key: " << key << std::endl;
        return;
    }
    findIndex(key, found, index);
    if (found) {
        data[index].key = PREVIOUSLYUSED;
        --used;
    }
}

template <class RecordType>
bool Table<RecordType>::isPresent(int key) const {
    bool found;
    std::size_t index;
    if (key < 0) {
        std::cerr << "Invalid key: " << key << std::endl;
        return false;
    }
    findIndex(key, found, index);
    return found;
}

template <class RecordType>
void Table<RecordType>::find(int key, bool& found, RecordType& result) const {
    std::size_t index;
    if (key < 0) {
        std::cerr << "Invalid key: " << key << std::endl;
        found = false;
        return;
    }
    findIndex(key, found, index);
    if (found) {
        result = data[index];
    }
}

template <class RecordType>
std::size_t Table<RecordType>::size() const {
    return used;
}

template <class RecordType>
std::size_t Table<RecordType>::hash(int key) const {
    return key % CAPACITY;
}

template <class RecordType>
std::size_t Table<RecordType>::quadProbe(std::size_t originalIndex, std::size_t i) const {
    return (originalIndex + i * i) % CAPACITY;
}

template <class RecordType>
void Table<RecordType>::findIndex(int key, bool& found, std::size_t& index) const {
    std::size_t count;
    count = 0;
    index = hash(key);
    std::size_t originalIndex = index;
    std::size_t i = 1;
    while ((count < CAPACITY) && (!neverUsed(index)) && (data[index].key != key)) {
        ++count;
        index = quadProbe(originalIndex, i);
        ++i;
    }
    found = (data[index].key == key);
}

template <class RecordType>
bool Table<RecordType>::neverUsed(std::size_t index) const {
    return (index == NEVERUSED);
}

template <class RecordType>
bool Table<RecordType>::isVacant(std::size_t index) const {
    return (index == PREVIOUSLYUSED);
}

