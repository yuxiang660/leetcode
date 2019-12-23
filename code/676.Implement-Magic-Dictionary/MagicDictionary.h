#pragma once

#include <string>
#include <memory>
#include <vector>


class MagicDictionary
{
public:
   MagicDictionary();
   void buildDict(const std::vector<std::string> &dict);
   bool search(const std::string& word);
private:
   #define ALPHABET_SIZE 26
   struct TrieNode
   {
      bool end;
      TrieNode* children[ALPHABET_SIZE];
      TrieNode() : end(false)
      {
         for (size_t i = 0; i < ALPHABET_SIZE; i++)
         {
            children[i] = nullptr;
         }
      }
   };

   void insert(const std::string& word);
   bool continueSearch(TrieNode* node, const std::string& subWord);

   TrieNode* root;
   std::vector<std::unique_ptr<TrieNode>> nodes;
};

