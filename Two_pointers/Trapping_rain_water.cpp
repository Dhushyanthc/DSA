#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    res += leftMax - height[l];
                l++;
            } else {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    res += rightMax - height[r];
                r--;
            }
        }

        return res;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solution;
    cout << "Trapped rain water: " << solution.trap(height) << endl;

    return 0;
}
