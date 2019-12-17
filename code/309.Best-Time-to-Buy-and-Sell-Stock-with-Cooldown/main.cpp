#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices)
{
   if (prices.size() == 0) return 0;

   std::vector<int> maxProfit(prices.size());

   maxProfit[0] = 0;
   for (int i = 1; i < prices.size(); i++)
   {
      if (i < 3 || maxProfit[i - 1] > maxProfit[i - 2] || maxProfit[i - 2] == maxProfit[i - 3])
      {
         maxProfit[i] = std::max(maxProfit[i - 1], maxProfit[i - 1] + prices[i] - prices[i - 1]);
      }
      else
      {
         maxProfit[i] = std::max(maxProfit[i - 2], maxProfit[i - 2] + prices[i] - prices[i - 2]);
         maxProfit[i] = std::max(maxProfit[i], maxProfit[i - 3] + prices[i] - prices[i - 1]);
      }
   }

   return maxProfit.back();
}

int main()
{
   std::cout << "309. Best Time to Buy and Sell Stock with Cooldown" << std::endl;

   std::cout << "Max Profit: " << maxProfit({ 1,7,2,4 }) << std::endl;

   return 0;
}
