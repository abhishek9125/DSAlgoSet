// https://www.geeksforgeeks.org/problems/queue-reversal/1

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        
        while(!q.empty()){
            int num = q.front();
            q.pop();
            s.push(num);
        }
        
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        return q;
    }
};