#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test Case 1:" << endl;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2], Target: 0" << endl;
    cout << "Index: " << sol.search(nums1, target1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2], Target: 3" << endl;
    cout << "Index: " << sol.search(nums2, target2) << endl;
    cout << "Expected: -1" << endl << endl;
    
    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Test Case 3:" << endl;
    cout << "Array: [1], Target: 0" << endl;
    cout << "Index: " << sol.search(nums3, target3) << endl;
    cout << "Expected: -1" << endl << endl;
    
    vector<int> nums4 = {3, 1};
    int target4 = 1;
    cout << "Test Case 4:" << endl;
    cout << "Array: [3, 1], Target: 1" << endl;
    cout << "Index: " << sol.search(nums4, target4) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}