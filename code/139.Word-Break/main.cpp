#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool isInWordDict
(
   const std::unordered_map<std::string, bool>& dict,
   const std::string::const_iterator begin,
   const std::string::const_iterator end
)
{
   return (dict.count(std::string(begin, end)) > 0);
}

bool wordBreak_DP(const std::string& words, const std::vector<std::string>& wordDict)
{
   std::unordered_map<std::string, bool> dict;
   for (auto&& word : wordDict)
   {
      dict.emplace(word, true);
   }

   std::vector<bool> canBreakTags(words.size() + 1);

   canBreakTags[0] = true;
   for (int i = 1; i < canBreakTags.size(); i++)
   {
      for (int j = i - 1; j >= 0; j--)
      {
         if (canBreakTags[j] && isInWordDict(dict, words.begin() + j, words.begin() + i))
         {
            canBreakTags[i] = true;
            break;
         }
      }
   }

   return canBreakTags.back();
}

// @NOTE: The recursive solution will cause leetcode to report time limit error! But for the solution
// of "140.Word-Break-II.md", this way has better performance than dynamic way, refer to "1440.Word-
// Break-II.md".
bool wordBreak_DFS(const std::string& subWords, const std::vector<std::string>& wordDict)
{
   if (subWords.empty()) return true;

   for (const auto& word : wordDict)
   {
      if ((subWords.rfind(word, 0) == 0) && (wordBreak_DFS(subWords.substr(word.size()), wordDict))) return true;
   }

   return false;
}

int main()
{
   std::cout << "139. Word Break" << std::endl;

   const std::string words{ "applepenapple" };
   const std::vector<std::string> wordDict{ "apple", "pen" };

   std::cout << "Work Break(DP Solution): " << wordBreak_DP(words, wordDict) << std::endl;
   std::cout << "Work Break(DFS Solution): " << wordBreak_DFS(words, wordDict) << std::endl;

   return 0;
}