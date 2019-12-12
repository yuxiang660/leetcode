#pragma once

#include <string>
#include <vector>

class DpSolution
{
public:
   DpSolution(const std::string& words, const std::vector<std::string>& wordDict);

   std::vector<std::string> wordBreak();

private:
   std::vector<size_t> getTailPositions
   (
      const std::string::const_iterator begin,
      const std::string::const_iterator end
   );

private:
   const std::string words;
   const std::vector<std::string> wordDict;
};
