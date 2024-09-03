class Solution{
    public:

    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        int n = start.size();
        
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), compare);

        int count = 1;
        int timeEnd = v[0].second;
        for(int i = 1; i < n; i++) {
            if(v[i].first > timeEnd) {
                count++;
                timeEnd = v[i].second;
            }
        }
        return count;

        return count;

    }
};