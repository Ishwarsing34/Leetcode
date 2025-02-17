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
public:
     void createMap(map<int, int>& nodeToind, vector<int>& in) {
        int n = in.size();

        for (int i = 0; i < n; i++) {
            nodeToind[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& post, vector<int>& in, int& ind, int instart,
                    int inEnd, int n, map<int, int>& nodeToind) {

        if (ind < 0 || instart > inEnd)
            return NULL;

        int el = post[ind--];
        TreeNode* root = new TreeNode(el);

        int pos = nodeToind[el];

        // rec calls
        root->right = solve(post, in, ind, pos + 1, inEnd, n, nodeToind);
        root->left = solve(post, in, ind, instart, pos - 1, n, nodeToind);

        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {

        int n = post.size();
        int preInd = n - 1;

        map<int, int> nodeToind;

        createMap(nodeToind, in);

        TreeNode* ans = solve(post, in, preInd, 0, n - 1, n, nodeToind);

        return ans;
    }
};