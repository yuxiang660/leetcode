#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices)
{
   if (prices.size() == 0) return 0;

   std::vector<int> maxProfits(prices.size());

   int minPrice = prices[0];
   int maxProfit = 0;

   for (int i = 0; i < prices.size(); i++)
   {
      if (prices[i] < minPrice) minPrice = prices[i];
      maxProfit = std::max(maxProfit, prices[i] - minPrice);
      maxProfits[i] = maxProfit;
   }

   int maxPrice = prices[prices.size() - 1];
   maxProfit = 0;

   for (int i = prices.size() - 1; i >= 0; i--)
   {
      if (prices[i] > maxPrice) maxPrice = prices[i];
      maxProfit = std::max(maxProfit, maxPrice - prices[i]);
      maxProfits[i] += maxProfit;
   }

   return *(std::max_element(maxProfits.begin(), maxProfits.end()));
}

int main()
{
   std::cout << "123. Best Time to Buy and Sell Stock III" << std::endl;

   std::cout << "Max Profit: " << maxProfit({ 7,6,4,3,1 }) << std::endl;
}
