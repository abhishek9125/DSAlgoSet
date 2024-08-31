class Solution {
public:

    void func(int index, vector<int> output, vector<int> &nums, vector<vector<int>> &result) {
    
        if(index == nums.size()) {
            result.push_back(output);
            return;
        }

        output.push_back(nums[index]);
        func(index + 1, output, nums, result);

        output.pop_back();

        for(int j = index + 1; j < nums.size(); j++) {
            if(nums[j] != nums[index]) {
                func(j, output, nums, result);
                return;
            }
        }

        func(nums.size(), output, nums, result);
        
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> output;
        sort(nums.begin(), nums.end());
        func(0, output, nums, result);
        return result; 
    }
};  