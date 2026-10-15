class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
    bool is_palindrome(string& s){
        int left = 0 ;
        int right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(int start, string& s){
        if(start == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = start; i < s.size(); i++){
            string sub = s.substr(start, i-start+1);

            if(is_palindrome(sub)){
                path.push_back(sub);
                solve(i+1,s);
                path.pop_back();
            }
        }
    }
};