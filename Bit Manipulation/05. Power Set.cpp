class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        int n = nums.size();
        vector<vector<int>> ans;

        int count = (1 << n);

        for(int val = 0; val < count; val++) {
            vector<int> subset;
            for(int i = 0; i < n; i++) {
                if(val & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};