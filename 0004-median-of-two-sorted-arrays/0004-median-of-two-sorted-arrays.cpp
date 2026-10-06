class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int k = n + m;

        int low = 0;
        int high = n;

        int half = (k + 1) / 2;

        while (low <= high) {

            int i = (low + high) / 2;

            int j = half - i;

            int aleft  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int aright = (i < n) ? nums1[i] : INT_MAX;

            int bleft  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int bright = (j < m) ? nums2[j] : INT_MAX;


            if (aleft > bright) {
                high = i - 1;
            }

            else if (bleft > aright) {
                low = i + 1;
            }

            else {

                if (k % 2 == 1) {
                    return max(aleft, bleft);
                }
                return (max(aleft, bleft)
                        + min(aright, bright)) / 2.0;
            }
        }

        return 0.0;
    }
};