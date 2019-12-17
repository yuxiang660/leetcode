#include <iostream>
#include <string>

bool isPalindrome(const std::string& s)
{
   for (int i = 0, j = s.size() - 1; j - i > 0; i++, j--)
   {
      while (i < s.size() && !isalnum(s[i])) i++;
      while (j >= 0 && !isalnum(s[j])) j--;

      if (j - i <= 0) return true;

      if (tolower(s[i]) != tolower(s[j])) return false;
   }

   return true;
}

int main()
{
   std::cout << "125. Valid Palindrome" << std::endl;
   std::cout << "is palindrome: " << (isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << std::endl;
   return 0;
}