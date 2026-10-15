class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, path, used, res);
        return res;
    }

    private:
    void dfs(vector<int>& nums, vector<int>& path,
             vector<bool>& used, vector<vector<int>>& res) {
        
        if (path.size() == nums.size()) {
            res.push_back(path);   
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;      

            used[i] = true;             
            path.push_back(nums[i]);

            dfs(nums, path, used, res); 

            path.pop_back();           
            used[i] = false;

           while((i+1) < nums.size() && nums[i]==nums[i+1])
            {
                i++;
            }
        }
    }
};