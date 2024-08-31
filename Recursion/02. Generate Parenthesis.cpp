class Solution {
public:

    void generate(vector<string>& s, int open, int close, int index, string output, int n) {
        if(2*n == index) {
            s.push_back(output);
            return;
        }

        if(open < n) {
            generate(s, open + 1, close, index + 1, output + '(', n);
        }

        if(close < open) {
            generate(s, open, close + 1, index + 1, output + ')', n);
        }
    }

    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string> s;
        generate(s, 0, 0, 0, "", n);
        return s;
    }
};