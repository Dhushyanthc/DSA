class Solution {
public:

    bool valid(vector<int>& need, vector<int>& have){
        for ( int i = 0 ; i <256; i++){
            if(have[i]<need[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

    vector<int> have(256, 0);
    vector<int> need(256, 0);

    for ( int i = 0; i < t.size(); i++){
        need[t[i]]++;
    }

    int low = 0;
    int res = INT_MAX ;
    int start = 0;
    for (int high = 0; high < s.size(); high++){
        have[s[high]]++;
        
        while(valid(need, have)){
            int len = high - low + 1;
            if(len < res){
                res = len;
                start = low;
            }
            
            have[s[low]]--;
            low++;
        }

    }
    
     return res == INT_MAX ? "" : s.substr(start, res);    
    }
};