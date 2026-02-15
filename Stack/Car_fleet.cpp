#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        vector<double> st;

        for (auto &car : cars) {
            double time = (double)(target - car.first) / car.second;

            if (st.empty() || time > st.back()) {
                st.push_back(time);
            }
        }

        return st.size();
    }
};

int main() {
    Solution sol;
    
    vector<int> position1 = {1, 4};
    vector<int> speed1 = {2, 1};
    int target1 = 6;
    cout << "Test Case 1:" << endl;
    cout << "Position: [1, 4], Speed: [2, 1], Target: 6" << endl;
    cout << "Number of fleets: " << sol.carFleet(target1, position1, speed1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> position2 = {4, 1, 0, 7};
    vector<int> speed2 = {2, 2, 1, 1};
    int target2 = 10;
    cout << "Test Case 2:" << endl;
    cout << "Position: [4, 1, 0, 7], Speed: [2, 2, 1, 1], Target: 10" << endl;
    cout << "Number of fleets: " << sol.carFleet(target2, position2, speed2) << endl;
    cout << "Expected: 3" << endl << endl;
    
    vector<int> position3 = {0, 2, 4};
    vector<int> speed3 = {4, 2, 1};
    int target3 = 6;
    cout << "Test Case 3:" << endl;
    cout << "Position: [0, 2, 4], Speed: [4, 2, 1], Target: 6" << endl;
    cout << "Number of fleets: " << sol.carFleet(target3, position3, speed3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    vector<int> position4 = {3};
    vector<int> speed4 = {3};
    int target4 = 10;
    cout << "Test Case 4 (Single car):" << endl;
    cout << "Position: [3], Speed: [3], Target: 10" << endl;
    cout << "Number of fleets: " << sol.carFleet(target4, position4, speed4) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}