#include <iostream>
#include<bits/stdc++.h>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void deleteNode(int key) {
        root = deleteNodeRecursive(root, key);
    }

private:
    Node* deleteNodeRecursive(Node* root, int key) {
         if (root == nullptr) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteNodeRecursive(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNodeRecursive(root->right, key);
        }
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            root->data = successor->data;

            root->right = deleteNodeRecursive(root->right, successor->data);
        }

        return root;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);


    std::cout << "Inorder Traversal: ";
    bst.inorder();

    bst.deleteNode(30);

    std::cout << "Inorder Traversal after deletion: ";
    bst.inorder();

    return 0;
}
