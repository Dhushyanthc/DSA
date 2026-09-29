class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        
        vector<vector<int>> result;

        sort(interval.begin(), interval.end());

        result.push_back(interval[0]);

        for ( int i = 1; i < interval.size(); i++)
        {
            vector<int>& last = result.back();

            int last_start = last[0];
            int last_end = last[1];

            int curr_start = interval[i][0];
            int curr_end = interval[i][1];

            if (curr_start <= last_end)
            {
                last[1] = max(last_end, curr_end);
            }
            else 
            {
                result.push_back(interval[i]);
            }
        }
        return result;
    }
};