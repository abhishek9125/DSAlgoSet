class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

      vector<int> result;
      int n = nums.size();

      int currentHighest = INT_MIN;

      int j = n - 1;
      
      while(j >= 0) {
        if(nums[j] > currentHighest) {
            result.push_back(nums[j]);
            currentHighest = nums[j];
        }
        j--;
      }

      int i = 0;
      j = result.size() - 1;

      while(i < j) {
        int temp = result[j];
        result[j] = result[i];
        result[i] = temp;
        i++;
        j--;
      }

      return result;
    }
};