class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        //your code goes here
        int n = cardScore.size();
        int total = 0;

        for(int i = 0; i < k; i++) {
          total += cardScore[i];
        }

        int maxi = total;
        int right = n - 1;

        for(int i = k - 1; i >= 0; i--) {
          total -= cardScore[i];
          total += cardScore[right--];
          maxi = max(maxi, total);
        }

        return maxi;
    }
};