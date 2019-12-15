#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices)
{
   if (prices.size() == 0) return 0;

   int maxProfit = 0;

   for (int i = 1; i < prices.size(); i++)
   {
      if (prices[i - 1] < prices[i])
      {
         maxProfit += prices[i] - prices[i - 1];
      }
   }

   return maxProfit;
}

int maxProfit2(const std::vector<int>& prices)
{
   if (prices.size() == 0) return 0;

   std::vector<int> maxProfit(prices.size());

   maxProfit[0] = 0;
   for (int i = 1; i < prices.size(); i++)
   {
      maxProfit[i] = std::max(maxProfit[i - 1], maxProfit[i - 1] + prices[i] - prices[i - 1]);
   }

   return maxProfit.back();
}

int main()
{
   std::cout << "122. Best Time to Buy and Sell Stock II" << std::endl;

   std::vector<int> prices{ 7, 1, 5, 3, 6, 4 };

   std::cout << "Max Profit: " << maxProfit(prices) << std::endl;
   std::cout << "Max Profit2: " << maxProfit2(prices) << std::endl;

   return 0;
}
