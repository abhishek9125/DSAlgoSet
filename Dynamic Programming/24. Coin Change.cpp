class Solution{
	public:

	int solveRecursive(vector<int>& coins, int index, int amount, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        
		if(index == 0) {
			if(amount % coins[0] == 0) {
				return amount / coins[0];
			} else {
				return 1e9;
			}
		}

		if(dp[index][amount] != -1) {
			return dp[index][amount];
		}

		int notTaken = solveRecursive(coins, index - 1, amount, dp);
		int taken = 1e9;
		if(amount >= coins[index]) {
			taken = 1 + solveRecursive(coins, index, amount - coins[index], dp);
		}

		return dp[index][amount] = min(notTaken, taken);

	}

	int MinimumCoins(vector<int>& coins, int amount) {
		int n = coins.size();
  		vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
		int ans = solveRecursive(coins, n - 1, amount, dp);
		if(ans >= 1e9) return -1;
		return ans;
    }
};