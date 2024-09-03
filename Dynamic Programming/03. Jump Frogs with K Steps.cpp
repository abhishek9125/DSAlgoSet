class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();

        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(heights[1] - heights[0]);

        for(int i = 2; i < n; i++) {
            int minJump = INT_MAX;
            for(int j = 1; j <= k; j++) {
                if(i - j >= 0) {
                    int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                    minJump = min(minJump, jump);
                }
            }
            dp[i] = minJump;
        }

        return dp[n-1];
    }
};
