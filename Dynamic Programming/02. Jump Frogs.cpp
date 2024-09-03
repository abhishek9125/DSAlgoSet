class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) return 0;
        
        int prev = 0;
        int post = abs(heights[1] - heights[0]);

        for(int i = 2; i < n; i++) {
            int one = post + abs(heights[i] - heights[i-1]);
            int two = prev + abs(heights[i] - heights[i-2]);
            prev = post;
            post = min(one, two);
        }

        return post;
    }
};

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n);
        
        dp[0] = 0;
        dp[1] = abs(heights[1] - heights[0]);

        for(int i = 2; i < n; i++) {
            int one = dp[i-1] + abs(heights[i] - heights[i-1]);
            int two = dp[i-2] + abs(heights[i] - heights[i-2]);
            dp[i] = min(one, two);
        }

        return dp[n-1];
    }
};