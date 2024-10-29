#include <iostream>
#include <string>
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

string serialize(TreeNode *root) {
    if (!root){
        return "#";
    }
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

string getNextToken(const string &data, int &pos) {
    int start = pos;
    while (pos < data.size() && data[pos] != ',') {
        pos++;
    }
    string token = data.substr(start, pos - start);
    pos++;
    return token;
}

TreeNode *deserializeHelper(const string &data, int &pos) {
    string token = getNextToken(data, pos);
    if (token == "#"){
        return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(token));
    node->left = deserializeHelper(data, pos);
    node->right = deserializeHelper(data, pos);
    return node;
}

TreeNode *deserialize(const string &data) {
    int pos = 0;
    return deserializeHelper(data, pos);
}

void printTree(TreeNode *root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode *deserializedTree = deserialize(serializedTree);
    cout << "Deserialized Tree (Preorder): ";
    printTree(deserializedTree);
    cout << endl;
}