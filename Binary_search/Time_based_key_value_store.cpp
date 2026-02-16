#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        store[key].push_back({timestamp, value});

    }
    
    string get(string key, int timestamp) {
        
       if (!store.count(key)) return "";
        auto& vec = store[key];

        int left = 0;
        int right = vec.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (vec[mid].first <= timestamp) {
                ans = vec[mid].second; 
                left = mid + 1;        
            } else {
                right = mid - 1;
            }
        }
        return ans;
        
    }
};

int main() {
    TimeMap timeMap;
    
    cout << "Test Case 1:" << endl;
    timeMap.set("foo", "bar", 1);
    cout << "set(\"foo\", \"bar\", 1)" << endl;
    cout << "get(\"foo\", 1): " << timeMap.get("foo", 1) << endl;
    cout << "Expected: bar" << endl << endl;
    
    cout << "Test Case 2:" << endl;
    cout << "get(\"foo\", 3): " << timeMap.get("foo", 3) << endl;
    cout << "Expected: bar" << endl << endl;
    
    cout << "Test Case 3:" << endl;
    timeMap.set("foo", "bar2", 4);
    cout << "set(\"foo\", \"bar2\", 4)" << endl;
    cout << "get(\"foo\", 4): " << timeMap.get("foo", 4) << endl;
    cout << "Expected: bar2" << endl << endl;
    
    cout << "Test Case 4:" << endl;
    cout << "get(\"foo\", 5): " << timeMap.get("foo", 5) << endl;
    cout << "Expected: bar2" << endl << endl;
    
    cout << "Test Case 5:" << endl;
    cout << "get(\"nonexistent\", 1): " << timeMap.get("nonexistent", 1) << endl;
    cout << "Expected: (empty string)" << endl;
    
    return 0;
}