class Solution {
    pair<int, int> diameterfast(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};  // {diameter, height}
        }

        pair<int, int> left = diameterfast(root->left);
        pair<int, int> right = diameterfast(root->right);

        int op1 = left.first;                 // Left subtree diameter
        int op2 = right.first;                // Right subtree diameter
        int op3 = left.second + right.second; // Diameter passing through root

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));  // Max diameter
        ans.second = max(left.second, right.second) + 1; // Corrected height

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterfast(root).first;
    }
};
