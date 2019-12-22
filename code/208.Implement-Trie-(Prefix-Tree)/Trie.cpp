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

bool Trie::search(const std::string& word)
{
   auto node = root;
   for (const auto& ch : word)
   {
      if (node->children[ch - 'a'] == nullptr)
      {
         return false;
      }
      node = node->children[ch - 'a'];
   }
   return node->count != 0;
}

bool Trie::startsWith(const std::string& prefix)
{
   auto node = root;
   for (const auto& ch : prefix)
   {
      if (node->children[ch - 'a'] == nullptr)
      {
         return false;
      }
      node = node->children[ch - 'a'];
   }
   return true;
}
