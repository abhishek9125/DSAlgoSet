class Solution {
public:

    bool isPossible(vector<int>& nums, int m, int mid) {
        int pageSum = 0;
        int studentCount = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(pageSum + nums[i] <= mid) {
                pageSum += nums[i];
            } else {
                studentCount++;              
                pageSum = nums[i];
            }
            if(studentCount > m || nums[i] > mid) {
                return false;
            }
        }
        return true;
    }

    int findPages(vector<int> &nums, int m)  {
        int start = 0;
        int sum = 0;

        if(m > nums.size()) return -1;

        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        int end = sum;
        int ans = -1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(isPossible(nums, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};