class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 

        int longest = 1; 
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        for(auto i: s) {
            if(s.find(i - 1) == s.end()) {
                int count = 1;
                int x = i;

                while(s.find(x+1) != s.end()) {
                    count++;
                    x = x + 1;
                }
                longest = max(longest, count);
            }
        }

        return longest;

    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int lastSmaller = INT_MIN;
        int longest = 1;

        int count = 1;

        for(int i = 0; i < n; i++) {
            int x = nums[i];

            if(nums[i] - 1 == lastSmaller) {
                count++;
                lastSmaller = nums[i];
            } else if(nums[i] != lastSmaller) {
                lastSmaller = nums[i];
                count = 1;
            }

            longest = max(longest, count);
        }

        return longest;

    }
};