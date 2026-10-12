class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty()||nums2.empty()||k<=0) return ans;

        using node = pair<int, pair<int,int>>;
        priority_queue<node, vector<node>, greater<node>> pq;

        for(int i = 0; i < min(k, (int)nums1.size()); i++){
            pq.push({nums1[i] + nums2[0], {i,0}});
        }

        while(k > 0 && !pq.empty()){
            auto current = pq.top();
            pq.pop();

            int i = current.second.first;
            int j = current.second.second;
            ans.push_back({nums1[i], nums2[j]});

            if(j+1 < nums2.size()){
                pq.push({
                    nums1[i] + nums2[j+1], {i,j+1}
                });
            }
            k--;
        }
        return ans;
    }
};