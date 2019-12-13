#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class DfsSolution
{
public:
   DfsSolution() {}

   std::vector<std::string> wordBreak(const std::string& words, const std::vector<std::string>& wordDict);

private:
   std::vector<std::string> getPossibleSentences(const std::string& subWords, const std::vector<std::string>& wordDict);

private:
   std::unordered_map<std::string, std::vector<std::string>> sentencesMap;
};
