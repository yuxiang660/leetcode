#pragma once

#include<memory>
#include<vector>
#include<queue>

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
   BinaryTree(const std::vector<int>& sortedArray);

   TreeNode* get() const;

   void travelPreorder() const;

private:
   TreeNode* sortedArrayToBST(const std::vector<int>& sortedArray);
   TreeNode* buildTree(const std::vector<int>& sortedArray, int begin, int end);
   TreeNode* buildNode(int data);

   void travelPreorderImpl(TreeNode* node) const;

private:
   TreeNode* root;
   std::vector<std::shared_ptr<TreeNode>> treeNodes;
};
