#include "DpSolution.h"
#include "DfsSolution.h"
#include <iostream>

int main()
{
   std::cout << "140. Word Break II" << std::endl;

   const std::string words{ "pineapplepenapple" };
   const std::vector<std::string> wordDict{ "apple", "pen", "applepen", "pine", "pineapple" };

   std::cout << "\nDpSolution:\n";
   DpSolution dpSolution;
   for (const auto& sentence : dpSolution.wordBreak(words, wordDict))
   {
      std::cout << sentence << std::endl;
   }

   std::cout << "\nDfsSolution:\n";
   DfsSolution dfsSolution;
   for (const auto& sentence : dfsSolution.wordBreak(words, wordDict))
   {
      std::cout << sentence << std::endl;
   }

   return 0;
}
