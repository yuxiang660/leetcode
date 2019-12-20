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

void List::reverseBetween(int m, int n)
{
   if (head == nullptr) return;

   ListNode* preListEnd = nullptr;
   ListNode* nodeHandle = head;

   for (int i = 1; i < m; i++)
   {
      preListEnd = nodeHandle;
      nodeHandle = nodeHandle->next;
   }

   std::stack<ListNode*> nodesStack;
   for (int i = m; i < n + 1; i++)
   {
      nodesStack.push(nodeHandle);
      nodeHandle = nodeHandle->next;
   }

   ListNode* postListBegin = nodeHandle;

   nodeHandle = nodesStack.top();
   nodesStack.pop();

   if (preListEnd == nullptr)
   {
      head = nodeHandle;
   }
   else
   {
      preListEnd->next = nodeHandle;
   }

   while (!nodesStack.empty())
   {
      nodeHandle->next = nodesStack.top();
      nodesStack.pop();
      nodeHandle = nodeHandle->next;
   }

   nodeHandle->next = postListBegin;
}

