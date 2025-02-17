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
    void createMap(map<int, int>& nodeToind, vector<int>& in) {
        int n = in.size();

        for (int i = 0; i < n; i++) {
            nodeToind[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& pre, vector<int>& in, int& ind, int instart,
                    int inEnd,int n, map<int, int>& nodeToind) {

        if (ind >= n || instart > inEnd)
            return NULL;

        int el = pre[ind++];
       TreeNode* root = new TreeNode(el);

        int pos = nodeToind[el];

        // rec calls
        root->left = solve( pre,in, ind, instart, pos - 1, n, nodeToind);
        root->right = solve(pre,in, ind, pos + 1, inEnd, n, nodeToind);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        /// inorder -> LEFT ROOT RIGHT
        // preorder -> R00T LEFT RIGHT

        int n = pre.size();
        int preInd = 0;

        map<int, int> nodeToind;

        createMap(nodeToind, in);

        TreeNode* ans = solve(pre, in, preInd, 0, n - 1, n, nodeToind);

        return ans;
    }
};