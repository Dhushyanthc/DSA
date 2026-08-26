class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        back(nums, n, idx, res);
        return res;
    }

    void back(vector<int>& nums, int n, int idx, vector<vector<int>>& res ){
        if (idx == n){
            res.push_back(nums);
            return;
        }

        for ( int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            back(nums, n, idx+1, res);
            swap(nums[idx], nums[i]);
        }
        return;
    }
};