#include "Trie.h"
#include <iostream>
#include <memory>

int main()
{
   std::cout << "208. Implement Trie (Prefix Tree)" << std::endl;

   std::unique_ptr<Trie> trie = std::make_unique<Trie>();

   std::cout << "Insert \"apple\"" << std::endl;
   trie->insert("apple");
   std::cout << " Has apple? " << (trie->search("apple") ? "Yes" : "No") << std::endl;
   std::cout << " Has app? " << (trie->search("app") ? "Yes" : "No") << std::endl;
   std::cout << " Starts with app? " << (trie->startsWith("app") ? "Yes" : "No") << std::endl;

   std::cout << "Insert \"app\"" << std::endl;
   trie->insert("app");
   std::cout << " Has app? " << (trie->search("app") ? "Yes" : "No") << std::endl;

   return 0;
}