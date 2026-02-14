#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0) return 0;

        int left = 0;
        unordered_map<char, int> index;
        int max_len = 0; 

        for (int right = 0; right < s.size(); right++)
        {
            if (index.count(s[right])){
                left = max(left, index[s[right]] + 1);
            }

            index[s[right]] = right;
            max_len = max(max_len, right - left + 1);

        }

        return max_len;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "abcabcbb";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s1) << endl;
    
    // Test case 2
    string s2 = "bbbbb";
    cout << "\nInput: \"" << s2 << "\"" << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s2) << endl;
    
    // Test case 3
    string s3 = "pwwkew";
    cout << "\nInput: \"" << s3 << "\"" << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s3) << endl;
    
    // Test case 4
    string s4 = "";
    cout << "\nInput: \"" << s4 << "\"" << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s4) << endl;
    
    return 0;
}
