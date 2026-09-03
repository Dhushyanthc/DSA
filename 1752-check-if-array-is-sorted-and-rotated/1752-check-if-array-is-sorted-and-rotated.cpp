class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            if ( a[i] > a[(i+1)%n]){
                count++;
            }
        }
        return count <= 1;
    }
};