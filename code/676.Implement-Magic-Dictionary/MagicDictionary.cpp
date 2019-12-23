#include "MagicDictionary.h"

MagicDictionary::MagicDictionary() :
   root(nullptr)
{
   nodes.emplace_back(std::make_unique<TrieNode>());
   root = nodes.back().get();
}

void MagicDictionary::buildDict(const std::vector<std::string>& dict)
{
   for (auto&& word : dict)
   {
      insert(word);
   }
}

void MagicDictionary::insert(const std::string& word)
{
   auto node = root;
   for (const auto& ch : word)
   {
      if (node->children[ch - 'a'] == nullptr)
      {
         nodes.emplace_back(std::make_unique<TrieNode>());
         node->children[ch - 'a'] = nodes.back().get();
      }
      node = node->children[ch - 'a'];
   }
   node->end = true;
}

bool MagicDictionary::continueSearch(TrieNode* node, const std::string& subWord)
{
   for (const auto& ch : subWord)
   {
      if (node->children[ch - 'a'] == nullptr) return false;
      node = node->children[ch - 'a'];
   }
   return node->end;
}

bool MagicDictionary::search(const std::string& word)
{
   auto node = root;
   for (size_t i = 0; i < word.size(); i++)
   {
      for (size_t j = 0; j < ALPHABET_SIZE; j++)
      {
         if (node->children[j] != nullptr && j != word[i] - 'a' &&
             continueSearch(node->children[j], std::string(word.begin() + i + 1, word.end())))
         {
            return true;
         }
      }

      if (node->children[word[i] - 'a'] == nullptr) break;
      node = node->children[word[i] - 'a'];
   }

   return false;
}
