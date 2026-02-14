#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> str;

        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                str.push_back(x);
            } 
            else if (x == ')') {
                if (str.empty() || str.back() != '(') return false;
                str.pop_back();
            } 
            else if (x == '}') {
                if (str.empty() || str.back() != '{') return false;
                str.pop_back();
            } 
            else if (x == ']') {
                if (str.empty() || str.back() != '[') return false;
                str.pop_back();
            } 
            else {
                return false;
            }
        }
        return str.empty();
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Simple valid parentheses
    string test1 = "()";
    cout << "Test 1: \"" << test1 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test1) ? "true" : "false") << endl << endl;
    
    // Test case 2: Multiple pairs
    string test2 = "()[]{}";
    cout << "Test 2: \"" << test2 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test2) ? "true" : "false") << endl << endl;
    
    // Test case 3: Nested parentheses
    string test3 = "({[]})";
    cout << "Test 3: \"" << test3 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test3) ? "true" : "false") << endl << endl;
    
    // Test case 4: Invalid - mismatched
    string test4 = "(]";
    cout << "Test 4: \"" << test4 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test4) ? "true" : "false") << endl << endl;
    
    // Test case 5: Invalid - unclosed
    string test5 = "([)]";
    cout << "Test 5: \"" << test5 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test5) ? "true" : "false") << endl << endl;
    
    // Test case 6: Empty string
    string test6 = "";
    cout << "Test 6: \"" << test6 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test6) ? "true" : "false") << endl << endl;
    
    // Test case 7: Single opening bracket
    string test7 = "(";
    cout << "Test 7: \"" << test7 << "\"" << endl;
    cout << "Is valid: " << (sol.isValid(test7) ? "true" : "false") << endl;
    
    return 0;
}
