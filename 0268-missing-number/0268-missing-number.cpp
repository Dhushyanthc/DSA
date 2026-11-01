class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = n*(n+1)/2;

        int sol = 0;

        for(int x:nums){
            sol += x;
        }

        return sum-sol;
    }
};