class Solution {
  public:

    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& ans) {
      ans.push_back(node);
      visited[node] = true;

      for(auto i: adj[node]) {
        if(!visited[i]) {
          dfs(i, adj, visited, ans);
        }
      }

    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vector<int> ans;
      vector<bool> visited(V, false);
      dfs(0, adj, visited, ans);
      return ans;    
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;

        ans.push_back(0);
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
          int node = q.front();
          q.pop();

          for(auto i: adj[node]) {
            if(!visited[i]) {
              visited[i] = true;
              ans.push_back(i);
              q.push(i);
            }
          }

        }

        return ans;
    }
};
