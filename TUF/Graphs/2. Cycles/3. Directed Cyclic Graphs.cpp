class Solution{
public:

    // bool detectCycle(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& dfsVisited) {
    //     visited[node] = true;
    //     dfsVisited[node] = true;

    //     for(auto neighbour: adj[node]) {
    //         if(!visited[neighbour]) {
    //             bool isCycleDetected = detectCycle(neighbour, adj, visited, dfsVisited);
    //             if(isCycleDetected) {
    //                 return true;
    //             }
    //         } else if(dfsVisited[neighbour]) {
    //             return true;
    //         }
    //     }

    //     dfsVisited[node] = false;
    //     return false;
    // }

    bool isCyclic(int N, vector<int> adj[]) {
        // vector<bool> visited(N, false);
        // vector<bool> dfsVisited(N, false);
            
        // for(int i = 0; i < N; i++) {
        //     if(!visited[i]) {
        //         bool ans = detectCycle(i, adj, visited, dfsVisited);
        //         if(ans) {
        //             return true;
        //         }
        //     }
        // }

        vector<int> inDegree(N, 0);

        for(int i = 0; i < N; i++) {
            for(auto j : adj[i]) {
                inDegree[j]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < N; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            count++;

            for(auto neighbour: adj[front]) {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return !(count == N);
    }
};
