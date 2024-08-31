class Solution {
  public:

    void generate(vector<int>& nums, vector<int>& ans, int index, int sum) {
      if(index == nums.size()) {
        ans.push_back(sum);
        return;
      }

      generate(nums, ans, index + 1, sum + nums[index]);
      generate(nums, ans, index + 1, sum);
    }

    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int> ans;
        generate(nums, ans, 0, 0);
        return ans;
    }
};