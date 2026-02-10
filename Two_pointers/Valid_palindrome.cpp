#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0;
        int j = len - 1;

        while (true)
        {
            if (i <= j)
            {   
                if (isalnum(s[i]) && isalnum(s[j]))
                {
                if (tolower(s[i]) == tolower(s[j]))
                {
                    i++;
                    j--;
                }else
                {
                    return false;
                }
                } else
                {
                    if (!isalnum(s[i]))
                    {
                        i++;
                    }else
                    {
                        j--;
                    }
                }

            }
            else
            {
                return true;
            }
            
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Simple valid palindrome
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: \"" << test1 << "\"" << endl;
    cout << "Is palindrome: " << (sol.isPalindrome(test1) ? "true" : "false") << endl << endl;
    
    // Test case 2: Invalid palindrome
    string test2 = "race a car";
    cout << "Test 2: \"" << test2 << "\"" << endl;
    cout << "Is palindrome: " << (sol.isPalindrome(test2) ? "true" : "false") << endl << endl;
    
    // Test case 3: Empty string / spaces and punctuation only
    string test3 = " ";
    cout << "Test 3: \"" << test3 << "\"" << endl;
    cout << "Is palindrome: " << (sol.isPalindrome(test3) ? "true" : "false") << endl << endl;
    
    // Test case 4: Single character
    string test4 = "a";
    cout << "Test 4: \"" << test4 << "\"" << endl;
    cout << "Is palindrome: " << (sol.isPalindrome(test4) ? "true" : "false") << endl << endl;
    
    // Test case 5: With numbers
    string test5 = "0P";
    cout << "Test 5: \"" << test5 << "\"" << endl;
    cout << "Is palindrome: " << (sol.isPalindrome(test5) ? "true" : "false") << endl;
    
    return 0;
}