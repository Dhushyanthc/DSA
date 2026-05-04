#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroes = 0;
        int maxlen = 0; 
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0) zeroes++;

            while(zeroes>1)
            {
                if (nums[left] == 0) zeroes--;
                left++;
            }

            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    cout << "Longest subarray of 1s after deleting one element: "
         << solution.longestSubarray(nums) << endl;

    return 0;
}
