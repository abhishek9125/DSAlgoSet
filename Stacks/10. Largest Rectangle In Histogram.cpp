class Solution
{

private:
    vector<int> findNSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }
        return ans;
    }   

    vector<int> findPSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }
        return ans;
    }   


public:
    int largestRectangleArea(vector<int> &heights) {

        vector<int> next = findNSE(heights);
        vector<int> prev = findPSE(heights);

        int largestArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            largestArea = max(largestArea, heights[i] * (next[i] - prev[i] - 1));
        }

        return largestArea;
    }
};