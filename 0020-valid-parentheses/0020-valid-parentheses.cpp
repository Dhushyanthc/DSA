class Solution {
public:
    bool isValid(string s) {
        vector<char> str;

    for (char x : s) {
        if (x == '(' || x == '{' || x == '[') {
            str.push_back(x);
        } 
        else if (x == ')') {
            if (str.empty() || str.back() != '(') return false;
            str.pop_back();
        } 
        else if (x == '}') {
            if (str.empty() || str.back() != '{') return false;
            str.pop_back();
        } 
        else if (x == ']') {
            if (str.empty() || str.back() != '[') return false;
            str.pop_back();
        } 
        else {
            return false;
        }
    }
        return str.empty();
    }
};
