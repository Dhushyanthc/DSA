#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> s1;
         unordered_map<int,int> s2;

         if (s.length() != t.length()){
            return false;
         }

         for ( int x: s )
         {
            ++s1[x];
         }
          for ( int x: t )
         {
            ++s2[x];
         }
         for ( int x: s)
         {
            if ( s1[x] != s2[x])
            {
                return false;
            }
         }
        return true;
         
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    
    bool result = sol.isAnagram(s, t);
    cout << "\"" << s << "\" and \"" << t << "\" are anagrams: " << (result ? "true" : "false") << endl;
    
    return 0;
}
