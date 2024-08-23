// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans = "";
		    
		    for(int i = 0; i < A.length(); i++) {
		        char ch = A[i];
		        q.push(ch);
	            count[ch]++;
	            
		        while(!q.empty()) {
		            if(count[q.front()] > 1) {
		                q.pop();
		            } else {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty()) {
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;
		}

};