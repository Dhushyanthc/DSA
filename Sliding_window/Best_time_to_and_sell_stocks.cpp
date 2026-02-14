#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price:prices)
        {
            min_price = min(min_price, price);
            int profit = price - min_price;
            max_profit = max(max_profit, profit);

        }
        return max_profit;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Prices: [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Maximum Profit: " << solution.maxProfit(prices1) << endl;
    
    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "\nPrices: [7, 6, 4, 3, 1]" << endl;
    cout << "Maximum Profit: " << solution.maxProfit(prices2) << endl;
    
    // Test case 3
    vector<int> prices3 = {2, 4, 1};
    cout << "\nPrices: [2, 4, 1]" << endl;
    cout << "Maximum Profit: " << solution.maxProfit(prices3) << endl;
    
    return 0;
}
