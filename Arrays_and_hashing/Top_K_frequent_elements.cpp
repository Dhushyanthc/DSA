#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        for (int x:nums)
        {
            map[x]++;
        }

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > minheap;

        for (auto& p: map)
        {
            minheap.push({p.second,p.first});
            if (minheap.size()>k)
            {
                minheap.pop();
            }
        }

        vector<int> res;

        while(!minheap.empty())
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Test 1: nums = [1, 1, 1, 2, 2, 3], k = 2" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = sol.topKFrequent(nums2, k2);
    cout << "Test 2: nums = [1], k = 1" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {4, 1, 1, 1, 2, 2, 3};
    int k3 = 2;
    vector<int> result3 = sol.topKFrequent(nums3, k3);
    cout << "Test 3: nums = [4, 1, 1, 1, 2, 2, 3], k = 2" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
