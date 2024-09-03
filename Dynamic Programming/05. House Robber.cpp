class Solution {
public:

    int solve(vector<int>& money, int start, int end) {
        int n = money.size(); 
        vector<int> dp(n);

        dp[start] = money[start];
        dp[start + 1] = max(money[start], money[start + 1]);

        for(int i = start + 2; i < end; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + money[i]);
        }

        return dp[end - 1];
    }

    int houseRobber(vector<int>& money) {
        int n = money.size();
        int first = solve(money, 0, n-1);
        int second = solve(money, 1, n);

        return max(first, second);
    }
};