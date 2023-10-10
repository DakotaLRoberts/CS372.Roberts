#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

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

        return false; // Value not found
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
    int find(int x, std::shared_ptr<Node> t) {
        if (t == nullptr)
            return -1; // Element not found
        else if (x < t->data)
            return find(x, t->left);
        else if (x > t->data)
            return find(x, t->right);
        else
            return t->data; // Element found
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

int main() {
   
    treeStructure* Struct = createAndPopulateStructure(10); 

    std::cout << "Sorted elements in the BST: ";
    Struct->treePtr->display();

    
    int elementToFind = 42; 
    int foundElement = Struct->treePtr->find(elementToFind);
    if (foundElement != -1) {
        std::cout << "Found element " << elementToFind << " in the BST." << std::endl;
    }
    else {
        std::cout << "Element " << elementToFind << " not found in the BST." << std::endl;
    }

    
    delete Struct->treePtr;
    delete Struct;

    return 0;
}





