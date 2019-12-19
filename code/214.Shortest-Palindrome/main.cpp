#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string& s)
{
   for (int i = 0, j = s.size() - 1; j - i > 0; i++, j--)
   {
      if (j - i <= 0) return true;

      if (s[i] != s[j]) return false;
   }

   return true;
}

std::string shortestPalindrome(const std::string& s)
{
   if (s.empty()) return "";

   int i = s.size() - 1;
   for (; i >= 0; i--)
   {
      if (isPalindrome(std::string(s.begin(), s.begin() + i + 1)))
      {
         break;
      }
   }

   std::string res(s.begin() + i + 1, s.end());

   std::reverse(res.begin(), res.end());

   return res + s;
}

std::string shortestPalindrome2(const std::string& s)
{
   if (s.empty()) return "";

   std::string rStr(s);
   std::reverse(rStr.begin(), rStr.end());

   int i = 0;
   for (;i < rStr.size(); i++)
   {
      if (s.find(std::string(rStr.begin() + i, rStr.end())) == 0)
      {
         break;
      }
   }

   return std::string(rStr.begin(), rStr.begin() + i) + s;
}

int main()
{
   std::cout << "214. Shortest Palindrome" << std::endl;
   std::string s("aacecaaa");
   std::cout << "Shortest Palindrome: " << shortestPalindrome(s) << std::endl;
   std::cout << "Shortest Palindrome(good): " << shortestPalindrome2(s) << std::endl;

   return 0;
}
