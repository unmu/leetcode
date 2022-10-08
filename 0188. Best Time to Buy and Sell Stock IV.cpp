You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
  
-------------------------------------

 class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) {
            return 0;
        }
        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i <= k; i++) {
            dp[i][0] = INT_MAX;
        }
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                dp[i][0] = min(dp[i][0], price - dp[i - 1][1]); // min cost
                dp[i][1] = max(dp[i][1], price - dp[i][0]); //max profit
            }
        }
        return dp[k][1];
    }
};
