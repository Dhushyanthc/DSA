class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = arr[0]; 
        int res = arr[0];
        
        for(int i = 1; i < n; i++) {
            int prev_nodelete = nodelete;
            
            nodelete = max(nodelete + arr[i], arr[i]);
            onedelete = max(onedelete + arr[i], prev_nodelete);
            
            res = max({res, nodelete, onedelete});
        }
        
        return res;
    }
};
