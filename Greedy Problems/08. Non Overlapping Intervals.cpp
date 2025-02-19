class Solution {
public:

    static bool cmp(vector<int> val1, vector<int> val2) {
        return val1[1] < val2[1];
    }

    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        sort(Intervals.begin(), Intervals.end(), cmp);

        int n = Intervals.size();

        int count = 1;

        int endTime = Intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(Intervals[i][0] >= endTime) {
                count++;
                endTime = Intervals[i][1];
            }
        } 

        return n - count;

    }
};