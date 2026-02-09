#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> res(n, 1);

    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] = res[i] * suffix;
        
        suffix *= nums[i];
    }

    return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = sol.productExceptSelf(nums1);
    cout << "Input: [1, 2, 3, 4]" << endl;
    cout << "Output: ";
    for(int num : result1) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 3, 4, 5};
    vector<int> result2 = sol.productExceptSelf(nums2);
    cout << "Input: [2, 3, 4, 5]" << endl;
    cout << "Output: ";
    for(int num : result2) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {-1, 1, 0, -3, 3};
    vector<int> result3 = sol.productExceptSelf(nums3);
    cout << "Input: [-1, 1, 0, -3, 3]" << endl;
    cout << "Output: ";
    for(int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
