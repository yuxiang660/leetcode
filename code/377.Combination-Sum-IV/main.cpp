#include <algorithm>
#include <iostream>
#include <vector>

int helper(std::vector<int>& dp, const std::vector<int>& candidates, int left)
{
   if (left <= 0) return left == 0;
   if (dp[left] != -1) return dp[left];

   dp[left] = 0;
   for (int i = 0; i < candidates.size(); i++) {
      dp[left] += helper(dp, candidates, left - candidates[i]);
   }
   return dp[left];
}

int combinationSum_DpFromTop(const std::vector<int>& candidates, int target)
{
   std::vector<int> dp(target + 1, -1);
   return helper(dp, candidates, target);
}

// If target is very large, some values in DP array may out of "int" range.
int combinationSum_DpFromBottom(const std::vector<int>& candidates, int target)
{
   // dp[i]: when the target is i, the number of possible combination is dp[i].
   std::vector<int> dp(target + 1);
   dp[0] = 0;

   for (size_t i = 1; i < dp.size(); i++)
   {
      for (auto candidate : candidates)
      {
         if (i == candidate) dp[i] += 1;
         if (i > candidate) dp[i] += dp[i - candidate];
      }
   }

   return dp[target];
}

int main()
{
   std::cout << "377. Combination Sum IV" << std::endl;

   std::vector<int> candidates{ 3, 33, 333 };
   int target = 333;

   std::cout << "The number of combination (DP From Bottom): " << combinationSum_DpFromBottom(candidates, target) << std::endl;
   std::cout << "The number of combination (DP From Top): " << combinationSum_DpFromTop(candidates, target) << std::endl;

   return 0;
}

