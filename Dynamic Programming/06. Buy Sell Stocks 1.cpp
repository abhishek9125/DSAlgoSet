class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int mini = arr[0];
        int profit = 0;

        for(int i = 1; i < n; i++) {
            int cost = arr[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, arr[i]);
        }

        return profit;
    }
};

