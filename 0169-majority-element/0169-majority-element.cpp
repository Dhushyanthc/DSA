class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> freq;

        int max=0;
        int maxvalue =0;

        for (int x:nums)
        {
            freq[x]++;

            if (freq[x] > max)
            {
                max = freq[x];
                maxvalue = x;
            }

        }
       int n = (nums.size()/2 - 1);
        if (max > n)
        {
            return maxvalue;
        }
        return 0;
    }
};