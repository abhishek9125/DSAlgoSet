class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> numIndexMap; 

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int required = target - num;
            if(numIndexMap.find(required) != numIndexMap.end()) {
                return { numIndexMap[required], i };
            }
            numIndexMap[num] = i;
        }

        return { -1, -1 };
    }
};