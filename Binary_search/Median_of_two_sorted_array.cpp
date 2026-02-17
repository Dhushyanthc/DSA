#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int half = total / 2;

        int left = 0, right = n;

        while (true) {
            int i = (left + right) / 2;   
            int j = half - i;            

            int aleft  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int aright = (i < n) ? nums1[i]     : INT_MAX;
            int bleft  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int bright = (j < m) ? nums2[j]     : INT_MAX;

            if (aleft <= bright && bleft <= aright) {
                
                if (total % 2)
                    return min(aright, bright);
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if (aleft > bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    cout << "Test Case 1:" << endl;
    cout << "Array 1: [1, 3], Array 2: [2]" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums1_1, nums2_1) << endl;
    cout << "Expected: 2" << endl << endl;
    
    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Test Case 2:" << endl;
    cout << "Array 1: [1, 2], Array 2: [3, 4]" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums1_2, nums2_2) << endl;
    cout << "Expected: 2.5" << endl << endl;
    
    vector<int> nums1_3 = {};
    vector<int> nums2_3 = {1};
    cout << "Test Case 3:" << endl;
    cout << "Array 1: [], Array 2: [1]" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums1_3, nums2_3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> nums1_4 = {1, 3, 5};
    vector<int> nums2_4 = {2, 4, 6};
    cout << "Test Case 4:" << endl;
    cout << "Array 1: [1, 3, 5], Array 2: [2, 4, 6]" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums1_4, nums2_4) << endl;
    cout << "Expected: 3.5" << endl;
    
    return 0;
}