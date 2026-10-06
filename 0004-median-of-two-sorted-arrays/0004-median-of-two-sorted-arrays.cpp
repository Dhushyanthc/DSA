class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<double> res;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            res.push_back(nums2[j]);
            j++;
        }

        int len = res.size();
        if (len%2 == 0){
            double i1 = res[len/2];
            double i2 = res[(len/2-1)];
            return (i1+i2)/2;
        }else{
            return res[len/2];
        }
    }
};
