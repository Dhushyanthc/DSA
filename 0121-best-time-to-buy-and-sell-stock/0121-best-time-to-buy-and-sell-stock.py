class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        min_price = prices[0]
        for price in prices:
            if price < min_price:
                min_price = price
            profit = price - min_price
            maxprofit = max(maxprofit, profit)
        return maxprofit if maxprofit > 0 else 0
        