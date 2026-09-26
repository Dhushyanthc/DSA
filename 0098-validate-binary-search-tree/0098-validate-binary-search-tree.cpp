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
    bool isValidBST(TreeNode* root) {
    inorder(root);
    return solve(root);
    }
    vector<int> in;
    bool solve(TreeNode* root){
        for(int i = 1; i < in.size(); i++){
            if(in[i] <= in[i-1]) return false;
        }
        return true;
    }

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
};
