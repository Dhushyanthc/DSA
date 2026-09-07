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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        PathSum(root, sum);
        return res;
    }
    void PathSum(TreeNode* root,int sum){
        if(root == NULL) return;

        sum = sum*10 + root->val;

        if(root->left == NULL && root->right == NULL){
            res += sum;
        }
        PathSum(root->left, sum);
        PathSum(root->right, sum);
    }
};