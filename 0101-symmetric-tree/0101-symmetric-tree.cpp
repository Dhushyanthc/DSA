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
    bool isSymmetric(TreeNode* root) {
        return sym(root->left, root->right);
    }
    bool sym(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        if(t1->val != t2->val) return false;

        bool c1 = sym(t1->left, t2->right);
        bool c2 = sym(t1->right, t2->left);
        if(c1== true && c2 == true) return true;
        return false;
    }
};