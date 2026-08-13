class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;

        for (string x:words)
        {
            map[x]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        decltype(comp)
        > minheap(comp);

        for (auto& p: map)
        {
            minheap.push({p.second,p.first});
            if (minheap.size()>k)
            {
                minheap.pop();
            }
        }

        vector<string> res;

        while(!minheap.empty())
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};