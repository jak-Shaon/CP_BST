#include <iostream>
#include <stack>

//root->left->right
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void preorderTraversalRecursive(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << " ";
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Recursive Preorder Traversal: ";
    preorderTraversalRecursive(root);
    std::cout << std::endl;

    return 0;
}

