#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);

            while ((right - left + 1) - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << solution.characterReplacement(s1, k1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test case 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << solution.characterReplacement(s2, k2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test case 3
    string s3 = "ABCDE";
    int k3 = 1;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << solution.characterReplacement(s3, k3) << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}
