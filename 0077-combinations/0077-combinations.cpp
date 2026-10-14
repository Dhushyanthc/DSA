class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        current.clear();
        solve(1,n,k);
        return ans;
    }

    void solve(int i, int n, int k){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        if(i > n) return;

        current.push_back(i);
        solve(i+1,n,k);
        current.pop_back();
        solve(i+1,n,k);
    }
};