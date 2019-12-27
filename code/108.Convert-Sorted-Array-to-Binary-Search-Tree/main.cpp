#include "BinaryTree.h"
#include <iostream>

int main()
{
   std::cout << "108. Convert Sorted Array to Binary Search Tree" << std::endl;

   BinaryTree tree({-10, -3, 0, 5, 9});
   tree.travelPreorder();

   return 0;
}
