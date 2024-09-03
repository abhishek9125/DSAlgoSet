// Space Optimised
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {

        int n = nums.size();
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            int temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }

        return prev1;
    }
};

// Memoisation
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};