#include "List.h"
#include <iostream>
#include <stack>

int main()
{
   std::cout << "206. Reverse Linked List" << std::endl;

   List list({1, 2, 3, 4, 5});

   std::cout << "List: ";
   list.print();

   list.reverseIteratively();
   std::cout << "Reversed List: ";
   list.print();

   list.reverseRecursively();
   std::cout << "Reversed List (Recursion): ";
   list.print();

   return 0;
}
