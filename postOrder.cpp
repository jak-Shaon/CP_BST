#include <iostream>
#include <stack>

//left->right->root
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void postorderTraversalRecursive(TreeNode* root) {
    if (root != nullptr) {
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        std::cout << root->val << " ";
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Recursive Postorder Traversal: ";
    postorderTraversalRecursive(root);
    std::cout << std::endl;

    return 0;
}

