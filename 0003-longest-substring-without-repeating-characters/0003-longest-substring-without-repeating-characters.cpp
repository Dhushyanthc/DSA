    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> str;

            int left = 0; 
            int maxlen = 0;

            for (int right = 0 ; right < s.size();right++ )
            {
                while (str.find(s[right]) != str.end())
                {
                    str.erase(s[left]);
                    left++;
                }

                str.insert(s[right]);
                maxlen = max(maxlen, right - left + 1);
            }
            
            return maxlen;
        }
    };
