class Solution{
    public:

    bool generate(vector<int>& nums, int sum, int index) {
        if(sum == 0) return true;
        if(sum < 0 || index == nums.size()) return false;

        return generate(nums, sum - nums[index], index + 1) || generate(nums, sum, index + 1);
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
         return generate(nums, k, 0);

    }
};