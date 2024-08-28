class Solution
{
    private:
        vector<int> findPGE(vector<int>& arr) {

            int n = arr.size();
            vector<int> ans(n);
            stack<int> s;

            for(int i = 0; i < n; i++) {

                while(!s.empty() && arr[s.top()] <= arr[i]) {
                    s.pop();
                }

                ans[i] = s.empty() ? -1 : s.top();

                s.push(i);
            }

            return ans;
        }

    public:
        vector <int> stockSpan(vector<int> arr, int n) {
            vector<int> prev = findPGE(arr);
            vector<int> ans(n);

            for(int i = 0; i < n; i++) {
                ans[i] = i - prev[i];
            }

            return ans;
        }
};
