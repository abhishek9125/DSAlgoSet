class Solution {
public:

    void dfs(int index, string s, vector<string> path,  vector<vector<string>>& result) {
        if(index == s.size()) {
            result.push_back(path);
            return;
        }

        for(int j = index; j < s.size(); j++) {
            if(isPalindrome(s, index, j)) {
                path.push_back(s.substr(index, j - index + 1));
                dfs(j + 1, s, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;

        dfs(0, s, path, result);

        return result;
    }
};