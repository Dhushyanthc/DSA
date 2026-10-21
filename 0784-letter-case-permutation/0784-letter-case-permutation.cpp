class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }

    void solve(string& s, int index, vector<string>& ans) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        if (isdigit(s[index])) {
            solve(s, index + 1, ans);
            return;
        }
        s[index] = tolower(s[index]);
        solve(s, index + 1, ans);

        s[index] = toupper(s[index]);
        solve(s, index + 1, ans);
    }
};