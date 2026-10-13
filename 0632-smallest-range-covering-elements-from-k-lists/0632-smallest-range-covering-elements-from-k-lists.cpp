class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using node = tuple<int,int,int>;
        priority_queue<node, vector<node>, greater<node>> pq;
        int current_max = nums[0][0];

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], i, 0});
            current_max = max(current_max, nums[i][0]);
        }

        int gap = INT_MAX;
        int best_start = 0;
        int best_end = 0;

        while(true){
            auto [value, listidx, currentidx] = pq.top();
            pq.pop();

            int current_gap = current_max - value;

            if(current_gap < gap || current_gap == gap && value < best_start){
                gap = current_gap;
                best_start = value;
                best_end = current_max;
            }

            int next_idx = currentidx + 1;
            if (next_idx == nums[listidx].size()) {
                break;
            }
            int next_value = nums[listidx][next_idx];

            pq.push({next_value, listidx, next_idx});
            current_max = max(current_max, next_value);
        }

        return {best_start, best_end};


    }
};