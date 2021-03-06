#pragma once

#include <vector>

struct ListNode
{
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class List
{
public:
   List(const std::vector<int>& values);
   ~List() = default;

   void print() const;

   void reverseBetween(int m, int n);

private:
   ListNode* head;
   std::vector<ListNode> nodes;
};



