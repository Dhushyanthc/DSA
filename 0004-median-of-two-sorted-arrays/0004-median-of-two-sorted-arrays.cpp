class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        // Increase nums1 size to hold both arrays
        nums1.resize(m + n);

        // Pointers
        int i = m - 1;       // Last element of original nums1
        int j = n - 1;       // Last element of nums2
        int k = m + n - 1;   // Last position of nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        // Copy remaining elements of nums2
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // Find median
        int len = m + n;

        if (len % 2 == 1) {
            // Odd
            return nums1[len / 2];
        }
        else {
            // Even
            return (nums1[len / 2] + nums1[len / 2 - 1]) / 2.0;
        }
    }
};