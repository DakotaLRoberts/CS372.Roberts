#include"BST.hpp"
#include <iostream>

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    
    std::cout << "Inorder traversal: ";
    bst.display();

   
    int findValue = 40;
    int found = bst.find(findValue);
    if (found != -1)
        std::cout << "Found " << findValue << " in the BST." << std::endl;
    else
        std::cout << findValue << " not found in the BST." << std::endl;

   
    int removeValue = 30;
    bst.remove(removeValue);

   
    std::cout << "Inorder traversal after removing " << removeValue << ": ";
    bst.display();

    return 0;
}