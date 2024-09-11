class Solution{

  public:

	bool solveRecursive(int index, int target, vector<int>&arr, vector<vector<int>>& dp) {
		if(target == 0) return dp[index][target] = true;
		if(index == 0) return dp[index][target] = (arr[index] == target);

		if(dp[index][target] != -1) {
			return dp[index][target];
		}

		bool skipNext = solveRecursive(index - 1, target, arr, dp);
		bool takeNext = false;
		if(arr[index] <= target) {
			takeNext = solveRecursive(index - 1, target - arr[index], arr, dp);
		}

		return dp[index][target] = skipNext || takeNext;

	}

	int minDifference(vector<int>&arr, int n)  { 
		
		int totalSum = 0;

		for(int i = 0; i < n; i++) totalSum += arr[i];

		vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
		for(int i = 0; i <= totalSum; i++) {
			bool dummy = solveRecursive(n - 1, i, arr, dp);
		}

		int mini = INT_MAX;
		for(int i = 0; i <= totalSum; i++) {
			if(dp[n-1][i] == true) {
				mini = min(mini, abs(i - (totalSum - i)));
			}
		}

		return mini;
	} 
};
