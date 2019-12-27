#include "BinaryTree.h"
#include <algorithm>
#include <iostream>
#include <queue>

int getHeight(TreeNode* root)
{
   if (root == nullptr) return 0;
   return std::max(getHeight(root->left) + 1, getHeight(root->right) + 1);
}

bool isBalanced(TreeNode* root)
{
   if (root == nullptr) return true;
   return (std::abs(getHeight(root->left) - getHeight(root->right)) <= 1)
          && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
   std::cout << "110. Balanced Binary Tree" << std::endl;

   BinaryTree balancedTree({ "1", "2", "3", "#", "#", "#", "2", "#", "3", "#", "#" });
   balancedTree.travelPreorder();

   BinaryTree unBalancedTree({ "1", "2", "3", "4", "#", "#", "#", "#", "2", "#", "3", "#", "#" });
   unBalancedTree.travelPreorder();

   std::cout << "Is the tree balanced ? - " << std::boolalpha << isBalanced(balancedTree.get()) << std::endl;
   std::cout << "Is the tree balanced ? - " << std::boolalpha << isBalanced(unBalancedTree.get()) << std::endl;

   return 0;
}
