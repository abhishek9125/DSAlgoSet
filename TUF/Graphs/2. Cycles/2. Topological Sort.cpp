class Solution{
public:

    void topologicalSort(int node, vector<int> adj[], vector<bool>& visited, stack<int>& s) {
        visited[node] = true;

        for(auto neighbour: adj[node]) {
            if(!visited[neighbour]) {
                topologicalSort(neighbour, adj, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans;
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto j: adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto neighbour: adj[frontNode]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // vector<bool> visited(V, false);
        // stack<int> s;

        // for(int i = 0; i < V; i++) {
        //     if(!visited[i]) {
        //         topologicalSort(i, adj, visited, s);
        //     }
        // }

        // while(!s.empty()) {
        //     ans.push_back(s.top());
        //     s.pop();
        // }

        return ans;    
    }
};
