#pragma once

#include <boost/optional.hpp>
#include<memory>
#include<vector>

struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
   BinaryTree(const std::vector<boost::optional<int>>& levelOrderNodes);

   TreeNode* get() const;
   void travelInorder() const;
   void travelPreorder() const;
   void travelPostorder() const;

   void print() const;

private:
   void travelInorderImpl(TreeNode* node) const;
   void travelPreorderImpl(TreeNode* node) const;
   void travelPostorderImpl(TreeNode* node) const;

   bool isValid(const std::vector<boost::optional<int>>& levelOrderNodes) const;

   TreeNode* insertLevelOrder(const std::vector<boost::optional<int>>& levelOrderNodes, size_t nodeIndex);
   void buildTree();

private:
   const std::vector<boost::optional<int>> levelOrderNodes;
   TreeNode* root;
   std::vector<std::shared_ptr<TreeNode>> treeNodes;
};
