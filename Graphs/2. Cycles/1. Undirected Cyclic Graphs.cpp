class Solution{
public:

    // bool detectCycle(int node, vector<bool>& visited, vector<int> adj[]) {

    //     vector<int> parent(visited.size(), -1);

    //     queue<int> q;
    //     q.push(node);

    //     while(!q.empty()) {
    //         int front = q.front();
    //         q.pop();

    //         visited[front] = true;

    //         for(auto i: adj[front]) {
    //             if(visited[i] && i != parent[front]) {
    //                 return true;
    //             } else if(!visited[i]) {
    //                 q.push(i);
    //                 parent[i] = front;
    //             }
    //         }
    //     }

    //     return false;

    // }

    bool detectCycle(int node, int parent, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;
        for(auto neighbour: adj[node]) {
            if(!visited[neighbour]) {
                bool isCycleDetected = detectCycle(neighbour, node, visited, adj);
                if(isCycleDetected) {
                    return true;
                }
            } else if(neighbour != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool ans = detectCycle(i, -1, visited, adj);
                if(ans) {
                    return true;
                }
            }
        }    

        return false;
    }
};