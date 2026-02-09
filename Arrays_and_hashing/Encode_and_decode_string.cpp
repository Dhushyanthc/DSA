#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {

        string st;
        
        for ( string s:strs){
            st = st + to_string(s.size()) + '#' + s;
        } 

        return st;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i<s.size())
        {
            int hash_pos = s.find('#',i); //starting from index i

            int len = stoi(s.substr(i,hash_pos-i));

            i = hash_pos + 1;

            result.push_back(s.substr(i,len));
            i++;
        }

        return result;

    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<string> input1 = {"Hello", "World"};
    string encoded1 = sol.encode(input1);
    cout << "Encoded: " << encoded1 << endl;
    
    vector<string> decoded1 = sol.decode(encoded1);
    cout << "Decoded: ";
    for(const string& s : decoded1) {
        cout << s << " ";
    }
    cout << endl << endl;
    
    // Test case 2
    vector<string> input2 = {"a", "bc", "def", "ghij"};
    string encoded2 = sol.encode(input2);
    cout << "Encoded: " << encoded2 << endl;
    
    vector<string> decoded2 = sol.decode(encoded2);
    cout << "Decoded: ";
    for(const string& s : decoded2) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
