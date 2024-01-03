#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    } else if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    } else {
        return root;
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    int n1 = 30, n2 = 40;
    TreeNode* lca = findLCA(root, n1, n2);

    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << std::endl;
    } else {
        std::cout << "Nodes " << n1 << " and " << n2 << " are not present in the BST." << std::endl;
    }

    return 0;
}

