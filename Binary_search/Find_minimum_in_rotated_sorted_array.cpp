#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0;
        int right = nums.size() - 1;

        while ( left < right)
        {
            int mid = left + (right - left)/2;

            if (nums[mid] >= nums[right])
            {
                left = mid + 1;
               
            }else
            {
                right = mid;
            }
        }
        return nums[left];
        
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1:" << endl;
    cout << "Array: [3, 4, 5, 1, 2]" << endl;
    cout << "Minimum: " << sol.findMin(nums1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 2:" << endl;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Minimum: " << sol.findMin(nums2) << endl;
    cout << "Expected: 0" << endl << endl;
    
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Test Case 3:" << endl;
    cout << "Array: [11, 13, 15, 17]" << endl;
    cout << "Minimum: " << sol.findMin(nums3) << endl;
    cout << "Expected: 11" << endl << endl;
    
    vector<int> nums4 = {2, 1};
    cout << "Test Case 4:" << endl;
    cout << "Array: [2, 1]" << endl;
    cout << "Minimum: " << sol.findMin(nums4) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}