class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;

        for (int a : arr) {
            pq.push({abs(a - x), a});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty()) {
            auto x = pq.top();
            res.push_back(x.second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};