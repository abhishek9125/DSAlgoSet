class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       
        vector<int> keys(V, 1e9);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        keys[0] = 0;

        for(int i = 0; i < V; i++) {
            int mini = 1e9;
            int u;

            for(int j = 0; j < V; j++) {
                if(visited[j] == false && keys[j] < mini) {
                    mini = keys[j];
                    u = j;
                }
            }
            
            visited[u] = true;

            for(auto it: adj[u]) {
                int node = it[0];
                int weight = it[1];

                if(visited[node] == false && weight < keys[node]) {
                    parent[node] = u;
                    keys[node] = weight;
                }
            }
        }

        int sum = 0;
        for(auto i : keys) {
            sum += i;
        }

        return sum;
    }
};
