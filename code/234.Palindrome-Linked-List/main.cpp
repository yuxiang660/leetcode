#include "List.h"
#include <iostream>

int main()
{
   std::cout << "234. Palindrome Linked List" << std::endl;

   List list({1, 2, 1});

   std::cout << "List: ";
   list.print();

   std::cout << "isPalindrome: " << (list.isPalindrome() ? "true" : "false") << std::endl;
   std::cout << "isPalindrome: " << (list.isPalindrome_fasterButModifyTheList() ? "true" : "false") << std::endl;

   return 0;
}
