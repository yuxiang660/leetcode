#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <boost/optional.hpp>

std::vector<int> travelBreadthFirst(TreeNode* root)
{
   std::vector<int> breadFirstNodes;
   std::queue<TreeNode*> nodeQueue;

   nodeQueue.push(root);

   while (!nodeQueue.empty())
   {
      root = nodeQueue.front();
      breadFirstNodes.push_back(root->val);
      nodeQueue.pop();

      if (root->left)
      {
         nodeQueue.push(root->left);
      }

      if (root->right)
      {
         nodeQueue.push(root->right);
      }
   }

   return breadFirstNodes;
}

std::vector<int> travelDepthFirst(TreeNode* root)
{
   std::vector<int> depthFirstNodes;
   std::stack<TreeNode*> nodeStack;

   nodeStack.push(root);

   while (!nodeStack.empty())
   {
      root = nodeStack.top();
      depthFirstNodes.push_back(root->val);
      nodeStack.pop();

      if (root->right)
      {
         nodeStack.push(root->right);
      }

      if (root->left)
      {
         nodeStack.push(root->left);
      }
   }

   return depthFirstNodes;
}

std::vector<int> travelPreorder(TreeNode* root)
{
   std::vector<int> preorderNodes;
   std::stack<TreeNode*> nodeStack;

   while (root != nullptr || !nodeStack.empty())
   {
      if (root != nullptr)
      {
         preorderNodes.push_back(root->val);
         nodeStack.push(root);
         root = root->left;
      }
      else
      {
         root = nodeStack.top()->right;
         nodeStack.pop();
      }
   }

   return preorderNodes;
}

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

std::vector<int> travelPostorder(TreeNode* root)
{
   std::vector<int> postorderNodes;
   std::stack<TreeNode*> nodeStack;
   TreeNode* lastPopNode = nullptr;

   while (root != nullptr || !nodeStack.empty())
   {
      if (root != nullptr)
      {
         nodeStack.push(root);
         root = root->left;
      }
      else
      {
         auto topNode = nodeStack.top();
         if (topNode->right == nullptr || topNode->right == lastPopNode)
         {
            postorderNodes.push_back(topNode->val);
            nodeStack.pop();
            lastPopNode = topNode;
         }
         else
         {
            root = topNode->right;
         }
      }
   }

   return postorderNodes;
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
   BinaryTree tree({ 1, 2, 3, boost::none, 4, 5 });
   tree.print();

   std::cout << "Travel Breadth First: ";
   print(travelBreadthFirst(tree.get()));

   std::cout << "Travel Depth First: ";
   print(travelDepthFirst(tree.get()));

   std::cout << "Travel Preorder: ";
   print(travelPreorder(tree.get()));

   std::cout << "Travel Inorder: ";
   print(travelInorder(tree.get()));

   std::cout << "Travel Postorder: ";
   print(travelPostorder(tree.get()));

   return 0;
}