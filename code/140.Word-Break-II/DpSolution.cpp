#include "DpSolution.h"

std::vector<size_t> DpSolution::getTailPositions
(
   const std::string::const_iterator begin,
   const std::string::const_iterator end,
   const std::vector<std::string>& wordDict
)
{
   std::vector<size_t> tailPositions;
   const std::string word(begin, end);

   for (auto&& tail : wordDict)
   {
      if (word.size() >= tail.size())
      {
         size_t len = tail.size();
         size_t pos = word.size() - tail.size();

         if (word.compare(pos, len, tail) == 0)
         {
            tailPositions.push_back(pos);
         }
      }
   }

   return tailPositions;
}

std::vector<std::string> DpSolution::wordBreak(const std::string& words, const std::vector<std::string>& wordDict)
{
   // @TODO: To make the algorithm more efficient, check whether the string can be broken correctly
   // in advance using "139. Word Break" way.
   // For example, s = "aaaaaaaaaaaaaba", wordDist = ["a", "aa", "aaa"], cannot be broken correctly.
   // If we don't check in advance, following code may take too long to solve the problem which may
   // cause "leetcode" to report time limit error.

   typedef std::vector<std::vector<std::string>> SentenceTable;

   SentenceTable sentenceTable(words.size());

   for (size_t i = 0; i < words.size(); i++)
   {
      const auto tailPositions = getTailPositions(words.begin(), words.begin() + i + 1, wordDict);

      for (const auto& tailPosition : tailPositions)
      {
         if (tailPosition == 0)
         {
            sentenceTable[i].push_back(std::string(words.begin(), words.begin() + i + 1));
         }
         else
         {
            for (auto sentence : sentenceTable[tailPosition - 1])
            {
               sentence.push_back(' ');
               sentence.append(std::string(words.begin() + tailPosition, words.begin() + i + 1));
               sentenceTable[i].push_back(sentence);
            }
         }
      }
   }

   return sentenceTable.back();
}
