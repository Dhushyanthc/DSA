#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> map;

        for (int i=0; i<nums.size(); i++)
        {
            int need = target - nums[i];
            if (map.find(need) != map.end())
            {
                return {map[need], i};
            }
            map[nums[i]]=i;
        }
        return {};
        
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test 1: nums = [2, 7, 11, 15], target = 9" << endl;
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test 2: nums = [3, 2, 4], target = 6" << endl;
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Test 3: nums = [3, 3], target = 6" << endl;
    cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
    
    return 0;
}