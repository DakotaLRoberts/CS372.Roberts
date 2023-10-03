#include <iostream>
#include<bstdelete.hpp>

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

 
    int deleteValue = 30;
    if (bst.deleteValue(deleteValue))
        std::cout << "Deleted " << deleteValue << " from the BST." << std::endl;
    else
        std::cout << deleteValue << " not found in the BST. Deletion failed." << std::endl;

   
    std::cout << "Inorder traversal after deleting " << deleteValue << ": ";
    bst.display();

    return 0;
}

