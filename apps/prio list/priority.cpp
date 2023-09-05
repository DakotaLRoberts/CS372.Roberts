#include <iostream>
#include <functional>
#include"list.hpp"
using namespace std;

template <typename T>
class PriorityList {
private:
    struct PrioNode {
        T data;
        int priority;
    };
    List<PrioNode> priorityList;
public:
    using iterator = typename List<PrioNode>::iterator;
    void insertPriority(const T& data, int priority) {
        PrioNode newNode{ data, priority };

        for (iterator it = priorityList.begin(); it != priorityList.end(); ++it) {
            if ((*it).priority <= priority) {
                priorityList.insert(it, newNode);
                return;
            }
        }

        priorityList.push_back(newNode);
    }
    void traverse(std::function<void(T& data)> doIt) {
        priorityList.traverse([&](PrioNode& pNode) {
            doIt(pNode.data);
            });
    }
};
int main() {
    PriorityList<string> List;
    List.insertPriority("apple", 3);
    List.insertPriority("tacos", 2);
    List.insertPriority("Liver medcine", 1);
    List.traverse([](std::string& data) {
        std::cout << data << std::endl;
        });
    return 0;
}