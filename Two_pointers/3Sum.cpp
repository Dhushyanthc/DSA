#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<vector<int>> result;

         if (n < 3) return result;

        sort(nums.begin(), nums.end());

        for ( int k = 0; k < n - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = - (nums[k]);

            i = k + 1;
            j = n - 1;

            while (j>i)
            {
                if (nums[i] + nums[j] == target )
                {
                    result.push_back({nums[k], nums[i], nums[j]});

                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                    
                }else if ((nums[i]+nums[j]) > target)
                {
                    j--;
                }else if ((nums[i]+nums[j]) < target)
                {
                    i++;
                }
            }


        }

        return result;
        
    }
};

void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[";
    for (int i = 0; i < triplets.size(); i++) {
        cout << "[";
        for (int j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j];
            if (j < triplets[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < triplets.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Test case 1: [-1, 0, 1, 2, -1, -4]
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1: [-1, 0, 1, 2, -1, -4]" << endl;
    cout << "Triplets that sum to 0: ";
    printTriplets(sol.threeSum(nums1));
    cout << endl;
    
    // Test case 2: [0, 0, 0, 0]
    vector<int> nums2 = {0, 0, 0, 0};
    cout << "Test 2: [0, 0, 0, 0]" << endl;
    cout << "Triplets that sum to 0: ";
    printTriplets(sol.threeSum(nums2));
    cout << endl;
    
    // Test case 3: [-2, 0, 1, 1, 2]
    vector<int> nums3 = {-2, 0, 1, 1, 2};
    cout << "Test 3: [-2, 0, 1, 1, 2]" << endl;
    cout << "Triplets that sum to 0: ";
    printTriplets(sol.threeSum(nums3));
    cout << endl;
    
    // Test case 4: [-1, -1, -1, 0, 1, 2]
    vector<int> nums4 = {-1, -1, -1, 0, 1, 2};
    cout << "Test 4: [-1, -1, -1, 0, 1, 2]" << endl;
    cout << "Triplets that sum to 0: ";
    printTriplets(sol.threeSum(nums4));
    
    return 0;
}
