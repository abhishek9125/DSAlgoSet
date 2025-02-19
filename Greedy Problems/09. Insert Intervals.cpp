class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here
        vector<vector<int>> result;
        int i = 0;
        int n = Intervals.size();

        while(i < n && Intervals[i][1] < newInterval[0]) {
            result.push_back(Intervals[i]);
            i = i + 1;
        }

        while(i < n && Intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], Intervals[i][0]);
            newInterval[1] = max(newInterval[1], Intervals[i][1]);
            i = i + 1;
        }

        result.push_back(newInterval);

        while(i < n) {
            result.push_back(Intervals[i]);
            i = i + 1;
        }

        return result;
    }
};