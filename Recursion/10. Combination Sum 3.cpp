class Solution {
public:

    void func(int sum, int last, vector<int> &output, int k, vector<vector<int>> &result) {

        if(output.size() == k && sum == 0) {
            result.push_back(output);
            return;
        }

        if(sum < 0 || output.size() > k) return;

        for(int i = last; i <= 9; i++) {
            if(i <= sum) {
                output.push_back(i);
                func(sum - i, i + 1, output, k, result);
                output.pop_back();
            } else {
                break;
            }
        }

    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> output;
        func(n, 1, output, k, result);
        return result;
    }
};