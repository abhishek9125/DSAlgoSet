class Solution {
public:

    bool solveHeap(int parent, vector<int>& nums) {
        int left = 2*parent + 1;
        int right = 2*parent + 2;

        if(left < nums.size()) {
            if(nums[left] < nums[parent]) {
                return false;
            } 
            if(!solveHeap(left, nums)) return false;
        }

        if(right < nums.size()) {
            if(nums[right] < nums[parent]) {
                return false;
            }
            if(!solveHeap(right, nums)) return false;
        }

        return true;
    }

    bool isHeap(vector<int>& nums) {
        if(nums.size() == 0) return false;
        return solveHeap(0, nums);
    }
};