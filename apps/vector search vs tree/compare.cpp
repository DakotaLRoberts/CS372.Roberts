
#include <memory>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

class BST {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;

    std::shared_ptr<Node> makeEmpty(std::shared_ptr<Node> t) {
        if (t == nullptr)
            return nullptr;
        t->left = makeEmpty(t->left);
        t->right = makeEmpty(t->right);
        return nullptr;
    }

    std::shared_ptr<Node> insert(int x, std::shared_ptr<Node> t) {
        if (t == nullptr) {
            t = std::make_shared<Node>();
            t->data = x;
            t->left = t->right = nullptr;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    std::shared_ptr<Node> findMin(std::shared_ptr<Node> t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    bool deleteNode(int x, std::shared_ptr<Node>& t) {
        if (t == nullptr)
            return false; // Value not found

        if (x < t->data) {
            if (deleteNode(x, t->left)) {
                // If value was found and deleted in the left subtree
                return true;
            }
        }
        else if (x > t->data) {
            if (deleteNode(x, t->right)) {
                // If value was found and deleted in the right subtree
                return true;
            }
        }
        else {
            // Node with the value x is found

            if (t->left == nullptr && t->right == nullptr) {
                // Node is a leaf node
                t = nullptr;
            }
            else if (t->left == nullptr) {
                // Node has only a right child
                t = t->right;
            }
            else if (t->right == nullptr) {
                // Node has only a left child
                t = t->left;
            }
            else {
                // Node has both left and right children
                std::shared_ptr<Node> minValueNode = findMin(t->right);
                t->data = minValueNode->data;
                deleteNode(minValueNode->data, t->right);
            }

            return true; // Value found and deleted
        }

        return false; 
    }

    void inorder(std::shared_ptr<Node> t) {
        if (t == nullptr)
            return;
        inorder(t->left);
        std::cout << t->data << " ";
        inorder(t->right);
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    bool deleteValue(int x) {
        return deleteNode(x, root);
    }

    void display() {
        inorder(root);
        std::cout << std::endl;
    }

    int find(int x) {
        return find(x, root);
    }

private:
    int find(int x, std::shared_ptr<Node> i) {
        if (i == nullptr)
            return -1;
        else if (x < i->data)
            return find(x, i->left);
        else if (x > i->data)
            return find(x, i->right);
        else
            return i->data;
    }
};
 
struct treeStructure {
    size_t size;
    std::vector<int>* vectorPtr;
    BST* treePtr;
};

treeStructure* createAndPopulateStructure(size_t numItems) {
    treeStructure* Struct = new treeStructure;
    Struct->size = numItems;
    Struct->vectorPtr = new std::vector<int>;

    for (size_t i = 0; i < numItems; ++i) {
        int randomInt = rand() % 100;  
        Struct->vectorPtr->push_back(randomInt);
    }

    std::sort(Struct->vectorPtr->begin(), Struct->vectorPtr->end());

    Struct->treePtr = new BST;

    for (const int& item : *(Struct->vectorPtr)) {
        Struct->treePtr->insert(item);
    }

    return Struct;
}


int getRandomNumber(int min, int max) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


template <typename T>
bool binarySearch(const std::vector<T>& sortedVector, const T& target) {
    int left = 0;
    int right = sortedVector.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sortedVector[middle] == target) {
            return true;
        }
        else if (sortedVector[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return false;
}

int main() {
    const int numStructures[] = { 1000, 2500, 5000, 10000, 50000 };
    const int numSearches = 100;

    for (int numItems : numStructures) {
        treeStructure* structure = createAndPopulateStructure(numItems);

      
        auto vectorStartTime = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numSearches; ++i) {
            int target = getRandomNumber(1, numItems * 2);
            bool found = binarySearch(*(structure->vectorPtr), target);
        }
        auto vectorEndTime = std::chrono::high_resolution_clock::now();
        auto vectorDuration = std::chrono::duration_cast<std::chrono::microseconds>(vectorEndTime - vectorStartTime);

       
        auto bstStartTime = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numSearches; ++i) {
            int target = getRandomNumber(1, numItems * 2);
            bool found = structure->treePtr->find(target) != -1;
        }
        auto bstEndTime = std::chrono::high_resolution_clock::now();
        auto bstDuration = std::chrono::duration_cast<std::chrono::microseconds>(bstEndTime - bstStartTime);


        double vectorAverageTime = static_cast<double>(vectorDuration.count()) / numSearches;
        double bstAverageTime = static_cast<double>(bstDuration.count()) / numSearches;

        std::cout << "Structure Size: " << numItems << std::endl;
        std::cout << "Average Time for Binary Search (us): " << vectorAverageTime << std::endl;
        std::cout << "Average Time for BST Lookup (us): " << bstAverageTime << std::endl;
        std::cout << std::endl;

       
        delete structure->vectorPtr;
        delete structure->treePtr;
        delete structure;
    }

    return 0;
}
