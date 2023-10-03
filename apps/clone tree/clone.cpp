
#include<iostream>
#include<memory>
#include"clonetree.hpp"

std::shared_ptr<Node> copyTreeWithoutLeaves(const std::shared_ptr<Node>& originalNode) {
    if (originalNode == nullptr) {
        return nullptr;
    }

   
    if (originalNode->left == nullptr && originalNode->right == nullptr) {
        return nullptr; 
    }

    std::shared_ptr<Node> newLeft = copyTreeWithoutLeaves(originalNode->left);
    std::shared_ptr<Node> newRight = copyTreeWithoutLeaves(originalNode->right);

  
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->data = originalNode->data;
    newNode->left = newLeft;
    newNode->right = newRight;

    return newNode;
}

int main() {
  
    BST originalTree;

    originalTree.insert(50);
    originalTree.insert(30);
    originalTree.insert(70);
    originalTree.insert(20);
    originalTree.insert(40);
    originalTree.insert(60);
    originalTree.insert(80);

    std::cout << "Original Tree (Inorder Traversal): ";
    originalTree.display();

    
    std::shared_ptr<Node> newTreeRoot = copyTreeWithoutLeaves(originalTree.getRoot());

    std::cout << "New Tree (Inorder Traversal): ";
    BST newTree;
    newTree.setRoot(newTreeRoot);
    newTree.display();

    return 0;
}
