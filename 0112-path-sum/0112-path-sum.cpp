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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return PathSum(root, sum, targetSum);
    }

    bool PathSum(TreeNode* root,int sum, int targetSum){
        if(root == NULL) return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum) return true;
        }
        return PathSum(root->left, sum, targetSum) ||
               PathSum(root->right, sum, targetSum);
    }
};