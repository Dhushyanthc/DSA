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
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = solve(root, p,q);
        return ans;
    }

    int solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return 0;

        int l = solve(root->left, p, q);
        int r = solve(root->right, p, q);

        int self = 0;
        if(root == p || root == q) self = 1;

        int total = self + l + r;
        
        if(total == 2 && ans == nullptr) ans = root;

        return total;
    }

};
