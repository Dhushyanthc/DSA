class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_sum = nums[0];
        int max_sum = nums[0];
        int sum = abs(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            min_sum = min(nums[i], min_sum+nums[i]);
            max_sum = max(nums[i], max_sum+nums[i]);
            int v1 = abs(min_sum);
            int v2 = abs(max_sum);
            sum = max({sum, v1,v2});
        }
        return sum;
    }
};