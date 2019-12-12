#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class DfsSolution
{
public:
   DfsSolution(const std::string& words, const std::vector<std::string>& wordDict);

   std::vector<std::string> wordBreak();

private:
   std::vector<std::string> getPossibleSentences(const std::string& subWords);

private:
   const std::string words;
   const std::vector<std::string> wordDict;
   std::unordered_map<std::string, std::vector<std::string>> sentencesMap;
};
