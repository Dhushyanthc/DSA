class Solution {
public:

    int count = 0;
    int countSubstrings(string s) {
         int n = s.size();

        for(int i = 0; i < n; i++) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }

        return count;
    }

    void expand(int left, int right, string& s) {
        if(left < 0 || right >= s.size())
            return;

        if(s[left] != s[right])
            return;

        count++;
        expand(left - 1, right + 1, s);
    }
};