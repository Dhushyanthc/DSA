class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> proj;
        int n = profits.size();

        for(int i = 0; i < n; i++){
            proj.push_back({capital[i], profits[i]});
        }

        sort(proj.begin(), proj.end());
        int idx = 0;
        priority_queue<int> pq;

        while(k--){
            while(idx < n){
                if(proj[idx].first > w) break;
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};