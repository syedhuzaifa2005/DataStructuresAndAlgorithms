#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

bool isIdentical(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2){
        return true;        
    }
    if (!root1 || !root2){
        return false;
    }

    return (root1->value == root2->value && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}

bool isSubtree(TreeNode *T1, TreeNode *T2) {
    if (!T2){
        return true;
    }
    if (!T1){
        return false;
    }

    if (isIdentical(T1, T2)){
        return true;
    }

    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main() {
    TreeNode *T1 = new TreeNode(1);
    T1->left = new TreeNode(2);
    T1->right = new TreeNode(3);
    T1->left->left = new TreeNode(4);
    T1->left->right = new TreeNode(5);
    T1->right->left = new TreeNode(6);
    T1->right->right = new TreeNode(7);

    TreeNode *T2 = new TreeNode(3);
    T2->left = new TreeNode(6);
    T2->right = new TreeNode(7);

    if (isSubtree(T1, T2)) {
        cout << "T2 is a subtree of T1." << endl;
    }
    else {
        cout << "T2 is not a subtree of T1." << endl;
    }
}