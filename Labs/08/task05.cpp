#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) { 
        value=x;
        left=nullptr;
        right=nullptr;
    }
};

TreeNode *sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void inOrderTraversal(TreeNode *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    int arr[] = {-10, -3, 0, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode *root = sortedArrayToBST(arr, 0, n - 1);

    cout << "In-order traversal of the balanced BST: ";
    inOrderTraversal(root);
    cout << endl;
}