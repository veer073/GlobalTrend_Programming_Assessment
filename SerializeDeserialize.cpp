#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root) {
    if (!root) return "";
    string result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            result += "null,";
        }
    }
    return result;
}

TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;
    stringstream ss(data);
    string item;
    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (getline(ss, item, ',')) {
            if (item != "null") {
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }
        }
        if (getline(ss, item, ',')) {
            if (item != "null") {
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
    }
    return root;
}

void preorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized tree (preorder traversal): ";
    preorder(deserialized);
    cout << endl;

    return 0;
}

