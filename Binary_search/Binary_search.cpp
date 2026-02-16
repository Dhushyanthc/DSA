#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;

            if ( target == nums[mid])
            {
                return mid;
            }else if(target < nums[mid])
            {
                right = mid - 1;
            }else 
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << "Test Case 1:" << endl;
    cout << "Array: [-1, 0, 3, 5, 9, 12], Target: 9" << endl;
    cout << "Index: " << sol.search(nums1, target1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Array: [-1, 0, 3, 5, 9, 12], Target: 2" << endl;
    cout << "Index: " << sol.search(nums2, target2) << endl;
    cout << "Expected: -1" << endl << endl;
    
    vector<int> nums3 = {5};
    int target3 = 5;
    cout << "Test Case 3:" << endl;
    cout << "Array: [5], Target: 5" << endl;
    cout << "Index: " << sol.search(nums3, target3) << endl;
    cout << "Expected: 0" << endl << endl;
    
    vector<int> nums4 = {2, 5, 8, 12, 19};
    int target4 = 12;
    cout << "Test Case 4:" << endl;
    cout << "Array: [2, 5, 8, 12, 19], Target: 12" << endl;
    cout << "Index: " << sol.search(nums4, target4) << endl;
    cout << "Expected: 3" << endl;
    
    return 0;
}