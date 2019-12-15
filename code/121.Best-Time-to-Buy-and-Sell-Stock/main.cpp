#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit1(const std::vector<int>& prices)
{
   if (prices.empty()) return 0;

   int maxProfit = 0;
   int minPrices = prices[0];

   for (size_t i = 0; i < prices.size(); i++)
   {
      minPrices = std::min(minPrices, prices[i]);
      maxProfit = std::max(maxProfit, prices[i] - minPrices);
   }

   return maxProfit;
}

int maxProfit2(const std::vector<int>& prices)
{
   if (prices.empty()) return 0;

   std::vector<int> buyPrices(prices.size());
   std::vector<int> sellPrices(prices.size());
   std::vector<int> maxProfit(prices.size());

   for (int i = 0; i < prices.size(); i++)
   {
      if (i == 0)
      {
         buyPrices[0] = prices[0];
      }
      else
      {
         buyPrices[i] = std::min(buyPrices[i - 1], prices[i]);
      }
   }

   for (int i = prices.size() - 1; i >= 0; i--)
   {
      if (i == prices.size() - 1)
      {
         sellPrices[i] = prices[i];
      }
      else
      {
         sellPrices[i] = std::max(sellPrices[i + 1], prices[i]);
      }
   }

   for (int i = 0; i < prices.size(); i++)
   {
      maxProfit[i] = sellPrices[i] - buyPrices[i];
   }

   return *(std::max_element(maxProfit.begin(), maxProfit.end()));
}

int main()
{
   std::cout << "121. Best Time to Buy and Sell Stock" << std::endl;

   std::vector<int> prices{ 7, 1, 5, 3, 6, 4 };

   std::cout << "Max Profit1: " << maxProfit1(prices) << std::endl;
   std::cout << "Max Profit2: " << maxProfit2(prices) << std::endl;

   return 0;
}
