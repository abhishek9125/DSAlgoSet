class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        int n = s.size();
        map<char, int> m;

        int l = 0, r = 0, maxLen = 0;

        while(r < n) {

          if(m.find(s[r]) != m.end()) {
            l = max(m[s[r]] + 1, l);
          } 

          int len = r - l + 1;
          maxLen = max(maxLen, len);

          m[s[r]] = r;
          r++;

        }

        return maxLen;
    }
};