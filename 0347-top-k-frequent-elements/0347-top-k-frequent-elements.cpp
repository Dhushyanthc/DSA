class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> map;

        for (int x:nums)
        {
            map[x]++;
        }

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > minheap;

        for (auto& p: map)
        {
            minheap.push({p.second,p.first});
            if (minheap.size()>k)
            {
                minheap.pop();
            }
        }

        vector<int> res;

        while(!minheap.empty())
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        return res;
        
    }
};