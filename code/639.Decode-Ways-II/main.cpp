#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int64_t decode(const char num)
{
   if (num == '*') return 9;

   if (num != '0') return 1;

   return 0;
}

int64_t decodeWithLastNum(const char lastNum, const char num)
{
   switch (lastNum)
   {
   case '*':
      if (num == '*') return 15;
      if (num <= '6') return 2;
      return 1;
   case '1':
      if (num == '*') return 9;
      return 1;
   case '2':
      if (num == '*') return 6;
      if (num <= '6')  return 1;
      return 0;
   default:
      break;
   }

   return 0;
}

static int64_t mod = std::pow(10, 9) + 7;

int numDecodings(const std::string& encode)
{
   std::vector<int64_t> decodeValues(encode.size());

   for (size_t i = 0; i < encode.size(); i++)
   {
      if (i == 0)
      {
         decodeValues[0] = decode(encode[0]);
      }
      else if (i == 1)
      {
         decodeValues[1] = decodeWithLastNum(encode[0], encode[1]) + decode(encode[1]) * decodeValues[0];
      }
      else
      {
         decodeValues[i] = (decodeWithLastNum(encode[i - 1], encode[i]) * decodeValues[i - 2] +
                            decode(encode[i]) * decodeValues[i - 1]) % mod;
      }
   }

   return decodeValues.back();
}

int main()
{
   std::cout << "639. Decode Ways II" << std::endl;

   std::cout << "Decode value: " << numDecodings("*********") << std::endl;

   return 0;
}
