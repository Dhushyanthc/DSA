#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int len = s.size();
        int n = words.size();
        int wordSize = words[0].size(); // Corrected word length
        int windowSize = wordSize * n;

        if (len < windowSize) return ans;

        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        // We only need to run the sliding window shifted wordSize times
        for (int i = 0; i < wordSize; ++i) {
            int low = i;
            unordered_map<string, int> curr;
            int count = 0; // Tracks total valid words in current window

            for (int high = i; high + wordSize <= len; high += wordSize) {
                string word = s.substr(high, wordSize);

                if (freq.count(word)) {
                    curr[word]++;
                    count++;

                    // If we have more occurrences than needed, shrink from the left
                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(low, wordSize);
                        curr[leftWord]--;
                        count--;
                        low += wordSize;
                    }

                    // Complete valid window found
                    if (count == n) {
                        ans.push_back(low);
                    }
                } else {
                    // Invalid word encountered: reset window completely
                    curr.clear();
                    count = 0;
                    low = high + wordSize;
                }
            }
        }
        return ans;
    }
};
