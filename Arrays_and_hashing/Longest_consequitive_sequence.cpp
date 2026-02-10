#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int max_length = 1;
        int i=1;
        int new_length = 1;

        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(),nums.end());
        
        while (i != nums.size())
        {
           
           

            if (nums[i] == nums[i-1] + 1)
            {
                new_length++;
            } else if (nums[i] == nums[i-1])
            {
                i++;
                continue;
            }else
            {
                new_length = 1;
            }

            max_length = max(max_length, new_length);

            i++;
            
        }

        return max_length;
        
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: [100, 4, 200, 1, 3, 2]" << endl;
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums1) << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]" << endl;
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums2) << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {};
    cout << "Test 3: []" << endl;
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums3) << endl << endl;
    
    // Test case 4
    vector<int> nums4 = {9, 1,4, 7, 3, 2, 8, 5, 6};
    cout << "Test 4: [9, 1, 4, 7, 3, 2, 8, 5, 6]" << endl;
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums4) << endl;
    
    return 0;
}
