class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size();
        int total_sum = 0;

        for(int i = 0; i < len; i++){
            int total = (i+1)*(len-i);
            int odd_subarray = (total+1)/2;
            total_sum += arr[i]*odd_subarray;
        }

        return total_sum;
    }
};