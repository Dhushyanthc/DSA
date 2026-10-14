class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        current.clear();

        solve(nums, 0);
        return ans;
    }

    void solve(vector<int>& nums, int start) {
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);
            solve(nums, i + 1);
            current.pop_back();
        }
    }
};