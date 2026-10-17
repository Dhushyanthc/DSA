class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;

        int parent = (k+1)/2;
        int symbol = kthGrammar(n-1,parent);

        if(k%2!=0){
            return symbol;
        }else{
            return 1-symbol;
        }
    }
};