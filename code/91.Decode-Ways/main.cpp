#include <iostream>
#include <string>
#include <vector>

bool decode(const char num)
{
   return (num != '0');
}

bool decodeWithLastNum(const char lastNum, const char num)
{
   switch (lastNum)
   {
   case '1':
      return true;
   case '2':
      if (num <= '6') return true;
   default:
      break;
   }

   return false;
}

int numDecodings(const std::string& encode)
{
   std::vector<int> decodeValues(encode.size());
  
   for (size_t i = 0; i < decodeValues.size(); i++)
   {
      if (i == 0)
      {
         decodeValues[0] = decode(encode[0]);
      }
      else if (i == 1)
      {
         decodeValues[1] = (decode(encode[1]) ? decodeValues[i - 1] : 0) + decodeWithLastNum(encode[0], encode[1]);
      }
      else
      {
         decodeValues[i] = (decode(encode[i]) ? decodeValues[i - 1] : 0) +
                           (decodeWithLastNum(encode[i - 1], encode[i]) ? decodeValues[i - 2] : 0);
      }
   }

   return decodeValues.back();
}

int main()
{
   std::cout << "91. Decode Ways" << std::endl;

   std::cout << "Decode number: " << numDecodings("91") << std::endl;

   return 0;
}