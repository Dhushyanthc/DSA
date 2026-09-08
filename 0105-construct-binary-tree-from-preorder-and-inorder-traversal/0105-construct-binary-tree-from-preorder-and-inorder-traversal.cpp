class Solution {
public:
    unordered_map<int, int> map;
    int idx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return fun(preorder, 0, inorder.size() - 1);
    }

    TreeNode* fun(vector<int>& preorder, int low, int high) {

        if (low > high)
            return NULL;

        int id = map[preorder[idx]];

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        node->left = fun(preorder, low, id - 1);
        node->right = fun(preorder, id + 1, high);

        return node;
    }
};