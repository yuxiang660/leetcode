#pragma once

#include<memory>
#include<vector>
#include<string>
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
   BinaryTree(const std::vector<std::string>& preorderNodes);

   TreeNode* get() const;

   void travelPreorder() const;

private:
   TreeNode* buildTree();

   void travelPreorderImpl(TreeNode* node) const;

private:
   std::queue<std::string> rawNodes;
   TreeNode* root;
   std::vector<std::shared_ptr<TreeNode>> treeNodes;
};
