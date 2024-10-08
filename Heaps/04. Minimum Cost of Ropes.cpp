class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i: arr) {
            pq.push(i);
        }
        
        long long cost = 0;
        while(pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            cost = cost + first + second;
            pq.push(first + second);
        }
        
        return cost;
    }
};