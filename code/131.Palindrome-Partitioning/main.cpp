#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool isPalindrome(const std::string& s)
{
   for (int i = 0, j = s.size() - 1; j - i > 0; i++, j--)
   {
      if (j - i <= 0) return true;

      if (s[i] != s[j]) return false;
   }

   return true;
}

std::unordered_map<std::string, std::vector<std::vector<std::string>>> partitionMap;

std::vector<std::vector<std::string>> partition(const std::string& s)
{
   if (s.empty()) return { {} };
   if (partitionMap.count(s) > 0) return partitionMap[s];

   std::vector<std::vector<std::string>> palindromePartition;

   for (int i = s.size() - 1; i >= 0; i--)
   {
      std::string subString = std::string(s.begin(), s.begin() + i);
      std::string tail = std::string(s.begin() + i, s.end());

      if (isPalindrome(tail))
      {
         for (auto onePartition : partition(subString))
         {
            onePartition.push_back(tail);
            palindromePartition.push_back(onePartition);
         }
      }
   }

   partitionMap.emplace(s, palindromePartition);

   return palindromePartition;
}

std::vector<std::vector<std::string>> partition_DP(const std::string& s)
{
   if (s.empty()) return { {} };

   std::unordered_map<std::string, std::vector<std::vector<std::string>>> partitionMap_DP;

   partitionMap_DP.emplace("", std::vector<std::vector<std::string>>{ {} });

   for (int i = 0; i < s.size(); i++)
   {
      std::string stringKey(s.begin(), s.begin() + i + 1);
      std::vector<std::vector<std::string>> partitionsValue;

      for (int j = i; j >= 0; j--)
      {
         std::string subString = std::string(s.begin(), s.begin() + j);
         std::string tail = std::string(s.begin() + j, s.begin() + i + 1);

         if (isPalindrome(tail))
         {
            for (auto onePartition : partitionMap_DP[subString])
            {
               onePartition.push_back(tail);
               partitionsValue.push_back(onePartition);
            }
         }
      }

      partitionMap_DP.emplace(stringKey, partitionsValue);
   }

   return partitionMap_DP[s];
}

int main()
{
   std::cout << "131. Palindrome Partitioning" << std::endl;

   std::string s("efe");

   std::cout << "Recusion Solution:" << std::endl;
   for (const auto& palindormes : partition(s))
   {
      std::cout << "[ ";
      for (const auto& palindorme : palindormes)
      {
         std::cout << palindorme << " ";
      }
      std::cout << "]" << std::endl;
   }

   std::cout << "DP Solution:" << std::endl;
   for (const auto& palindormes : partition_DP(s))
   {
      std::cout << "[ ";
      for (const auto& palindorme : palindormes)
      {
         std::cout << palindorme << " ";
      }
      std::cout << "]" << std::endl;
   }

   return 0;
}
