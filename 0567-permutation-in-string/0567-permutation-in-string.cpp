class Solution {
public:

    bool valid(vector<int>& need, vector<int>& have){
        for(int i = 0; i < 26; i++){
            if (need[i] != have[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 
        int n = s1.size();
        int low = 0;
        int high = n -1;
        vector<int> need(26,0);
        vector<int> have(26,0);

        for ( int i = 0; i < s1.size(); i++){
            need[s1[i] - 'a']++;
            have[s2[i] - 'a']++;
        }

        while(high < s2.size()){
            if (valid(need, have)) return true;
            high++;
            if(high == s2.size()) break;
            
            have[s2[high] - 'a']++;
            have[s2[low] - 'a']--;
            low++;
        }

        return valid(need, have);
    }
};
