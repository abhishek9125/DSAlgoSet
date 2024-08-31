class Solution {
public:

    void generate(string& digits, int index, string combos[], string output, vector<string>& result) {
        if(index == digits.size()) {
            result.push_back(output);
            return;
        }

        int digit = digits[index] - '0';

        for(int i = 0; i < combos[digit].size(); i++) {
            generate(digits, index + 1, combos, output + combos[digit][i], result);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string combos[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string output;
        generate(digits, 0, combos, output, result);
        return result;
    }
};