class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        map<int, int> m;
        m[0] = 1;
        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum = prefixSum + nums[i];
            int remove = prefixSum - k;
            count = count + m[remove];
            m[prefixSum]++;
        }

        return count;
    }
};