#pragma once

#include <string>
#include <vector>

class DpSolution
{
public:
   DpSolution() {}

   std::vector<std::string> wordBreak(const std::string& words, const std::vector<std::string>& wordDict);

private:
   std::vector<size_t> getTailPositions
   (
      const std::string::const_iterator begin,
      const std::string::const_iterator end,
      const std::vector<std::string>& wordDict
   );
};
