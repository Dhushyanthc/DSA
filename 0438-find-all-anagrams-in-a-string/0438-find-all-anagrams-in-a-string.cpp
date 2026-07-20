class Solution {
public:
    bool valid(vector<int>& need, vector<int>& have){
        for(int i = 0; i < 26; i++){
            if (need[i] != have[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s2, string s1) {
        if (s1.size() > s2.size()) return {}; 
        int n = s1.size();
        int low = 0;
        int high = n -1;
        vector<int> need(26,0);
        vector<int> have(26,0);
        vector<int> res;

        for ( int i = 0; i < s1.size(); i++){
            need[s1[i] - 'a']++;
            have[s2[i] - 'a']++;
        }

        while(high < s2.size()){
            if (valid(need, have)) res.push_back(low);
            high++;
            if(high == s2.size()) break;
            
            have[s2[high] - 'a']++;
            have[s2[low] - 'a']--;
            low++;
        }

        return res;
    }
};