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
   
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;

         if (root == nullptr) {
            return res; 
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int lvlsize = q.size();
            vector<int> tmp;
            tmp.reserve(lvlsize);
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};