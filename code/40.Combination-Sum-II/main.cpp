#include <algorithm>
#include <iostream>
#include <vector>

void findCombination
(
   const std::vector<int>& candidates,
   int candidatesStartIndex,
   int target,
   std::vector<int>& oneCombination,
   std::vector<std::vector<int>>& results
)
{
   if (target == 0) results.push_back(oneCombination);
   if (target < 0) return;

   for (size_t i = candidatesStartIndex; i < candidates.size(); i++)
   {
      if (i != candidatesStartIndex && candidates[i - 1] == candidates[i]) continue;

      oneCombination.push_back(candidates[i]);
      findCombination
      (
         candidates,
         i + 1,
         target - candidates[i],
         oneCombination,
         results
      );
      oneCombination.pop_back();
   }
}

std::vector<std::vector<int>> combinationSum(const std::vector<int>& data, int target)
{
   std::vector<int> candidates(data);
   std::sort(candidates.begin(), candidates.end());

   std::vector<std::vector<int>> results;
   std::vector<int> oneCombination;

   findCombination
   (
      candidates,
      0,
      target,
      oneCombination,
      results
   );

   return results;
}

int main()
{
   std::cout << "40. Combination Sum II" << std::endl;

   auto results = combinationSum({ 1,2,2,2,5 }, 5);

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

