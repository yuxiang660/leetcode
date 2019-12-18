#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int longestPalindromeSubseq(const std::string& s)
{
   if (s.size() == 0) return 0;

   // dp[begin][end] : the longest palindrom length of substring "s[begin] ~ s[end]",
   // and 0 <= begin <= end < s.size().
   // The value of dp[begin][end] can be deduced by the value of its substring.
   // If s[begin] == s[end], then dp[begin][end] = dp[begin + 1][end - 1] + 2.
   // If s[begin] != s[end], then dp[begin][end] = max(dp[begin + 1][end], dp[begin][end - 1]).
   int len = s.size();
   std::vector<std::vector<int>> dp(len, std::vector<int>(len));

   for (int begin = len - 1; begin >= 0; begin--)
   {
      dp[begin][begin] = 1;

      for (int end = begin + 1; end < len; end++)
      {
         if (s[begin] == s[end])
         {
            dp[begin][end] = dp[begin + 1][end - 1] + 2;
         }
         else
         {
            dp[begin][end] = std::max(dp[begin + 1][end], dp[begin][end - 1]);
         }
      }
   }

   return dp[0][len - 1];
}

int main()
{
   std::cout << "516. Longest Palindromic Subsequence" << std::endl;

   std::cout << "Longest Palindromic Subsequence Length: " << longestPalindromeSubseq("bbbab") << std::endl;

   return 0;
}
