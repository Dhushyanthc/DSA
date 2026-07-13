class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<vector<int>> result;

         if (n < 3) return result;

        sort(nums.begin(), nums.end());

        for ( int k = 0; k < n - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = - (nums[k]);

            i = k + 1;
            j = n - 1;

            while (j>i)
            {
                if (nums[i] + nums[j] == target )
                {
                    result.push_back({nums[k], nums[i], nums[j]});

                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                    
                }else if ((nums[i]+nums[j]) > target)
                {
                    j--;
                }else if ((nums[i]+nums[j]) < target)
                {
                    i++;
                }
            }


        }

        return result;
        
    }
};
