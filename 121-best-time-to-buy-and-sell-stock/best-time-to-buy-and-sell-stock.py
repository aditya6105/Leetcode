class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        mini = prices[0]
        for i in range(1, len(prices)):
            cost = prices[i] - mini
            if(mini > prices[i]): mini = prices[i]
            if(maxP < cost): maxP = cost
        return maxP