class Solution {
public:

    int findFloor(vector<int>& nums, int x) {
        int start = 0;
        int end = nums.size() - 1;

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= x) {
                ans = nums[mid];
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }

    int findCeil(vector<int>& nums, int x) {
        int start = 0;
        int end = nums.size() - 1;

        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= x) {
                ans = nums[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = findFloor(nums, x);
        int ceil = findCeil(nums, x);
        return { floor, ceil };
    }
};