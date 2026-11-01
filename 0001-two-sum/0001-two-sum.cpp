class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int ele = target - nums[i];
            if(map.find(ele) != map.end()){
                return {i,map[ele]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};