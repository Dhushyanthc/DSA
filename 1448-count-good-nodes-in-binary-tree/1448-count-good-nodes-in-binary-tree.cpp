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
public:
    int res = 0;
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return res;
    }
    void solve(TreeNode* root, int maxval){
        if(root == nullptr) return;

        if(maxval <= root->val) res++;

        maxval = max(maxval, root->val);

        solve(root->left, maxval);
        solve(root->right, maxval);

    }
};
