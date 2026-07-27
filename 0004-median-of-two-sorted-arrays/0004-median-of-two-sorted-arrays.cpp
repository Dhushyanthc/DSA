class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Ensure nums1 is smaller
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int half = total / 2;

        int left = 0, right = n;

        while (true) {
            int i = (left + right) / 2;   // partition in nums1
            int j = half - i;             // partition in nums2

            int aleft  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int aright = (i < n) ? nums1[i]     : INT_MAX;
            int bleft  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int bright = (j < m) ? nums2[j]     : INT_MAX;

            if (aleft <= bright && bleft <= aright) {
                // correct partition
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
