class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int max_dif = 10000;
        int res_sum = 0;

        if (nums.size() == 3) return nums[0]+nums[1]+nums[2];

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++){
            int j = i + 1;
            int k = nums.size()-1;

            while(j<k){
            int sum = nums[i]+nums[j]+nums[k];

            int dif = abs(sum - target);
            if (dif < max_dif){
                max_dif = dif;
                res_sum = sum;
            }

            if ( sum < target)
                j++;
            else 
                k--;
            
        }
        }

        return res_sum;
    }
};