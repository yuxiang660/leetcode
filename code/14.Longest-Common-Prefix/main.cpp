#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string getCommonPrefix
(
   const std::vector<std::string>::const_iterator begin,
   const std::vector<std::string>::const_iterator end,
   const std::string& commonPrefix
)
{
   if (begin == end) return commonPrefix;

   int i = 0;
   for (; i < commonPrefix.size(); i++)
   {
      if ((*begin)[i] != commonPrefix[i]) break;
   }

   return getCommonPrefix(begin + 1, end, std::string(commonPrefix.begin(), commonPrefix.begin() + i));
}

std::string longestCommonPrefixRecursively(const std::vector<std::string>& s)
{
   if (s.empty()) return "";

   return getCommonPrefix(s.begin() + 1, s.end(), *s.begin());
}

std::string longestCommonPrefixIteratively(const std::vector<std::string>& words)
{
   if (words.empty()) return "";

   std::string commonPrefix = *(words.begin());
   int commonPrefixSize = commonPrefix.size();

   for (const auto& word : words)
   {
      commonPrefixSize = std::min(commonPrefixSize, static_cast<int>(word.size()));

      for (int i = 0; i < commonPrefixSize; i++)
      {
         if (commonPrefix[i] != word[i])
         {
            commonPrefixSize = i;
            break;
         }
      }
   }

   return std::string(commonPrefix.begin(), commonPrefix.begin() + commonPrefixSize);
}

int main()
{
   std::cout << "14. Longest Common Prefix" << std::endl;

   std::vector<std::string> words{ "aa", "a" };

   std::cout << "Longest Common Prefix (Iteration): " << longestCommonPrefixIteratively(words) << std::endl;
   std::cout << "Longest Common Prefix (Recursion): " << longestCommonPrefixRecursively(words) << std::endl;

   return 0;
}
