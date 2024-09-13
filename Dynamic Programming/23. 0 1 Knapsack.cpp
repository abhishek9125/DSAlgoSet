class Solution {
public:
    
    int solveRecursive(vector<int> &wt, vector<int> &val, int index, int W, vector<vector<int>>& dp) {

        if(index < 0 || W == 0) return 0; 
        if(dp[index][W] != -1) return dp[index][W];
        int notTaken = solveRecursive(wt, val, index - 1, W, dp);
        int taken = 0;
        if(wt[index] <= W ) {
            taken = val[index] + solveRecursive(wt, val, index - 1, W - wt[index], dp);
        }

        return dp[index][W] = max(notTaken, taken);
    }

    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solveRecursive(wt, val, n - 1, W, dp);
    }

};