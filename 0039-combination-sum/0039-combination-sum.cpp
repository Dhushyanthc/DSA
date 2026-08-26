class Solution {
public:

    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int> dairy;
        int idx =0;
        int sum = 0;
        back(candidates, n, idx, dairy, sum, target, result);
        return result;
    }

    void back(vector<int>& candidates, int n, int idx, vector<int>& dairy,int sum, int target, vector<vector<int>>& result ){

        if(sum == target){
            result.push_back(dairy);
            return;
        }

        if (idx >= n) return;

        back(candidates, n, idx + 1, dairy, sum, target, result);

        if(sum + candidates[idx] <= target){
            dairy.push_back(candidates[idx]);
            back(candidates, n, idx, dairy, sum + candidates[idx], target, result);
            dairy.pop_back();
        }
        return;
    }
};