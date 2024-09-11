#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int mod = (int)1e9 + 7;

    int recursiveSol(vector<int>& arr, vector<vector<int>>& dp, int target, int index) {
      if(target == 0) return 1;
      if(index == 0) return arr[0] == target ? 1 : 0;

      if(dp[index][target] != - 1) return dp[index][target];

      int skipNext = recursiveSol(arr, dp, target, index - 1);
      int takeNext = 0;
      if(arr[index] <= target) {
        takeNext = recursiveSol(arr, dp, target - arr[index], index - 1);
      }

      return dp[index][target] = (skipNext + takeNext) % mod;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {

        int totalSum = 0;
        for(auto i : arr) {
          totalSum += i;
        }

        if(totalSum - diff < 0) return 0;
        if((totalSum - diff) % 2 == 1) return 0;

        int target = (totalSum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return recursiveSol(arr, dp, target, n - 1);
      }
};