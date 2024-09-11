class Solution {
  public:

    int solveRecursive(string& s1, string& s2, int i1, int i2, vector<vector<int>>& dp) {
      if(i1 < 0 || i2 < 0) {
        return 0;
      }

      if(dp[i1][i2] != - 1) return dp[i1][i2];

      if(s1[i1] == s2[i2]) {
        return dp[i1][i2] = 1 + solveRecursive(s1, s2, i1 - 1, i2 - 1, dp);
      } 

      return dp[i1][i2] = max(solveRecursive(s1, s2, i1, i2 - 1, dp), solveRecursive(s1, s2, i1 - 1, i2, dp));
    }

    int lcs(string str1, string str2) {
      int n = str1.length();
      int m = str2.length();

      vector<vector<int>> dp(n, vector<int>(m, -1));

      return solveRecursive(str1, str2, n - 1, m - 1, dp);
    }
};

// Iterative
class Solution {
  public:
    int lcs(string str1, string str2) {
      int n = str1.length();
      int m = str2.length();

      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
          if(str1[i - 1] == str2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }

      return dp[n][m];
    }
};

