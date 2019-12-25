#include <iostream>
#include <vector>

void findCombination
(
   int size,
   int sum,
   int baseNumber,
   std::vector<int>& oneCombination,
   std::vector<std::vector<int>>& results
)
{
   if (sum == 0 && oneCombination.size() == size) results.push_back(oneCombination);

   for (int i = baseNumber; i <= 9; i++)
   {
      oneCombination.push_back(i);
      findCombination(size, sum - i, i + 1, oneCombination, results);
      oneCombination.pop_back();
   }
}

std::vector<std::vector<int>> combinationSum(int k, int n)
{
   std::vector<std::vector<int>> ret;
   std::vector<int> oneCombination;

   findCombination(k, n, 1, oneCombination, ret);

   return ret;
}

int main()
{
   std::cout << "216. Combination Sum III" << std::endl;

   auto results = combinationSum(3, 9);

   for (const auto& result : results)
   {
      std::cout << "[ ";
      for (auto data : result)
      {
         std::cout << data << " ";
      }
      std::cout << "]" << std::endl;
   }

   return 0;
}
