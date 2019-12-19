#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string getPalindrome(const std::string& s)
{
   std::string rStr(s);
   std::reverse(rStr.begin(), rStr.end());

   size_t i = 0;
   for (; i < s.size(); i++)
   {
      if (rStr.find(std::string(s.begin() + i, s.end())) == 0)
      {
         break;
      }
   }

   return std::string(s.begin() + i, s.end());
}

std::string longestPalindrome(const std::string& s)
{
   if (s.empty()) return "";

   std::string longestPalindrome{s[0]};

   for (size_t i = 1; i < s.size(); i++)
   {
      auto palindrome = getPalindrome(std::string(s.begin(), s.begin() + i + 1));
      if (palindrome.size() > longestPalindrome.size())
      {
         longestPalindrome = palindrome;
      }
   }

   return longestPalindrome;
}

std::string longestPalindrome_DP(const std::string& s)
{
   if (s.empty()) return "";

   // "dp[i][j] == true" means s[i] ~ s[j] is palindrome.
   // If s[i] == s[j] && dp[i - 1][j - 1] == true, then dp[i][j] = true.
   std::vector <std::vector<bool>> dp(s.size(), std::vector<bool>(s.size()));
   int maxLength = 1;
   int startIndex = 0;
   for (int begin = s.size() - 1; begin >= 0; begin--)
   {
      dp[begin][begin] = true;
      for (int end = begin + 1; end < static_cast<int>(s.size()); end++)
      {
         if (s[begin] == s[end])
         {
            if (begin + 1 == end || dp[begin + 1][end - 1] == true)
            {
               dp[begin][end] = true;
               int len = end - begin + 1;
               if (len > maxLength)
               {
                  maxLength = len;
                  startIndex = begin;
               }
            }
         }
      }
   }

   return s.substr(startIndex, maxLength);
}

int main()
{
   std::cout << "5. Longest Palindromic Substring" << std::endl;

   std::string s("cbbd");

   std::cout << "Longest Palindromic Substring: " << longestPalindrome(s) << std::endl;
   std::cout << "Longest Palindromic Substring (DP): " << longestPalindrome_DP(s) << std::endl;

   return 0;
}
