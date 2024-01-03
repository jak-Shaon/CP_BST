#include <iostream>
#include <stack>

//left->root->right
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void inOrderTraverseRecursive(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraverseRecursive(root->left);
        std::cout << root->value << " ";
        inOrderTraverseRecursive(root->right);
    }
}

int main()
{

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Recursive Inorder Traversal: ";
    inOrderTraverseRecursive(root);
    std::cout << std::endl;

    return 0;
}

