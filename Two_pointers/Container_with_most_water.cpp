#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;

        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            max_area = max(max_area, h * w);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_area;
    }
};

int main() {
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(height);

    cout << "Maximum Area: " << result << endl;

    return 0;
}
