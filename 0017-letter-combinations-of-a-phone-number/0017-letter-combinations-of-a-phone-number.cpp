class Solution {
public:

    unordered_map<char, string> map;
    vector<string> res;

    vector<string> letterCombinations(string digits) {

        res.clear();
        map.clear();

        if (digits.empty()) return res;

        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        int n = digits.size();
        int idx = 0;
        string dairy = "";
        backtrack(digits, idx, n, dairy);
        return res;
    }


    void backtrack(string &digits, int idx, int n, string &dairy){
        if (idx == n){
            res.push_back(dairy);
            return;
        }

        string choice = map[digits[idx]];
        for ( int j = 0 ; j < choice.size(); j++ )
        {
            dairy.push_back(choice[j]);
            backtrack(digits, idx + 1, n, dairy);
            dairy.pop_back();
        }
    }
};