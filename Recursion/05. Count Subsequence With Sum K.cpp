class Solution{
    public:    	

    int generate(vector<int>& nums, int sum, int index) {
        if(sum == 0) {
            return 1;
        }

        if(sum < 0 || index == nums.size()) {
            return 0;
        }

        return generate(nums, sum - nums[index], index + 1) + generate(nums, sum, index + 1);
    }

    int countSubseqenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        return generate(nums, k, 0);
    }
};