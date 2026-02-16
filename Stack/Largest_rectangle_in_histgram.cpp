#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test Case 1:" << endl;
    cout << "Heights: [2, 1, 5, 6, 2, 3]" << endl;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights1) << endl;
    cout << "Expected: 10" << endl << endl;
    
    vector<int> heights2 = {2, 4};
    cout << "Test Case 2:" << endl;
    cout << "Heights: [2, 4]" << endl;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    vector<int> heights3 = {1};
    cout << "Test Case 3:" << endl;
    cout << "Heights: [1]" << endl;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> heights4 = {2, 1, 2};
    cout << "Test Case 4:" << endl;
    cout << "Heights: [2, 1, 2]" << endl;
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights4) << endl;
    cout << "Expected: 3" << endl;
    
    return 0;
}