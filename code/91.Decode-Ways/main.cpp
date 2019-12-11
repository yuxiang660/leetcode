#include <iostream>
#include <string>
#include <vector>

bool decodeWithLastCharacter(const std::string& encode, size_t i)
{
   if (encode[i - 1] == '0') return false;

   int number = std::stoi(std::string(encode.begin() + i - 1, encode.begin() + i + 1));

   return (number >= 1) && (number <= 26);
}

bool decodeCurrentCharacter(const std::string& encode, size_t i)
{
   return (encode[i] != '0');
}

int numDecodings(const std::string& encode)
{
   std::vector<int> decodeValues(encode.size());
  
   for (size_t i = 0; i < decodeValues.size(); i++)
   {
      if (i == 0)
      {
         decodeValues[i] = decodeCurrentCharacter(encode, i);
      }
      else if (i == 1)
      {
         decodeValues[i] = (decodeCurrentCharacter(encode, i) ? decodeValues[i - 1] : 0) + decodeWithLastCharacter(encode, i);
      }
      else
      {
         decodeValues[i] = (decodeCurrentCharacter(encode, i) ? decodeValues[i - 1] : 0) +
                           (decodeWithLastCharacter(encode, i) ? decodeValues[i - 2] : 0);
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