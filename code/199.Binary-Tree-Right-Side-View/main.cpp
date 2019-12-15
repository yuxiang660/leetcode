#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> rightSideView_iteration(TreeNode* root)
{
   std::vector<int> rightNodes;
   std::queue<TreeNode*> nodesQueue;
   std::queue<TreeNode*> nodesInOneLayer;

   if (root != nullptr)
   {
      nodesQueue.push(root);
   }

   while (!nodesQueue.empty())
   {
      while (!nodesQueue.empty())
      {
         nodesInOneLayer.push(nodesQueue.front());
         nodesQueue.pop();
      }

      auto rightNode = nodesInOneLayer.back();
      rightNodes.push_back(rightNode->val);

      while (!nodesInOneLayer.empty())
      {
         auto node = nodesInOneLayer.front();
         if (node->left != nullptr)
         {
            nodesQueue.push(node->left);
         }
         if (node->right != nullptr)
         {
            nodesQueue.push(node->right);
         }
         nodesInOneLayer.pop();
      }

      nodesInOneLayer = {};
   }

   return rightNodes;
}

void insert(std::vector<int>& rightNodes, TreeNode* node, int level)
{
   if (node == nullptr) return;

   if (rightNodes.size() == level) rightNodes.push_back(node->val);

   insert(rightNodes, node->right, level + 1);
   insert(rightNodes, node->left, level + 1);
}

std::vector<int> rightSideView_recursion(TreeNode* root)
{
   std::vector<int> rightNodes;

   insert(rightNodes, root, 0);

   return rightNodes;
}

int main()
{
   std::cout << "199. Binary Tree Right Side View" << std::endl;

   BinaryTree tree({ 1, 2, 3, boost::none,5, boost::none, 4 });
   tree.travelPreorder();

   for (int value : rightSideView_iteration(tree.get()))
   {
      std::cout << value << " ";
   }
   std::cout << std::endl;

   for (int value : rightSideView_recursion(tree.get()))
   {
      std::cout << value << " ";
   }
   std::cout << std::endl;

   return 0;
}
