class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        current.clear();

        solve(nums, 0);
        return ans;
    }

    void solve(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(current);
            return;
        }

       
        current.push_back(nums[i]);
        solve(nums, i + 1);

        
        current.pop_back();
        solve(nums, i + 1);
    }
};