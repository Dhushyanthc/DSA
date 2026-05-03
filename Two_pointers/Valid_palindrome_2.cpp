#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }else
            {
                return isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1);
            }
        }
        return true;
    }
private:
    bool isPalindrome(string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution solution;
    if (solution.validPalindrome(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
