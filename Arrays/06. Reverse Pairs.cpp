class Solution {
public:

    void merge(vector<int>& nums, int start, int mid, int end) {
        
        vector<int> temp;

        int left = start;
        int right = mid + 1;

        while(left <= mid && right <= end) {
            if(nums[left] < nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left++]);
        }

        while(right <= end) {
            temp.push_back(nums[right++]);
        }

        for(int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    int countPairs(vector<int>& nums, int start, int mid, int end) {
        
        int count = 0;
        int right = mid + 1;

        for(int i = start; i <= mid; i++) {
            while(right <= end && nums[i] > 2*nums[right]) {
                right++;
            }
            count += right - (mid + 1);
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int start, int end) {

        int count = 0;

        if(start < end) {
            int mid = start + (end - start) / 2;
            count += mergeSort(nums, start, mid);
            count += mergeSort(nums, mid + 1, end);
            count += countPairs(nums, start, mid, end);
            merge(nums, start, mid, end);
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);    
    }
};