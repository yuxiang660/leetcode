#include <iostream>
#include <string>
#include <vector>

bool isMatch(std::string s, std::string p) {
   int m = p.size();
   int n = s.size();
   // dp[0][0] is true, which means empty string matches empty string
   // dp[1][0] means p[0] matches empty string
   // dp[2][0] means p[0]~p[1] matches emtpy string
   // dp[i][j] means p[0]~p[i-1] matches s[0]~s[j-1]
   std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));

   dp[0][0] = true;

   // boundary case: s is empty string
   for (int i = 1; i <= m; i++) {
      // '*' can ignore last element. If p[0]~p[i-3] matches empty string, p[0]~p[i-1] can match empty string.
      if (p[i-1] == '*') {
         if (i == 1) dp[i][0] = true;
         else dp[i][0] = dp[i - 2][0];
      }
   }

   // man cases: dp[i][j] means p[0]~p[i-1] matches s[0]~s[j-1]
   for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
         // Goal: judge p[0]~p[i-1] matches s[0]~s[j-1] or not, while we know all substring match cases.

         // Case 1: p[i-1] is not '*'. We can get dp[i][j] based on dp[i-1][j-1].
         if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
            dp[i][j] = dp[i - 1][j - 1];
         }

         // Case 2: p[i-1] is '*'.
         if (p[i - 1] == '*') {
            // 2.1: '*' is used to ignore the last element. If p[0]~p[i-3] matches i[0][j-1], p[0]~p[i-1] matches because p[i-2] can be ignored by p[i-1] ('*').
            dp[i][j] = dp[i - 2][j];

            // 2.2: '*' is not used to ignore last element.
            if (p[i - 2] == s[j - 1] || p[i - 2] == '.') {
               // dp[i-2][j-1] means we are not using *. p[0]~p[i-3] should match s[0]~s[j-2]
               // dp[i][j-1] means using * to repeat the last element. p[0]~p[i-1] should match s[0]~s[j-2]
               dp[i][j] = dp[i][j] || dp[i - 2][j - 1] || dp[i][j - 1];
            }
         }
      }
   }

   return dp[m][n];
}

int main() {
   std::cout << "10. Regular Expression Matching" << std::endl;

   std::string s("aa");
   std::string p("a*");

   std::cout << "Is Match: " << std::boolalpha << isMatch(s, p) << std::endl;
}
