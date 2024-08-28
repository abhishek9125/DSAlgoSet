class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(int i = 0; i < str.length(); i++) {
            char br = str[i];
            if(br == '(' || br == '[' || br == '{') {
                s.push(br);
            } else {
                
                if(s.empty()) {
                    return false;
                }

                char ch = s.top();
                s.pop();

                if(!(ch == '(' && br == ')' || 
                   ch == '[' && br == ']' ||
                   ch == '{' && br == '}' 
                )) {
                    return false;
                }
            }
        }

        return !s.size();
    }
};