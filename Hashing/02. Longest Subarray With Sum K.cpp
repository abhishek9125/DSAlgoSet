// For Positive Numbers and Zeroes only
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int n = a.size();
    long long sum = a[0];

    while(right < n) {

        while(left <= right && sum > k) {
            sum = sum - a[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if(right < n) {
            sum = sum + a[right];
        }

    }

    return maxLen;
}

// For Positives and Negatives
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){

        map<int, int> prefixSum;
        
        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if(sum == k) {
                maxLen = max(maxLen, i + 1);
            }
            if(prefixSum.find(sum - k) != prefixSum.end()) {
                int len = i - prefixSum[sum - k];
                maxLen = max(maxLen, len);
            }
            if(prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }

        return maxLen;
    }
};


// Brute Force
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        
        int n = nums.size();
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = sum + nums[j];
                if(sum == k) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;

    }
};
