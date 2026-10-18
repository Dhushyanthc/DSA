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
        vector<int> path;
        solve(root, targetSum, sum, path);
        return res;
    }
    void solve(TreeNode* root, int targetSum, int sum, vector<int>& path){
        if(root==NULL) return;
        sum+= root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum)
                res.push_back(path);
        }
        solve(root->left, targetSum, sum, path);
        solve(root->right, targetSum, sum, path);
        path.pop_back();

    }
};