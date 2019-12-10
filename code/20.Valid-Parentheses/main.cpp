#include <iostream>
#include <stack>
#include <string>

bool isLeftParenthesis(const char parenthesis)
{
   const std::string leftParentheses("({[");

   auto found = leftParentheses.find(parenthesis);

   return (found == std::string::npos) ? false : true;
}

bool isParenthesesMatch(const char leftParenthesis, const char rightParenthesis)
{
   switch (leftParenthesis)
   {
   case '(':
      return rightParenthesis == ')' ? true : false;
   case '[':
      return rightParenthesis == ']' ? true : false;
   case '{':
      return rightParenthesis == '}' ? true : false;
   default:
      return false;
   }
}

bool isValidParentheses(const std::string& parentheses)
{
   std::stack<char> leftParentheses;

   for (const auto& parenthesis : parentheses)
   {
      if (isLeftParenthesis(parenthesis))
      {
         leftParentheses.push(parenthesis);
      }
      else
      {
         if (leftParentheses.empty()) return false;

         if (!isParenthesesMatch(leftParentheses.top(), parenthesis)) return false;
         leftParentheses.pop();
      }
   }

   return leftParentheses.empty();
}

void main()
{
   std::cout << "20. Valid Parentheses" << std::endl;

   std::cout << (isValidParentheses("{") ? "true" : "false") << std::endl;
}