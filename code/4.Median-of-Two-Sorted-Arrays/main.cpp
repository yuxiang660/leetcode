#include <algorithm>
#include <iostream>
#include <vector>

int getElement(int index, const std::vector<int>& nums1, const std::vector<int>& nums2)
{
   int len1 = nums1.size();
   int len2 = nums2.size();
   int numberOfElements = index + 1;

   int minNumFromNums1 = std::max(0, numberOfElements - len2); // all nums2 elements contribute to the small part.
   int maxNumFromNums1 = std::min(numberOfElements, len1); // all nums2 elements contribute to the large part.

   // "numberOfElements" elements consist of "numFromNums1" elements in "nums1" and "numFromNums2" elements in "nums2".
   int numFromNums1 = (minNumFromNums1 + maxNumFromNums1) / 2;
   int numFromNums2 = numberOfElements - numFromNums1;

   while (true)
   {
      // "numFromNums1" is too large since "nums1[numFromNums1 - 1] > nums2[numFromNums2]"
      if (numFromNums1 != 0 && numFromNums2 != len2 && nums1[numFromNums1 - 1] > nums2[numFromNums2])
      {
         maxNumFromNums1 = numFromNums1 - 1;
      }
      // "numFromNums1" is too small since "nums1[numFromNums1] < nums2[numFromNums2 - 1]".
      else if (numFromNums2 != 0 && numFromNums1 != len1 && nums1[numFromNums1] < nums2[numFromNums2 - 1])
      {
         minNumFromNums1 = numFromNums1 + 1;
      }
      else
      {
         if (numFromNums1 == 0) return nums2[numFromNums2 - 1];
         if (numFromNums2 == 0) return nums1[numFromNums1 - 1];
         return std::max(nums1[numFromNums1 - 1], nums2[numFromNums2 - 1]);
      }

      numFromNums1 = (minNumFromNums1 + maxNumFromNums1) / 2;
      numFromNums2 = numberOfElements - numFromNums1;
   }
}

double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
   auto len = nums1.size() + nums2.size();

   if (len % 2) return getElement(len / 2, nums1, nums2);
   return  (getElement((len / 2 - 1), nums1, nums2) + getElement((len / 2), nums1, nums2))/ 2.0;
}

int main()
{
   std::cout << "4. Median of Two Sorted Arrays" << std::endl;
   std::cout << "The median is " << findMedianSortedArrays({ 1,2 }, { 3,4 }) << std::endl;;
}
