#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        double max_sum = 0;
        double window_sum = 0;

        while (i < k)
        {
            window_sum += nums[i];
            i++;
        }

        max_sum = window_sum;
        
        for (int i = k; i < n; i++)
        {
            window_sum -= nums[i-k];
            window_sum += nums[i];
            max_sum = max(max_sum, window_sum);
        }

        return max_sum/k;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution solution;
    cout << "Maximum average: " << solution.findMaxAverage(nums, k) << endl;

    return 0;
}
