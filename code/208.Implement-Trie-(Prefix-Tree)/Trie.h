#pragma once

#include <string>
#include <memory>
#include <vector>

class Trie
{
public:
   Trie();
   void insert(const std::string& word);
   bool search(const std::string& word);
   bool startsWith(const std::string& prefix);

private:
   #define ALPHABET_SIZE 26
   struct TrieNode
   {
      int count;
      TrieNode* children[ALPHABET_SIZE];
      TrieNode() : count(0)
      {
         for (size_t i = 0; i < ALPHABET_SIZE; i++)
         {
            children[i] = nullptr;
         }
      }
   };

   TrieNode* root;
   std::vector<std::unique_ptr<TrieNode>> nodes;
};
