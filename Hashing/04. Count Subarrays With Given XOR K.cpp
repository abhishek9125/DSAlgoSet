class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        map<int, int> m;
        int xr = 0;
        int count = 0;
        m[xr] = 1;
        for(int i = 0; i < nums.size(); i++) {
            xr = xr ^ nums[i];
            int x = xr ^ k;
            count = count + m[x];
            m[xr]++;
        }

        return count;
    }
};