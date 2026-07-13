class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[j] ==  nums[j-1]){
                j++;
                continue;
            }else{
                nums[++i] = nums[j];
                j++;
            }
        }
        return ++i;
    }
};