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

static bool isListPalindrome(ListNode* head, int length)
{
   if (length <= 1) return true;

   ListNode* end = head;
   for (int i = 0; i < length - 1; i++)
   {
      end = end->next;
   }

   return (head->val == end->val) && isListPalindrome(head->next, length - 2);
}

bool List::isPalindrome()
{
   if (head == nullptr) return true;

   int length = 0;

   ListNode* node = head;
   while (node != nullptr)
   {
      length++;
      node = node->next;
   }

   return isListPalindrome(head, length);
}

bool List::isPalindrome_fasterButModifyTheList()
{
   ListNode* fast = head;
   ListNode* slow = head;
   head = nullptr;

   while ((fast != nullptr) && (fast->next != nullptr))
   {
      fast = fast->next->next;

      ListNode* temp = slow->next;
      slow->next = head;
      head = slow;
      slow = temp;
   }

   if (fast != nullptr)
   {
      slow = slow->next;
   }

   while (head != nullptr)
   {
      if (head->val != slow->val) return false;

      head = head->next;
      slow = slow->next;
   }

   return true;
}
