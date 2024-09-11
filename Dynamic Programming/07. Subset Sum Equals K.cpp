// Bottom Up
class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for(int i = 0; i < n; i++){ 
            dp[i][0] = true;
        }

        if(arr[0] <= target) {
            dp[0][arr[0]] = true;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j) {
                    take = dp[i-1][j - arr[i]];
                }
                dp[i][j] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};

// Top Down
class Solution{   
public:

    bool solveRecursive(vector<int>arr, vector<vector<int>>& dp, int index, int target) {
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;

        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        bool skipNext = solveRecursive(arr, dp, index - 1, target);
        bool takeNext = false;
        if(target >= arr[index]) {
            takeNext = solveRecursive(arr, dp, index - 1, target - arr[index]);
        }

        return dp[index][target] = takeNext || skipNext;
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveRecursive(arr, dp, n - 1, target);
    }
};

// Recursive
class Solution{   
public:
    bool solveRecursive(vector<int>arr, int index, int target) {
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;

        bool skipNext = solveRecursive(arr, index - 1, target);
        bool takeNext = false;
        if(target >= arr[index]) {
            takeNext = solveRecursive(arr, index - 1, target - arr[index]);
        }

        return takeNext || skipNext;
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return solveRecursive(arr, n - 1, target);
    }
};