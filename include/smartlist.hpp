#include <iostream>
#include <memory>

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> head = nullptr;
    std::shared_ptr<Node> tail = nullptr;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(T newData) {
        auto newNode = std::make_shared<Node>();
        newNode->data = newData;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }

    List(const List& rhs) { // copy constructor
        for (auto current = rhs.head; current != nullptr; current = current->next) {
            push_back(current->data);
        }
    }

    ~List() {
        head = nullptr; // Shared pointers will take care of deletion
        tail = nullptr;
    }

    bool empty() {
        return (head == nullptr);
    }

    void push_front(T data) {
        auto newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        auto newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (empty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        if (tail != nullptr) {
            if (tail->prev != nullptr) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else { // Only one element in the list
                head = nullptr;
                tail = nullptr;
            }
        }
    }

    T& front() {
        if (!empty()) {
            return head->data;
        }
        else {
            throw std::runtime_error("Exception: list is empty.");
        }
    }

    T& back() {
        if (!empty()) {
            return tail->data;
        }
        else {
            throw std::runtime_error("Exception: list is empty.");
        }
    }

    void traverse(void (*doIt)(T& data)) {
        for (auto current = head; current != nullptr; current = current->next) {
            doIt(current->data);
        }
    }
};


