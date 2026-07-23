class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = nums[0];
        int curr_maxsum = nums[0];
        int curr_minsum = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];

        for ( int i = 1; i < nums.size(); i++){
            total_sum+=nums[i];

            curr_maxsum = max(nums[i], curr_maxsum + nums[i]);
            maxsum = max(maxsum, curr_maxsum);

            curr_minsum = min(nums[i], curr_minsum + nums[i]);
            minsum = min(minsum, curr_minsum);
        }

        if(maxsum < 0){
                return maxsum;
            }

        
        return max(maxsum, total_sum - minsum);
    }
};