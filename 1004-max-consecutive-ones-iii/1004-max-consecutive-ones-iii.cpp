class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int count = 0, res = INT_MIN;
        for ( int high = 0; high < nums.size(); high++){
            if(nums[high]== 0)
                count++;
            while(count > k){
                if (nums[low] == 1){
                    low++;
                }else{
                    low++;
                    count--;
                }
            }
            int len = high - low + 1;
            res = max(res, len);
        }

        return (res == INT_MIN)?0:res;
    }
};