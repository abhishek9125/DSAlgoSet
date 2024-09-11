class Solution {
  public:

    bool isAllStars(string s1, int i) {
        for (int j = 0; j <= i; j++) {
            if (s1[j] != '*')
                return false;
        }
        return true;
    }

    bool solveRecursive(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
      
      if(i < 0 && j < 0) return true;
      if(i < 0 && j >= 0) return false;
      if(j < 0 && i >= 0) return isAllStars(s1, i);

      if(s1[i] == s2[j] || s1[i] == '?') {
        return dp[i][j] = solveRecursive(s1, s2, i - 1, j - 1, dp);
      }

      if(s1[i] == '*') {
        return dp[i][j] = solveRecursive(s1, s2, i - 1, j, dp) || solveRecursive(s1, s2, i, j - 1, dp);
      }

      return false;

    }

    bool wildCard(string s1, string s2) {
      int n = s1.size();
      int m = s2.size();
      vector<vector<int>> dp(n, vector<int>(m, -1));
      return solveRecursive(s1, s2, n - 1, m - 1, dp);
    }
};
