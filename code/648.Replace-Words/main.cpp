#include "Trie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string getRoot(const std::vector<std::string>& dict, const std::string& successor)
{
   std::string root;
   for (const auto& word : dict)
   {
      if (successor.find(word) == 0)
      {
         if (root.empty() || root.size() > word.size())
         {
            root = word;
         }
      }
   }
   return root.empty() ? successor : root;
}

std::string replaceWords(const std::vector<std::string>& dict, const std::string& sentence)
{
   std::string ret;

   std::istringstream input(sentence);
   while (input)
   {
      std::string successor;
      input >> successor;

      auto root = getRoot(dict, successor);

      if (root.empty()) ret.pop_back();
      else ret += root + " ";
   }

   return ret;
}

std::string replaceWords_trieSolution(const std::vector<std::string>& dict, const std::string& sentence)
{
   Trie trie;
   for (const auto& root : dict)
   {
      trie.insert(root);
   }

   std::string ret;

   std::istringstream input(sentence);
   while (input)
   {
      std::string successor;
      input >> successor;

      auto root = trie.search(successor);

      if (root.empty()) ret.pop_back();
      else ret += root + " ";
   }

   return ret;
}

int main()
{
   std::cout << "648. Replace Words" << std::endl;
   std::vector<std::string> dict{ "a", "aa", "aaa", "aaaa" };
   std::string sentence("a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa");

   std::cout << "Output: " << replaceWords(dict, sentence) << std::endl;;
   std::cout << "Output (Trie Solution): " << replaceWords_trieSolution(dict, sentence) << std::endl;;

   return 0;
}
