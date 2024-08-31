class Solution {
public:	

    void generate(vector<int>& nums, vector<vector<int>>& result, vector<int> output, int index) {

        if(index == nums.size()) {
            result.push_back(output);
            return;
        }

        generate(nums, result, output, index + 1);
        output.push_back(nums[index]);
        generate(nums, result, output, index + 1);

    }

    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> result;
        vector<int> output;

        generate(nums, result, output, 0);

        return result;
    }
};