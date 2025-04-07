/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode* root){

        if(root == nullptr) return 0;


        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right);

        return ans+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        

        if(root == nullptr) return true;


        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->right) - height(root->left)) <= 1;

        if(left && right && diff) return 1;
        else return false;
    }
};