#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<std::vector<int>> triangle_11 =
{
   {2},
   {3,4},
   {6,5,7},
   {4,1,8,3}
};

std::vector<std::vector<int>> triangle_12 =
{
   {2},
   {3,2},
   {6,5,7},
   {4,4,8,1}
};

int minimumTotal(const std::vector<std::vector<int>>& triangle)
{
   auto minSumTriangle = triangle;

   for (size_t row = 1; row < triangle.size(); row++)
   {
      const auto& lastLayer = minSumTriangle[row - 1];
      for (size_t column = 0; column < triangle[row].size(); column++)
      {
         if (column == 0)
         {
            minSumTriangle[row][column] = lastLayer[column] + triangle[row][column];
         }
         else if (column == triangle[row].size() - 1)
         {
            minSumTriangle[row][column] = lastLayer[column - 1] + triangle[row][column];
         }
         else
         {
            minSumTriangle[row][column] = std::min(lastLayer[column - 1], lastLayer[column]) + triangle[row][column];
         }
      }
   }

   return *(std::min_element(minSumTriangle.back().begin(), minSumTriangle.back().end()));
}

int minimumTotal2(const std::vector<std::vector<int>>& triangle)
{
   auto minSumTriangle = triangle;

   for (int row = triangle.size() - 2; row >= 0; row--)
   {
      for (int column = 0; column < triangle[row].size(); column++)
      {
         minSumTriangle[row][column] = std::min(minSumTriangle[row + 1][column], minSumTriangle[row + 1][column + 1]) + triangle[row][column];
      }
   }

   return minSumTriangle[0][0];
}

int minimumTotal_recursion(const std::vector<std::vector<int>>& triangle, int row, int column)
{
   if (row == triangle.size() - 1)
   {
      return triangle[row][column];
   }

   return triangle[row][column] + std::min(minimumTotal_recursion(triangle, row + 1, column), minimumTotal_recursion(triangle, row + 1, column + 1));
}

int minimumTotal3(const std::vector<std::vector<int>>& triangle)
{
   return minimumTotal_recursion(triangle, 0, 0);
}

void main()
{
   std::cout << "120. Triangle" << std::endl;

   std::cout << "minimum path sum: " << minimumTotal3(triangle_12) << std::endl;
}