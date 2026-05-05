#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        int entr = 0;
        int l = 0;
        int m = s1.size();

        for (int i = 0; i < m; i++) map[s1[i]]++;

        for(int j = 0 ; j < s2.size(); j++)
        {
            int windowSize = j - l + 1; 
            if (windowSize > s1.length())
            {
                map[s2[l]]++;
                if(map[s2[l]] > 0)
                {
                    entr--;
                }
                l++;
            }
            if (map[s2[j]] > 0)
            {
                entr++;
                map[s2[j]]--;
            }else
            {
                map[s2[j]]--;
            }

            if(entr == m)
            {
                return true;
            }

        }
        return false;
    }
};

int main() {
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    Solution sol;
    bool ans = sol.checkInclusion(s1, s2);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}
