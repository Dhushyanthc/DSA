#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        for (vector<int> row : matrix)
        {
            if (target > row[n])
            {
                continue;
            }else
            {
                int left = 0;
                int right = (row.size()==1)?0:n;
                while(left <= right)
                {
                    int mid = left + (right - left)/2;
                    if (target == row[mid])
                    {
                        return true;
                    }
                    else if (target < row[mid])
                    {
                        right = mid - 1;
                    }else
                    {
                        left = mid + 1;
                    }
                }
            }
        }

        return false;
        
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    cout << "Test Case 1:" << endl;
    cout << "Matrix: [[1,3,5,7],[10,11,16,20],[23,30,34,60]], Target: 3" << endl;
    cout << "Found: " << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    cout << "Test Case 2:" << endl;
    cout << "Matrix: [[1,3,5,7],[10,11,16,20],[23,30,34,60]], Target: 13" << endl;
    cout << "Found: " << (sol.searchMatrix(matrix2, target2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    vector<vector<int>> matrix3 = {{1}};
    int target3 = 1;
    cout << "Test Case 3:" << endl;
    cout << "Matrix: [[1]], Target: 1" << endl;
    cout << "Found: " << (sol.searchMatrix(matrix3, target3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    vector<vector<int>> matrix4 = {{1, 3}, {5, 7}};
    int target4 = 5;
    cout << "Test Case 4:" << endl;
    cout << "Matrix: [[1,3],[5,7]], Target: 5" << endl;
    cout << "Found: " << (sol.searchMatrix(matrix4, target4) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}