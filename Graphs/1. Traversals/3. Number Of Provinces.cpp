class Solution
{
public:

    void dfs(int node, vector<int> adjLs[], vector<bool>& visited) {
        visited[node] = true;

        for(auto i: adjLs[node]) {
            if(!visited[i]) {
                dfs(i, adjLs, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj) {
       
        int count = 0;
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> adjLs[V];

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adjLs, visited);
                count++;
            }
        }

        return count;

    }

};
