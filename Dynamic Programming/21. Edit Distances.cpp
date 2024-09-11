class Solution {
  public:

    int solveRecursive(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
      
      if(i < 0) return j + 1;
      if(j < 0) return i + 1;

      if(dp[i][j] != -1) return dp[i][j];

      if(s1[i] == s2[j]) {
        return dp[i][j] = solveRecursive(s1, s2, i - 1, j - 1, dp);
      } else {
        int op1 = solveRecursive(s1, s2, i - 1, j, dp);
        int op2 = solveRecursive(s1, s2, i, j - 1, dp);
        int op3 = solveRecursive(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = 1 + min(op1, min(op2, op3));
      }

    }

    int editDistance(string start, string target) {
      int n = start.size();
      int m = target.size();

      vector<vector<int>> dp(n, vector<int>(m, -1));
      return solveRecursive(start, target, n - 1, m - 1, dp);
    }
};

