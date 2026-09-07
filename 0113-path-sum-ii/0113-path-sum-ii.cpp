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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        PathSum(root, sum, targetSum);
        return res;
    }
    vector<int> dairy;
   void PathSum(TreeNode* root,int sum, int targetSum){
        if(root == NULL) return;


        sum = sum + root->val;
        dairy.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum)
            res.push_back(dairy);
            dairy.pop_back();
            return;
        }
        
        PathSum(root->left, sum, targetSum);
        PathSum(root->right, sum, targetSum);
        dairy.pop_back();
    }
};