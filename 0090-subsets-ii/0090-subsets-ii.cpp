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

    void solve(vector<int>& nums, int i) {
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        solve(nums, i + 1);
        current.pop_back();

        int idx = i + 1;
        while(idx<nums.size() && nums[idx] == nums[i]){
            idx++;
        }
        solve(nums,idx);
    }
};

