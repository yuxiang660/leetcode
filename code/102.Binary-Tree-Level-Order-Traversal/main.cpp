#include "BinaryTree.h"
#include <iostream>
#include <queue>

void insert(std::vector<std::vector<int>>& levelOrderNodes, TreeNode* node, int level)
{
   if (node == nullptr) return;

   if (level >= levelOrderNodes.size())
   {
      levelOrderNodes.push_back({});
   }

   levelOrderNodes[level].push_back(node->val);

   insert(levelOrderNodes, node->left, level + 1);
   insert(levelOrderNodes, node->right, level + 1);
}

std::vector<std::vector<int>> levelOrder_recursion(TreeNode* root)
{
   std::vector<std::vector<int>> levelOrderNodes;

   insert(levelOrderNodes, root, 0);

   return levelOrderNodes;
}

// @NOTE: runtime of this method in leetcode is 0ms, which is better than other methods.
std::vector<std::vector<int>> levelOrder_iteration2(TreeNode* root)
{
   std::vector<std::vector<int>> levelOrderNodes;
   std::queue<TreeNode*> nodesQueue;
   std::queue<TreeNode*> nodesInOneLayerQueue;

   if (root != nullptr)
   {
      nodesQueue.push(root);
   }

   while (!nodesQueue.empty())
   {
      while (!nodesQueue.empty())
      {
         nodesInOneLayerQueue.push(nodesQueue.front());
         nodesQueue.pop();
      }

      levelOrderNodes.push_back({});

      while (!nodesInOneLayerQueue.empty())
      {
         auto node = nodesInOneLayerQueue.front();
         levelOrderNodes.back().push_back(node->val);
         nodesInOneLayerQueue.pop();

         if (node->left != nullptr)
         {
            nodesQueue.push(node->left);
         }

         if (node->right != nullptr)
         {
            nodesQueue.push(node->right);
         }
      }
   }

   return levelOrderNodes;
}

std::vector<std::vector<int>> levelOrder_iteration(TreeNode* root)
{
   std::vector<std::vector<int>> levelOrderNodes;
   std::queue<TreeNode*> nodeQueue;

   if (root != nullptr)
   {
      nodeQueue.push(root);
   }

   while (!nodeQueue.empty())
   {
      levelOrderNodes.push_back({});
      auto levelSize = nodeQueue.size();

      for (size_t i = 0; i < levelSize; i++)
      {
         const auto node = nodeQueue.front();
         levelOrderNodes.back().push_back(node->val);
         nodeQueue.pop();

         if (node->left != nullptr) nodeQueue.push(node->left);
         if (node->right != nullptr) nodeQueue.push(node->right);
      }
   }

   return levelOrderNodes;
}

void print(const std::vector<std::vector<int>>& levelOrderNodes)
{
   for (const auto& nodesInOneLayer : levelOrderNodes)
   {
      std::cout << "[ ";

      for (const auto& node : nodesInOneLayer)
      {
         std::cout << node << " ";
      }

      std::cout << "]" << std::endl;
   }
}

int main()
{
   std::cout << "102. Binary Tree Level Order Traversal" << std::endl;

   BinaryTree tree({"3", "9", "#", "#", "20", "15", "#", "#", "7", "#", "#" });
   tree.travelPreorder();

   std::cout << "Recursion solution: " << std::endl;
   print(levelOrder_recursion(tree.get()));

   std::cout << "Iteration solution: " << std::endl;
   print(levelOrder_iteration(tree.get()));

   return 0;
}
