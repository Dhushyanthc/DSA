class Solution {
public:
    string ans = "";

    string longestPalindrome(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }

        return ans;
    }

    void expand(int left, int right, string& s) {
        if(left < 0 || right >= s.size())
            return;

        if(s[left] != s[right])
            return;

        if(right - left + 1 > ans.size()) {
            ans = s.substr(left, right - left + 1);
        }

        expand(left - 1, right + 1, s);
    }
};