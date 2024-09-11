class Solution{
  public:	
	const int prime = 1e9 + 7;
	int solveRecursive(string s, string t, int i, int j, vector<vector<int>>& dp) {
		if(j < 0) return 1;
		if(i < 0) return 0;
		if(dp[i][j] != - 1) return dp[i][j];

		if(s[i] == t[j]) {
			return dp[i][j] = (solveRecursive(s, t, i - 1, j - 1, dp) + solveRecursive(s, t, i - 1, j, dp)) % prime;
		} else {
			return dp[i][j] = solveRecursive(s, t, i - 1, j, dp);
		}
	}

	int distinctSubsequences(string s, string t){
		int n = s.length();
		int m = t.length();

		vector<vector<int>> dp(n, vector<int>(m, -1));
	   
	   	return solveRecursive(s, t, n - 1, m - 1, dp);
	}
};