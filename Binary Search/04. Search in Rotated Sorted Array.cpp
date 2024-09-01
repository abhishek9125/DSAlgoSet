class Solution {
public:

    int getPivot(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }

    int binarySearch(vector<int>& nums, int k, int s, int e) {
        int start = s;
        int end = e;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == k) {
                return mid;
            } else if(nums[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int> &nums, int k) {

        if(nums.size() == 0) return -1;
        int pivot = getPivot(nums);
        if(k >= nums[pivot] && k <= nums[nums.size() - 1]) {
            return binarySearch(nums, k, pivot, nums.size() - 1);
        } else {
            return binarySearch(nums, k, 0, pivot - 1);
        }
    }
};