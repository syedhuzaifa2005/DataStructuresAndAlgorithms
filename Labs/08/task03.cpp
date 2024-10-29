#include <iostream>
#include <climits>
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

void findMaxProfitPath(TreeNode *node, int currentSum, int &maxSum, string currentPath, string &maxProfitPath) {
    if (node == nullptr) {
        return;
    }
    currentSum += node->value;
    currentPath += to_string(node->value) + " ";

    if (node->left == nullptr && node->right == nullptr) {
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxProfitPath = currentPath;
        }
    }
    findMaxProfitPath(node->left, currentSum, maxSum, currentPath, maxProfitPath);
    findMaxProfitPath(node->right, currentSum, maxSum, currentPath, maxProfitPath);
}

string getMaxProfitPath(TreeNode *root) {
    if (root == nullptr) {
        return "No path available";
    }
    int maxSum = INT_MIN;
    string maxProfitPath;
    findMaxProfitPath(root, 0, maxSum, "", maxProfitPath);

    return maxProfitPath + "with maximum profit: " + to_string(maxSum);
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(-8);
    root->right->right = new TreeNode(7);

    cout << "Maximum Profit Path: " << getMaxProfitPath(root) << endl;
}