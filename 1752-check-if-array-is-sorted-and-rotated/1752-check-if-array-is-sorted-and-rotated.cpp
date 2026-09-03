class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        if (n == 0 || n ==1) return true;
        int smallest = a[0];
        bool turn = false;
        for (int i = 1; i < n; i++){
            if (a[i] >= a[i-1])
            {
                if ( turn == true && a[i] > a[0]){
                   return false;
                }
                continue;
            }else if (a[i] <= smallest && turn == false ){
                turn = true;
                smallest = a[i];
            }else{
                return false;
            }
        }
        return true;
    }
};