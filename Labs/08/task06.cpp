#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode *first = nullptr;
TreeNode *second = nullptr;
TreeNode *prev = nullptr;

void findSwappedNodes(TreeNode *root) {
    if (root == nullptr){
        return;
    }

    findSwappedNodes(root->left);

    if (::prev != nullptr && root->value < ::prev->value) {
        if (first == nullptr) {
            first = ::prev;
        }
        second = root;
    }
    ::prev = root;

    findSwappedNodes(root->right);
}

void recoverBST(TreeNode *root) {
    first = second = ::prev = nullptr;
    findSwappedNodes(root);

    if (first && second) {
        swap(first->value, second->value);
    }
}

void inOrderTraversal(TreeNode *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);

    cout << "In-order traversal before recovery: ";
    inOrderTraversal(root);
    cout << endl;

    recoverBST(root);

    cout << "In-order traversal after recovery: ";
    inOrderTraversal(root);
    cout << endl;
}