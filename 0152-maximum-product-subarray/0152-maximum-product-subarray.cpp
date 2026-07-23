class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_product = nums[0];
        int max_product = nums[0];
        int global_prod = nums[0];

        for ( int i = 1; i < nums.size(); i++){

            if (nums[i] < 0){
                swap(min_product, max_product);
            }
            min_product = min(nums[i], min_product*nums[i]);
            max_product = max(nums[i], max_product*nums[i]);
            global_prod = max(max_product, global_prod);
        }

        return global_prod;
    }
};