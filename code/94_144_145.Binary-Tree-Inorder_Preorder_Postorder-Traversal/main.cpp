#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <vector>
#include <boost/optional.hpp>

std::vector<int> travelInorder(TreeNode* root)
{
   std::vector<int> inorderNodes;
   std::stack<TreeNode*> nodeStack;

   while (root != nullptr || !nodeStack.empty())
   {
      if (root)
      {
         nodeStack.push(root);
         root = root->left;
      }
      else
      {
         root = nodeStack.top()->right;
         inorderNodes.push_back(nodeStack.top()->val);
         nodeStack.pop();
      }
   }

   return inorderNodes;
}

std::vector<int> travelPreorder(TreeNode* root)
{
   return {};
}

std::vector<int> travelPostorder(TreeNode* root)
{
   return {};
}


void print(const std::vector<int> numbers)
{
   for (const auto& number : numbers)
   {
      std::cout << number << " ";
   }
   std::cout << std::endl;
}

int main()
{
   BinaryTree tree({ 1, 2, 3, boost::none, 5, 6, 7 });
   tree.print();

   std::cout << "Travel Inorder: ";
   print(travelInorder(tree.get()));

   std::cout << "Travel Preorder: ";
   print(travelPreorder(tree.get()));

   std::cout << "Travel Postorder: ";
   print(travelPostorder(tree.get()));

   return 0;
}