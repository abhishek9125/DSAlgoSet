class Solution{
	public:
	int modulo = 1e9+7;
	int solveRecursive(vector<int>&arr,vector<vector<int>>& dp, int index, int target) {
		if(target == 0) return 1;
		if(index == 0) return arr[0] == target ? 1 : 0;

		if(dp[index][target] != -1) return dp[index][target];

		int skipNext = solveRecursive(arr, dp, index - 1, target);
		int takeNext = 0;
		if(arr[index] <= target) {
			takeNext = solveRecursive(arr, dp, index - 1, target - arr[index]);
		}

		return dp[index][target] = (skipNext + takeNext) % modulo;
	}

	int perfectSum(vector<int>&arr, int K){
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(K+1, -1));
		return solveRecursive(arr, dp, n - 1, K);
	}
};