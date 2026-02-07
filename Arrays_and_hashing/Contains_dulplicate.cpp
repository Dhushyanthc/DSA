#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freq;

        for (int x : nums)
        {
            if (freq.count(x))
            {
                return true;
            }
            freq.insert(x);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    
    bool result = sol.hasDuplicate(nums);
    cout << "Has duplicate: " << (result ? "true" : "false") << endl;
    
    return 0;
}