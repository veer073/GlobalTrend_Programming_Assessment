#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int Helper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int leftSum = max(0, Helper(root->left, maxSum));
    int rightSum = max(0, Helper(root->right, maxSum));
    maxSum = max(maxSum, root->val + leftSum + rightSum);
    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    Helper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Maximum path sum: " << maxPathSum(root) << endl;
    return 0;
}

