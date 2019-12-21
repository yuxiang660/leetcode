#include "List.h"
#include <iostream>

int main()
{
   std::cout << "143. Reorder List" << std::endl;

   List list({ 1, 2, 3, 4, 5 });
   list.print();

   list.reorder();
   std::cout << "After reorder: ";
   list.print();

   return 0;
}
