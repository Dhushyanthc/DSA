class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentsum = nums[0];
        int maxsum = nums[0];

        for ( int i =1 ; i < nums.size(); i++)
        {
            currentsum = max(nums[i], currentsum + nums[i]);
            maxsum = max(maxsum, currentsum);
        }
        return maxsum;
    }
};