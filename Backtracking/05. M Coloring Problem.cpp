class Solution{
public:

    bool isSafe(int color, int node, vector<int>& colors, vector<int> adj[]) {
        
        for(auto i: adj[node]) {
            if(colors[i] == color) return false;
        }

        return true;
    }

    bool solve(int node, int m, int n, vector<int>& colors, vector<int> adj[]) {
        if(node == n) return true;

        for(int i = 1; i <= m; i++) {
            if(isSafe(i, node, colors, adj)) {
                colors[node] = i;
                if(solve(node + 1, m, n, colors, adj)) return true;
                colors[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//your code goes here

        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> colors(n, 0);

        return solve(0, m, n, colors, adj);
    }
};