#include "DfsSolution.h"

std::vector<std::string> DfsSolution::wordBreak(const std::string& words, const std::vector<std::string>& wordDict)
{
   return getPossibleSentences(words, wordDict);
}

std::vector<std::string> DfsSolution::getPossibleSentences(const std::string& subWords, const std::vector<std::string>& wordDict)
{
   if (sentencesMap.count(subWords) > 0) return sentencesMap.at(subWords);
   if (subWords.empty()) return { "" };

   std::vector<std::string> sententences;
   for (const auto& word : wordDict)
   {
      if (subWords.rfind(word, 0) == 0)
      {
         for (const auto appendSentence : getPossibleSentences(subWords.substr(word.size()), wordDict))
         {
            auto sentence = word + (appendSentence.empty() ? "" : " ") + appendSentence;
            sententences.push_back(sentence);
         }
      }
   }

   sentencesMap.insert(std::pair<std::string, std::vector<std::string>>(subWords, sententences));

   return sententences;
}
