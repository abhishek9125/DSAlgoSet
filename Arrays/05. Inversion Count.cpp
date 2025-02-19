class Solution {
public:

    long long int merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> temp;
        int left = start;
        int right = mid + 1;

        long long int count = 0;

        while(left <= mid && right <= end) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                count = count + (mid - left + 1);
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= end) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }

        return count;
    }

    long long int mergeSort(vector<int>& nums, int start, int end) {
        long long int count = 0;

        if(start < end) {
            int mid = start + ( end - start ) / 2;
            count += mergeSort(nums, start, mid);
            count += mergeSort(nums, mid + 1, end);
            count += merge(nums, start, mid, end);
        }

        return count;
    }

    long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();
        return mergeSort(nums, 0 , n - 1);
    }
};