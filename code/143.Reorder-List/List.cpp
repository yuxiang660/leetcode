#include "List.h"
#include <iostream>
#include <stack>

List::List(const std::vector<int>& values) :
   head(nullptr)
{
   if (values.empty()) return;

   for (int value : values)
   {
      nodes.emplace_back(value);
   }

   for (size_t i = 0; i < nodes.size() - 1; i++)
   {
      nodes[i].next = &nodes[i + 1];
   }

   head = &nodes[0];
}

void List::print() const
{
   ListNode* next = head;
   while (next != nullptr)
   {
      std::cout << next->val << " ";
      next = next->next;
   }

   std::cout << std::endl;
}

void List::reorder()
{
   if (head == nullptr) return;

   std::stack<ListNode*> nodesStack;

   ListNode* node = head;
   while (node != nullptr)
   {
      nodesStack.push(node);
      node = node->next;
   }

   node = head;
   while (nodesStack.top() != node && nodesStack.top()->next != node)
   {
      auto nextNode = nodesStack.top();
      nodesStack.pop();
      auto nextNextNode = node->next;

      node->next = nextNode;
      nextNode->next = nextNextNode;

      node = nextNextNode;
   }

   node->next = nullptr;
}
