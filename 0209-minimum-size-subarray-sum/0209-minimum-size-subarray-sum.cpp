class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int high = 0, low = 0;
        int sum = 0;
        int min_len = INT_MAX;
        while(high < nums.size()){
            sum += nums[high];
            while(sum >= target){
                int len = high - low + 1;
                min_len = min(min_len, len);
                sum -= nums[low];
                low++;
            }
            high++;
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};