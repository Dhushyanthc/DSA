class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int x:stones) pq.push(x);

        while(pq.size() > 1){
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            pq.push(abs(num1-num2));
        }
        return pq.top();
    }
};