// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        for(int i = 0; i < k; i++) {
            int num = q.front();
            q.pop();
            s.push(num);
        }
        
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        int t = q.size() - k;
        
        for(int i = 0; i < t; i++) {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        
        return q;
    }
};