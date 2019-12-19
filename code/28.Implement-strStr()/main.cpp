#include <iostream>
#include <string>
#include <vector>

int strStr(const std::string& haystack, const std::string& needle)
{
   if (needle.size() == 0) return 0;

   for (int i = 0; i < static_cast<int>(haystack.size()); i++)
   {
      int j = 0;
      for (; j < static_cast<int>(needle.size()); j++)
      {
         if (haystack[i + j] != needle[j])
         {
            break;
         }
      }
      if (j == needle.size())
      {
         return i;
      }
   }

   return -1;
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

int strStr_KMP(const std::string& haystack, const std::string& needle)
{
   if (needle.empty()) return 0;
   if (needle.size() > haystack.size()) return -1;

   auto next = getNext(needle);

   int j = 0;
   int i = 0;
   while (j < static_cast<int>(needle.size()) && i < static_cast<int>(haystack.size()))
   {
      if (j == -1 || haystack[i] == needle[j])
      {
         i++;
         j++;
      }
      else
      {
         j = next[j];
      }
   }

   return (j == static_cast<int>(needle.size())) ? (i - j) : -1;
}

int main()
{
   std::cout << "28. Implement strStr()" << std::endl;

   const std::string haystack("hello");
   const std::string needle("ll");

   std::cout << "Violent Solution strStr(): " << strStr(haystack, needle) << std::endl;
   std::cout << "KMP Algorithm strStr(): " << strStr_KMP(haystack, needle) << std::endl;

   return 0;
}
