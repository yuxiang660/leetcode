#include "List.h"
#include <iostream>

int main()
{
   std::cout << "92. Reverse Linked List II" << std::endl;

   int m = 2;
   int n = 4;
   List list({1, 2, 3, 4, 5});

   std::cout << "List: ";
   list.print();

   list.reverseBetween(m , n);
   std::cout << "Reverse between " << m << "th node and " << n << "th node: ";
   list.print();

   return 0;
}
