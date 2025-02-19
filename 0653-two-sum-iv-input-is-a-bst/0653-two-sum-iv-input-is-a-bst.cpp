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
    void inorder(TreeNode* root, vector<int>&value){

        if(root == NULL) return;


        inorder(root->left,value);
        value.push_back(root->val);
        inorder(root->right,value);
    }


    bool twosum(TreeNode* root,vector<int>&value, int k)
    {
        int i = 0;
        int j = value.size() - 1;

        while(i<j){

            if(value[i]+value[j] == k) return true;
            else if(value[i] + value[j] > k) j--;
            else i++;
        }

        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>value;


        inorder(root,value);

        bool ans = twosum(root,value,k);

        return ans;



    }
};