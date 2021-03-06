#include "List.h"
#include <iostream>

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

void List::reverseIteratively()
{
   if (head == nullptr) return;

   ListNode* node = head;
   head = nullptr;
   while (node != nullptr)
   {
      ListNode* temp = node->next;
      node->next = head;
      head = node;
      node = temp;
   }
}

static ListNode* moveForward(ListNode* baseNode, ListNode* movedNode)
{
   if (movedNode == nullptr) return baseNode;

   ListNode* next = movedNode->next;
   movedNode->next = baseNode;

   return moveForward(movedNode, next);
}

void List::reverseRecursively()
{
   head = moveForward(nullptr, head);
}
