class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        solve(s,0,path);
        return ans;

    }

    bool is_valid(string segment) {
        if (segment.size() > 1 && segment[0] == '0')
            return false;

        int num = stoi(segment);
        return num <= 255;
    }

    void solve(string s, int start, vector<string>& path){
        if (path.size() == 4) {
                if (start == s.size()) {
                    string c = path[0] + "." + path[1] + "." +path[2] + "." + path[3];
                    ans.push_back(c);
                }
                return;
        }

        for(int i = start;i < s.size()&&i<start+3;i++){

            string segment = s.substr(start, i-start+1);

            if(is_valid(segment)){
                path.push_back(segment);
                solve(s, i+1,path);
                path.pop_back();
            }
        }
    }
};