#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> map;

        for (string s:strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;

        for (auto& pair: map)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "ate", "bat", "tab", "cat"};
    vector<vector<string>> result1 = sol.groupAnagrams(strs1);
    cout << "Test 1: strs = [eat, tea, ate, bat, tab, cat]" << endl;
    cout << "Output:" << endl;
    for (auto& group : result1) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = sol.groupAnagrams(strs2);
    cout << "Test 2: strs = [\"\"]" << endl;
    cout << "Output: [[]]" << endl << endl;
    
    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = sol.groupAnagrams(strs3);
    cout << "Test 3: strs = [a]" << endl;
    cout << "Output: [[a]]" << endl;
    
    return 0;
}
