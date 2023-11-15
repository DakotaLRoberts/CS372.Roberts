#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
  
};


class Tree {
public:
    TreeNode* root;
   
    Tree(TreeNode* r) : root(r) {}
};

// Function 1: Count Nodes
int countNodes(const TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// Function 2: Count Internal Nodes
int countInternalNodes(const TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }
    else {
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
}

// Function 3: External Path Length
void externalPathLength(const TreeNode* root, int& sum) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }
    else {
        
        ++sum;

      
        externalPathLength(root->left, sum);
        externalPathLength(root->right, sum);
    }
}

int main() {

    TreeNode* root = new TreeNode{ 1, new TreeNode{2, nullptr, nullptr}, new TreeNode{3, nullptr, nullptr} };
    Tree myTree{ root };

    // Function 1: Count Nodes
    int nodeCount = countNodes(myTree.root);
    std::cout << "Number of nodes in the tree: " << nodeCount << std::endl;

    // Function 2: Count Internal Nodes
    int internalNodeCount = countInternalNodes(myTree.root);
    std::cout << "Number of internal nodes in the tree: " << internalNodeCount << std::endl;

    // Function 3: External Path Length
    int externalPathSum = 0;
    externalPathLength(myTree.root, externalPathSum);
    std::cout << "External Path Length of the tree: " << externalPathSum << std::endl;

 
    return 0;
}
