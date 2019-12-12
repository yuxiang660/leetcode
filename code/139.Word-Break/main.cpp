#include <iostream>
#include <string>
#include <vector>

bool hasTail(const std::string& word, const std::string& tail)
{
   if (word.size() < tail.size()) return false;

   size_t len = tail.size();
   size_t pos = word.size() - tail.size();

   return word.compare(pos, len, tail) == 0;
}

bool wordBreak(const std::string& words, const std::vector<std::string>& wordDict)
{
   std::vector<bool> breakTags(words.size());

   for (size_t i = 0; i < words.size(); i++)
   {
      for (auto&& word : wordDict)
      {
         if (hasTail(std::string(words.begin(), words.begin() + i + 1), word))
         {
            size_t wordStartIndex = i + 1 - word.size();
            if (wordStartIndex == 0 || breakTags[wordStartIndex - 1])
            {
               breakTags[i] = true;
            }
         }
      }
   }

   return breakTags.back();
}

int main()
{
   std::cout << "139. Word Break" << std::endl;

   std::cout << "Work Break: " << wordBreak("catsandog", {"cats", "dog", "san", "and", "cat"}) << std::endl;

   return 0;
}