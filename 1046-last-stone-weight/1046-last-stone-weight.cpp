class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int x:stones){
            pq.push(x);
        }

        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(pq.empty()) return a;
            int b = pq.top();
            pq.pop();
            if(a != b){
                pq.push(abs(a-b));
                if(pq.empty()) return abs(a-b);
            }
        }
        return 0;
    }
};