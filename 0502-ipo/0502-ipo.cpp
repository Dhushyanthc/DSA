class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       vector<pair<int,int>> proj;
       for(int i = 0; i < profits.size(); i++){
        proj.push_back({capital[i], profits[i]});
       }
        priority_queue<int> maxheap;
        sort(proj.begin(), proj.end());
        int idx = 0;
        while(k--){
            while(idx<profits.size()){
                if(proj[idx].first > w) break;
                maxheap.push(proj[idx].second);
                idx++;
            }
                if(maxheap.empty()) return w;
                w+=maxheap.top();
                maxheap.pop();
            }

            return w;
       }
    
};