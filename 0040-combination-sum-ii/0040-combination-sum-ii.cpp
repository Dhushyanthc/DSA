class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates);
        return ans;
    }
    void solve(int start, int remaining ,vector<int>& candidates ){
        if(remaining == 0){
            ans.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(candidates[i]>remaining) continue;
            path.push_back(candidates[i]);
            solve(i+1, remaining - candidates[i],candidates);
            path.pop_back();
            while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        }
     }
};

    
    

   