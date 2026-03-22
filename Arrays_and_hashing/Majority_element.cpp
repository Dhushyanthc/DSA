#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> map;
        int n = nums.size()/2;

        for (int x:nums)
        {
            ++map[x];
        }
        for (auto& pair: map)
        {
            if (pair.second > n) return pair.first;  
        }
        return 0;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;

    return 0;
}