#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(const std::vector<boost::optional<int>>& levelOrderNodes) :
   levelOrderNodes(levelOrderNodes),
   root(nullptr)
{
   buildTree();
}

TreeNode* BinaryTree::get() const
{
   return root;
}

static int isLayerStartIndex(int index)
{
   return ((index + 1) & index) == 0;
}

void BinaryTree::print() const
{
   std::cout << "Binary Tree:";
   for (int i = 0; i < levelOrderNodes.size(); i++)
   {
      if (isLayerStartIndex(i))
      {
         std::cout << std::endl;
      }

      if (levelOrderNodes[i])
      {
         std::cout << "  " << levelOrderNodes[i].get() << "  ";
      }
      else
      {
         std::cout << " null ";
      }
   }
   std::cout << std::endl << std::endl;
}

void BinaryTree::travelInorder() const
{
   std::cout << "Inorder Traversal: " << std::endl;
   travelInorderImpl(root);
   std::cout << std::endl;
}

void BinaryTree::travelPreorder() const
{
   std::cout << "Preorder Traversal: " << std::endl;
   travelPreorderImpl(root);
   std::cout << std::endl;
}

void BinaryTree::travelPostorder() const
{
   std::cout << "Postorder Traversal: " << std::endl;
   travelPostorderImpl(root);
   std::cout << std::endl;
}

void BinaryTree::travelInorderImpl(TreeNode* node) const
{
   if (node == nullptr) return;

   travelInorderImpl(node->left);
   std::cout << node->val << " ";
   travelInorderImpl(node->right);
}

void BinaryTree::travelPreorderImpl(TreeNode* node) const
{
   if (node == nullptr) return;

   std::cout << node->val << " ";
   travelPreorderImpl(node->left);
   travelPreorderImpl(node->right);
}

void BinaryTree::travelPostorderImpl(TreeNode* node) const
{
   if (node == nullptr) return;

   travelPostorderImpl(node->left);
   travelPostorderImpl(node->right);
   std::cout << node->val << " ";
}

bool BinaryTree::isValid(const std::vector<boost::optional<int>>& levelOrderNodes) const
{
   return !levelOrderNodes.empty();
}

TreeNode* BinaryTree::insertLevelOrder(const std::vector<boost::optional<int>>& levelOrderNodes, size_t nodeIndex)
{
   if (nodeIndex >= levelOrderNodes.size()) return nullptr;
   if (levelOrderNodes[nodeIndex] == boost::none) return nullptr;

   auto treeNode = std::make_shared<TreeNode>(levelOrderNodes[nodeIndex].get());
   treeNode->left = insertLevelOrder(levelOrderNodes, 2 * nodeIndex + 1);
   treeNode->right = insertLevelOrder(levelOrderNodes, 2 * nodeIndex + 2);

   treeNodes.push_back(treeNode);

   return treeNode.get();
}

void BinaryTree::buildTree()
{
   if (!isValid(levelOrderNodes)) return;

   root = insertLevelOrder(levelOrderNodes, 0);
}
