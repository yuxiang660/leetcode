#include "BinaryTree.h"
#include<iostream>

BinaryTree::BinaryTree(const std::vector<std::string>& preorderNodes)
{
   for (auto node : preorderNodes)
   {
      rawNodes.push(node);
   }

   root = buildTree();
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

TreeNode* BinaryTree::buildTree()
{
   if (rawNodes.empty()) return nullptr;

   auto rawNode = rawNodes.front();
   rawNodes.pop();

   if (rawNode.compare("#") == 0) return nullptr;

   auto node = std::make_shared<TreeNode>(std::stoi(rawNode));
   node->left = buildTree();
   node->right = buildTree();

   treeNodes.push_back(node);

   return node.get();
}

void BinaryTree::travelPreorderImpl(TreeNode* node) const
{
   if (node == nullptr) return;

   std::cout << node->val << " ";
   travelPreorderImpl(node->left);
   travelPreorderImpl(node->right);
}
