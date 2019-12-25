#include <algorithm>
#include <iostream>
#include <vector>

void findCombination
(
   const std::vector<int>& candidates,
   int target,
   std::vector<int>& oneCombination,
   std::vector<std::vector<int>>& results
)
{
   if (target == 0) results.push_back(oneCombination);
   if (target < 0) return;

   for (size_t i = 0; i < candidates.size(); i++)
   {
      oneCombination.push_back(candidates[i]);
      findCombination
      (
         candidates,
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
      target,
      oneCombination,
      results
   );

   return results;
}

int main()
{
   std::cout << "377. Combination Sum IV" << std::endl;

   auto results = combinationSum({ 1, 2, 3 }, 4);

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

