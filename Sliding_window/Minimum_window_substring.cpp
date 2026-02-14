#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size()) return "";

        unordered_map<char, int> target, window;

        for (char c : t)
            target[c]++;

        int required = target.size();
        int formed = 0;

        int left = 0;
        int min_len = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c]) {
                formed++;
            }

            while (formed == required) {

                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start = left;
                }

                char left_char = s[left];
                window[left_char]--;

                if (target.count(left_char) &&
                    window[left_char] < target[left_char]) {
                    formed--;
                }

                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: s = "ADOBECODEBANC", t = "ABC"
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test 1: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Result: \"" << solution.minWindow(s1, t1) << "\"" << endl;
    cout << "Expected: \"BANC\"" << endl << endl;
    
    // Test case 2: s = "a", t = "a"
    string s2 = "a";
    string t2 = "a";
    cout << "Test 2: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Result: \"" << solution.minWindow(s2, t2) << "\"" << endl;
    cout << "Expected: \"a\"" << endl << endl;
    
    // Test case 3: s = "a", t = "aa"
    string s3 = "a";
    string t3 = "aa";
    cout << "Test 3: s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Result: \"" << solution.minWindow(s3, t3) << "\"" << endl;
    cout << "Expected: \"\"" << endl;
    
    return 0;
}
