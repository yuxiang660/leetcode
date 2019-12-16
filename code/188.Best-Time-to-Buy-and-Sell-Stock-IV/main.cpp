#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int maxProfitNoTransactionLimit(const std::vector<int>& prices)
{
   if (prices.empty()) return 0;

   int maxProfit = 0;

   for (int i = 1; i < prices.size(); i++)
   {
      if (prices[i] > prices[i - 1]) maxProfit += prices[i] - prices[i - 1];
   }

   return maxProfit;
}

int maxProfit(int k, const std::vector<int>& prices)
{
   if (k == 0) return 0;
   if (prices.size() <= 3 || k >= prices.size() / 2) return maxProfitNoTransactionLimit(prices);

   int numberOfPrices = prices.size();
   int numberOfTransactions = k + 1; // 0 ~ k

   // dp[i][j] : max profit with at most i transaction if the last price is price[j].
   // dp[0][] == 0, max profit is zero because no transaction.
   // dp[][0] == 0, max profit is zero because only the price in one day is same, which cannot get the profit.
   // DP transition function for dp[i][j]:
   // 1. No operation
   //    dp[i][j] = dp[i][j - 1]
   // 2. Take a transaction from dp[i - 1][k], (0 <= k < j)
   //    dp[i][j] = dp[i - 1][k] + price[j] - price[k], (0 <= k < j);
   //    the transaction buy the stock at price[k], and sell it at price[j].
   std::vector<std::vector<int>> dp(numberOfTransactions, std::vector<int>(numberOfPrices));

   for (int i = 1; i < numberOfTransactions; i++)
   {
      for (int j = 1; j < numberOfPrices; j++)
      {
         int maxProfitWithOneTransaction = 0;
         for (int k = 0; k < j; k++)
         {
            maxProfitWithOneTransaction = std::max(maxProfitWithOneTransaction, dp[i - 1][k] + prices[j] - prices[k]);
         }
         dp[i][j] = std::max(dp[i][j - 1], maxProfitWithOneTransaction);
      }
   }

   return dp[numberOfTransactions - 1][numberOfPrices - 1];
}

int main()
{
   std::cout << "188. Best Time to Buy and Sell Stock IV" << std::endl;

   std::cout << "Max Profit: " << maxProfit(2, { 3,2,6,5,0,3 }) << std::endl;

   return 0;
}