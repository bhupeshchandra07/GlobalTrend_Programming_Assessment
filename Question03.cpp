#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSumUtil(TreeNode* root, int &res) {
    if (!root) return 0;
    int left = std::max(0, maxPathSumUtil(root->left, res));
    int right = std::max(0, maxPathSumUtil(root->right, res));
    res = std::max(res, left + right + root->val);
    return root->val + std::max(left, right);
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << "Maximum path sum: " << maxPathSum(root) << std::endl;
    return 0;
}
