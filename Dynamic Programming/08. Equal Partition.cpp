class Solution{
public:

    bool recursiveSol(vector<int> arr, vector<vector<int>>& dp, int index, int target) {
        if(target == 0) return true;
        if(index == 0) return target == arr[0];

        if(dp[index][target] != -1) return dp[index][target];

        bool skipNext = recursiveSol(arr, dp, index - 1, target);
        bool takeNext = false;

        if(target >= arr[index]) {
            takeNext = recursiveSol(arr, dp, index - 1, target - arr[index]);
        }

        return dp[index][target] = takeNext || skipNext;
    }

    int equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if(sum % 2 == 1) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return recursiveSol(arr, dp, n-1, target); 
    }
};
