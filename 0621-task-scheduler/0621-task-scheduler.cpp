class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for (char x : tasks) freq[x]++;

        priority_queue<int> pq;
        for (auto &[task, count] : freq) pq.push(count);

        int ans = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int ran = 0;

            for (int i = 0; i <= n && !pq.empty(); i++) {
                int count = pq.top();
                pq.pop();
                if (--count > 0) temp.push_back(count);
                ran++;
            }

            for (int c : temp) pq.push(c);
            ans += pq.empty() ? ran : n + 1;
        }
        return ans;
    }
};