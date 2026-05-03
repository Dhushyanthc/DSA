#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0;
        int r = numbers.size() - 1;
        if (numbers.size() > 1)
        {
        while (l<r)
        {
            int sum = numbers[l] + numbers[r];

            if (sum == target)
            {
                l++;
                r++;
                res.push_back(l);
                res.push_back(r);
                return res;
            }else if (sum < target)
            {
                l++;
            }else {
                r--;
            }
        }

        }else
        {
            return {};
        }

        return res;
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
