#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void printZigzagOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode *> currentLevel;
    stack<TreeNode *> nextLevel;

    currentLevel.push(root);

    bool leftToRight = true;

    while (!currentLevel.empty()) {
        TreeNode *node = currentLevel.top();
        currentLevel.pop();

        if (node) {
            cout << node->val << " ";
            if (leftToRight) {
                if (node->left) {
                    nextLevel.push(node->left);
                }
                if (node->right) {
                    nextLevel.push(node->right);
                }
            }
            else {
                if (node->right) {
                    nextLevel.push(node->right);
                }
                if (node->left) {
                    nextLevel.push(node->left);
                }
            }
        }

        if (currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Zigzag Order Traversal: ";
    printZigzagOrder(root);
}