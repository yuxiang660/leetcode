#include "Trie.h"

Trie::Trie():
   root(nullptr)
{
   nodes.emplace_back(std::make_unique<TrieNode>());
   root = nodes.back().get();
}

void Trie::insert(const std::string& word)
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
   node->count = node->count + 1;
}

std::string Trie::search(const std::string& word)
{
   if (word.empty()) return word;

   std::string ret;

   auto node = root;
   for (const auto& ch : word)
   {
      if (node->children[ch - 'a'] != nullptr)
      {
         ret += ch;
         node = node->children[ch - 'a'];
         if (node->count != 0) break;
      }
      else
      {
         break;
      }
   }

   return (node->count == 0) ? word : ret;
}
