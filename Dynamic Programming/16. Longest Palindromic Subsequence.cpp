class Solution{
private:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int func(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // Declare a 2D DP array to store length of the LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize first row and first column to 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill in the DP array
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        // The value at dp[n][m] contains length of the LCS
        return dp[n][m];
    }
public:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int longestPalinSubseq(string s){
        // Store a reversed copy of the string
        string t = s;
        reverse(s.begin(), s.end());

        /* Call the LCS function to find the 
        length of the Longest Common Subsequence*/
        return func(s, t);
    }
};