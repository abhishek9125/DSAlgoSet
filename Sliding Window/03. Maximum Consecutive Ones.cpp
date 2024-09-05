class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here

        int n = nums.size();

        int left = 0;
        int right = 0;
        int maxLength = 0;
        int zeros = 0;

        while(right < n) {

            if(nums[right] == 0) zeros++;

            if(zeros > k) {
                if(nums[left] == 0) zeros--;
                left++;
            } else {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }

        return maxLength;
    }
};