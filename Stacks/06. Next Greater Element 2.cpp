class Solution {
public:

    void solveStack(stack<int>& s, vector<int>& result, vector<int>& arr, int start, int end) {
        for(int i = start; i > end; i--) {
            while(!s.empty() && arr[i] >= s.top()) {
                s.pop();
            }

            if(!s.empty()) {
                result[i] = s.top();
            }

            s.push(arr[i]);
        }
    }

    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> result(n, -1);

        int maxElement = INT_MIN;
        int maxIndex = 0;

        for(int i = 0 ; i < n; i++) {
            if(maxElement < arr[i]) {
                maxElement = arr[i];
                maxIndex = i;
            }
        }

        solveStack(s, result, arr, maxIndex, -1);
        solveStack(s, result, arr, n - 1, maxIndex);

        return result;
    }
};