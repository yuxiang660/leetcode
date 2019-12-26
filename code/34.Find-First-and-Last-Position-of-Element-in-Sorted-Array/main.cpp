#include <iostream>
#include <vector>

int findLeftTarget(const std::vector<int>& nums, int begin, int end, int target)
{
   if (begin > end) return -1;
   if (begin == end) return ((nums[begin] == target) ? begin : -1);

   int mid = (begin + end) / 2;
   if (nums[mid] == target)
   {
      auto left = findLeftTarget(nums, begin, mid - 1, target);
      return (left == -1) ? mid : left;
   }

   if (nums[mid] > target) return findLeftTarget(nums, begin, mid - 1, target);

   return findLeftTarget(nums, mid + 1, end, target);
}

int findRightTarget(const std::vector<int>& nums, int begin, int end, int target)
{
   if (begin > end) return -1;
   if (begin == end) return ((nums[begin] == target) ? begin : -1);

   int mid = (begin + end) / 2;
   if (nums[mid] == target)
   {
      auto right = findRightTarget(nums, mid + 1, end, target);
      return (right == -1) ? mid : right;
   }

   if (nums[mid] > target) return findRightTarget(nums, begin, mid - 1, target);

   return findRightTarget(nums, mid + 1, end, target);
}

std::vector<int> searchRange(const std::vector<int>& nums, int target)
{
   auto left = findLeftTarget(nums, 0, nums.size() - 1, target);
   auto right = findRightTarget(nums, 0, nums.size() - 1, target);
   return { left, right };
}

int main()
{
   std::cout << "34. Find First and Last Position of Element in Sorted Array" << std::endl;

   std::cout << "Range: [ ";
   for (auto data : searchRange({ 5,7,7,8,8,10 }, 6))
   {
      std::cout << data << " ";
   }
   std::cout << "]" << std::endl;

   return 0;
}
