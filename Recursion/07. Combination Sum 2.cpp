class Solution {
public:

    void generate(vector<int>& candidates, int index, int sum, vector<vector<int>>& result, vector<int> output) {
        if(sum == 0) {
            result.push_back(output);
            return;
        }

        if(sum < 0 || index == candidates.size()) {
            return;
        }

        generate(candidates, index + 1, sum, result, output);
        output.push_back(candidates[index]);
        generate(candidates, index, sum - candidates[index], result, output);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> output;

        generate(candidates, 0, target, result, output);
        return result;
    }
};