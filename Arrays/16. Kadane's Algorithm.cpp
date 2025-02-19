class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSumAccumulator = 0;
        int maximumSubArraySum = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            currentSumAccumulator = currentSumAccumulator + nums[i];
            if(currentSumAccumulator < 0) {
                currentSumAccumulator = 0;
            } else {
                maximumSubArraySum = max(maximumSubArraySum, currentSumAccumulator);
            }
        }

        return maximumSubArraySum;
    }
};