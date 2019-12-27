#include "BinaryTree.h"
#include <iostream>
#include <queue>

BinaryTree::BinaryTree(const std::vector<int>& sortedArray)
{
   root = sortedArrayToBST(sortedArray);
}

TreeNode* BinaryTree::get() const
{
   return root;
}

void BinaryTree::travelPreorder() const
{
   std::cout << "Preorder Traversal: " << std::endl;
   travelPreorderImpl(root);
   std::cout << std::endl;
}

TreeNode* BinaryTree::sortedArrayToBST(const std::vector<int>& sortedArray)
{
   root = buildTree(sortedArray, 0, sortedArray.size());

   return root;
}

TreeNode* BinaryTree::buildTree(const std::vector<int>& sortedArray, int begin, int end)
{
   if (begin >= end) return nullptr;

   int mid = (begin + end) / 2;
   TreeNode* node = buildNode(sortedArray[mid]);
   node->left = buildTree(sortedArray, begin, mid);
   node->right = buildTree(sortedArray, mid + 1, end);

   return node;
}

TreeNode* BinaryTree::buildNode(int data)
{
   treeNodes.emplace_back(std::make_shared<TreeNode>(data));
   return (treeNodes.back()).get();
}

void BinaryTree::travelPreorderImpl(TreeNode* node) const
{
   if (node == nullptr) return;

   std::cout << node->val << " ";
   travelPreorderImpl(node->left);
   travelPreorderImpl(node->right);
}
