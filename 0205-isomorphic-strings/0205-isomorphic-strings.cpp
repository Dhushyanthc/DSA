class Solution {
public:
    bool isIsomorphic(string s, string t) {
     unordered_map<char,char> map1;
     unordered_map<char,char> map2;
     for(int i = 0; i < s.size(); i++){
        if(map1.find(t[i]) != map1.end() || map2.find(s[i]) != map2.end()){
            if (map1[t[i]] != s[i] || map2[s[i]] != t[i]){
                return false;
            }
        }
        map1[t[i]] = s[i];
        map2[s[i]] = t[i];

     }  
     return true; 
    }
};