#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int> res;
        unordered_map<int, int> map;

        for(int x : nums)
        {
            ++map[x];
        }
        for (auto& pair : map)
        {
            if (pair.second > n)
            {
                res.push_back(pair.first);
            }
        }
        return res;
        
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
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}