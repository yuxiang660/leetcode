#include <algorithm>
#include <iostream>
#include <vector>

void findCombination
(
   const std::vector<int>& candidates,
   int candidatesStartIndex,
   int sum,
   std::vector<int>& oneCombination,
   std::vector<std::vector<int>>& results
)
{
   if (sum == 0) results.push_back(oneCombination);
   if (sum < 0) return;

   for (size_t i = candidatesStartIndex; i < candidates.size(); i++)
   {
      oneCombination.push_back(candidates[i]);
      findCombination
      (
         candidates,
         i,
         sum - candidates[i],
         oneCombination,
         results
      );
      oneCombination.pop_back();
   }
}

std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
{
   std::vector<std::vector<int>> results;
   std::vector<int> oneCombination;
   findCombination(candidates, 0, target, oneCombination, results);

   return results;
}

int main()
{
   std::cout << "39. Combination Sum" << std::endl;

   auto results = combinationSum({ 2,3,5 }, 8);

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
