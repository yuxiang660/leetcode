#include "MagicDictionary.h"
#include <iostream>

int main()
{
   std::cout << "676. Implement Magic Dictionary" << std::endl;

   MagicDictionary dict;
   dict.buildDict({ "hello", "leetcode" });

   std::cout << "Search hello: " << (dict.search("hello") ? "True" : "False") << std::endl;
   std::cout << "Search hhllo: " << (dict.search("hhllo") ? "True" : "False") << std::endl;
   std::cout << "Search hell: " << (dict.search("hell") ? "True" : "False") << std::endl;
   std::cout << "Search leetcoded: " << (dict.search("leetcoded") ? "True" : "False") << std::endl;

   return 0;
}
