class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }

    int solve(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int left = solve(root->left);
        if(left == -1)
            return -1;

        int right = solve(root->right);
        if(right == -1)
            return -1;

        if(abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }
};