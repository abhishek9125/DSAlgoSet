class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {

        stack<int> s;
        int n = arr.size();
        vector<int> result(n, -1);

        for(int i = n - 1; i>=0; i--) {
            while(!s.empty() && arr[i] >= s.top()) {
                s.pop();
            }

            if(!s.empty()) {
                result[i] = s.top();
            }

            s.push(arr[i]);
        }

        return result;
    }
};
