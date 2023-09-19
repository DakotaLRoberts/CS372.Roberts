
using namespace std;
#include <iostream>
#include <functional>

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
        bool deleted;

        Node() : data(T()), prev(nullptr), next(nullptr), deleted(false) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    void setupList() {
        head = nullptr;
        Node* newNode = new Node();
        head = newNode;
        tail = newNode;
    }

public:
    List() = default;



    bool empty() const {
        return (head == nullptr);
    }

    void push_front(T data) {
        if (this->empty()) {
            setupList();
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;

        if (head) {
            head->prev = newNode;
        }

        newNode->prev = nullptr;
        newNode->deleted = false;

        head = newNode;
    }


    void push_back(T data) {
        if (this->empty()) {
            setupList();
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        newNode->deleted = false;

        if (tail) {
            tail->next = newNode;
        }

        tail = newNode;
    }

    T front() const {
        if (head) {
            return head->data;
        }
        throw std::runtime_error("List is empty");
    }

    T back() const {
        if (tail) {
            return tail->data;
        }
        throw std::runtime_error("List is empty");
    }

    void pop_back() {
        if (tail) {
            Node* lastNode = tail;
            tail = tail->prev;

            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }

            delete lastNode;
        }
    }

    void pop_front() {
        if (head) {
            Node* firstNode = head;
            head = head->next;

            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }

            delete firstNode;
        }
    }

    void traverse(std::function<void(T)> func) const {
        Node* current = head;
        while (current != nullptr) {
            if (!current->deleted) {
                func(current->data);
            }
            current = current->next;
        }
    }
    void markDelete(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (!current->deleted && current->data == value) {
                current->deleted = true;
            }
            current = current->next;
        }

        current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            if (temp->deleted) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                else {
                    head = temp->next;
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                else {
                    tail = temp->prev;
                }
                delete temp;
            }
        }
    }

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
int main() {
    List<int> deltionlist;
    deltionlist.push_front(12);
    deltionlist.push_front(42);
    deltionlist.push_front(33);
    deltionlist.push_back(47);
    deltionlist.push_back(85);
    deltionlist.push_back(46);
    cout << "orginal Front: " << deltionlist.front() << endl;
    cout << "orginal Back: " << deltionlist.back() << endl;
    deltionlist.pop_front();
    deltionlist.pop_back();
    cout << "new Front: " << deltionlist.front() << std::endl;
    cout << " new Back " << deltionlist.back() << std::endl;
    deltionlist.markDelete(33);
    cout << "Remaining list ";
    deltionlist.traverse([](int data) { cout << data << " "; });
    cout << endl;

    return 0;
}