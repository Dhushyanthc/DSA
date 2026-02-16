#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool Canfinish(int k, vector<int>& piles, int h)
    {
        int hours = 0;
        for (auto& pile : piles)
        {
            hours += (pile + k - 1)/k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int right = piles[0];
       for (int pile : piles)
       {
            if (pile > right)
            {
                right = pile;
            }
       }
        int left = 1;
        int answer = right;

        while (left <= right)
        {
            int mid = left + (right -left)/2;
            if (Canfinish(mid, piles, h))
            {
                answer = mid;
                right = mid - 1;
            }else
            {
                left = mid + 1;
            }
        }
        return answer;

        
    }
};

int main() {
    Solution sol;
    
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test Case 1:" << endl;
    cout << "Piles: [3, 6, 7, 11], Hours: 8" << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles1, h1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: 5" << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles2, h2) << endl;
    cout << "Expected: 30" << endl << endl;
    
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Test Case 3:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: 6" << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles3, h3) << endl;
    cout << "Expected: 23" << endl << endl;
    
    vector<int> piles4 = {1, 1, 1, 1};
    int h4 = 4;
    cout << "Test Case 4:" << endl;
    cout << "Piles: [1, 1, 1, 1], Hours: 4" << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles4, h4) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}