class Solution {
  public:
    long long solve(vector<int>& bt) {

      sort(bt.begin(), bt.end());

      int n = bt.size();
      long long waitingTime = 0;
      long long totalTime = 0;

      for(int i = 0; i < n; i++) {
        waitingTime += totalTime;
        totalTime += bt[i];
      }

      return waitingTime / n;
    }
};  