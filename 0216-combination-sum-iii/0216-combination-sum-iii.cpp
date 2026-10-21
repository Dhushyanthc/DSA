class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        solve(1, k, n, path);
        return res;
    }

    void solve(int start, int k, int remaining, vector<int>& path){
        if(remaining == 0 && path.size() == k){
            res.push_back(path);
        }

        for(int i = start; i <= 9; i++){
            path.push_back(i);
            solve(i+1, k, remaining - i,path);
            path.pop_back();
        }
    }
};