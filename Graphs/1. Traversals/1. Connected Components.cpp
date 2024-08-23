class Solution {
  public:

    void bfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& visited) {

      queue<int> q;
      q.push(node);

      while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        visited[frontNode] = true;

        for(auto i: adj[frontNode]) {
          if(!visited[i]) {
            q.push(i);
          }
        }

      }
    }

    int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) {
      
      unordered_map<int, list<int>> adj;

      for(int i = 0; i < E; i++) {
          adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
      }

      vector<bool> visited(V, false);
      int count = 0;

      for(int i = 0; i < V; i++) {
        if(!visited[i]) {
          count++;
          bfs(i, adj, visited);
        }
      }

      return count;
    
    }
};