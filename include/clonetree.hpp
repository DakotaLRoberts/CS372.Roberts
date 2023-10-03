#include <iostream>
#include <memory>

struct Node {
    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};
class BST {
private:


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
                return true;
            }
        }
        else if (x > t->data) {
            if (deleteNode(x, t->right)) {
                return true;
            }
        }
        else {
            if (t->left == nullptr && t->right == nullptr) {
                t = nullptr;
            }
            else if (t->left == nullptr) {
                t = t->right;
            }
            else if (t->right == nullptr) {
                t = t->left;
            }
            else {
                std::shared_ptr<Node> minValueNode = findMin(t->right);
                t->data = minValueNode->data;
                deleteNode(minValueNode->data, t->right);
            }

            return true;
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
    std::shared_ptr<Node> getRoot() {
        return root;
    }
    int find(int x) {
        return find(x, root);
    }

    int find(int x, std::shared_ptr<Node> t) {
        if (t == nullptr)
            return -1;
        else if (x < t->data)
            return find(x, t->left);
        else if (x > t->data)
            return find(x, t->right);
        else
            return t->data;
    }


    void setRoot(std::shared_ptr<Node> newRoot) {
        root = newRoot;
    }
};

