/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(vector<int>& pre, int mini, int maxx, int& i) {
        if (i >= pre.size())
            return nullptr;

        if (pre[i] < mini || pre[i] > maxx)
            return nullptr;

        TreeNode* root = new TreeNode(pre[i++]);

        root->left = solve(pre, mini, root->val, i);
        root->right = solve(pre, root->val, maxx, i);

            return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int mini = INT_MIN;
        int maxx = INT_MAX;
        int i =0;
        return solve(pre, mini, maxx, i);
    }
};