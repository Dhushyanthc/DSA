/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);
        return ans;
    }

    int find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return 0;

        int left = find(root->left, p, q);
        int right = find(root->right, p, q);

        int self = 0;

        if (root == p || root == q)
            self = 1;

        int total = self + left + right;

        if (total == 2 && ans == NULL)
            ans = root;

        return total;
    }
};