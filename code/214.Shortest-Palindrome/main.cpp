#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string shortestPalindrome(const std::string& s)
{
   if (s.empty()) return "";

   std::string rStr(s);
   std::reverse(rStr.begin(), rStr.end());

   int i = 0;
   for (; i < rStr.size(); i++)
   {
      if (s.find(std::string(rStr.begin() + i, rStr.end())) == 0)
      {
         break;
      }
   }

   return std::string(rStr.begin(), rStr.begin() + i) + s;
}

std::vector<int> getNext(const std::string& needle)
{
   std::vector<int> next(needle.size());

   // If next[j] == k, it means that "needle[0] ~ needle[k - 1]" equals to "needle[j - k] ~ needle[j - 1]".
   // To compute next[j + 1], we should compare needle[j] with another character. There are two cases:
   // 1. if needle[j] == needle[k], then next[j + 1] = next[j] + 1.
   // 2. if needle[j] != needle[k], then we should shrink "k" to "next[k]" until "needle[j] == needle[k]" or "k == -1".
   next[0] = -1;
   int k = next[0];
   int j = 0; // start to compute next[j + 1]
   while (j + 1 < static_cast<int>(needle.size()))
   {
      if (k == -1 || needle[k] == needle[j])
      {
         next[j + 1] = k + 1;
         k = next[j + 1];
         j++;
      }
      else
      {
         k = next[k];
      }
   }

   return next;
}

std::string shortestPalindrome_KMP(const std::string& s)
{
   if (s.empty()) return "";

   std::string rStr(s.rbegin(), s.rend());

   auto next = getNext(s);

   int len = static_cast<int>(s.size());
   int j = 0;
   int i = 0;
   while (i < len && j < len)
   {
      if (j == -1 || rStr[i] == s[j])
      {
         j++;
         i++;
      }
      else
      {
         j = next[j];
      }
   }

   return std::string(rStr.begin(), rStr.begin() + (len - j)) + s;
}

int main()
{
   std::cout << "214. Shortest Palindrome" << std::endl;
   std::string s("abcd");
   std::cout << "Shortest Palindrome: " << shortestPalindrome(s) << std::endl;
   std::cout << "Shortest Palindrome (KMP): " << shortestPalindrome_KMP(s) << std::endl;

   return 0;
}
