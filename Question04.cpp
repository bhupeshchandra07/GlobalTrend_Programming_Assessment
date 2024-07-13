#include <iostream>
#include <string>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::string serialize(TreeNode* root) {
    if (!root) return "#";
    return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserializeUtil(std::istringstream &ss) {
    std::string val;
    std::getline(ss, val, ',');
    if (val == "#") return nullptr;
    TreeNode* root = new TreeNode(std::stoi(val));
    root->left = deserializeUtil(ss);
    root->right = deserializeUtil(ss);
    return root;
}

TreeNode* deserialize(std::string data) {
    std::istringstream ss(data);
    return deserializeUtil(ss);
}

void printTree(TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "# ";
        }
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::string serialized = serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    TreeNode* deserialized = deserialize(serialized);
    std::cout << "Deserialized tree: ";
    printTree(deserialized);

    return 0;
}
