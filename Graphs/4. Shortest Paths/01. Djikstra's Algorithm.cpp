class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> distance(V, 1e9);

        st.insert(make_pair(0, S));
        distance[S] = 0;

        while(!st.empty()) {
            int dist = st.begin()->first;
            int node = st.begin()->second;

            st.erase(st.begin());

            for(auto i: adj[node]) {
                int adjNode = i[0];
                int adjDist = i[1];

                if(dist + adjDist < distance[adjNode]) {

                    if(st.find(make_pair(distance[adjNode], adjNode)) != st.end()) {
                        st.erase(make_pair(distance[adjNode], adjNode));
                    }

                    distance[adjNode] = dist + adjDist;
                    st.insert(make_pair(distance[adjNode], adjNode));
                }
            }
        }
        return distance;
    }
};