class Solution {
public:

    bool isSafe(int node,
                int color,
                vector<int>& colors,
                vector<int> adj[]) {

        for(auto neighbour : adj[node]) {

            if(colors[neighbour] == color)
                return false;
        }

        return true;
    }

    bool solve(int node,
               vector<int>& colors,
               int m,
               int n,
               vector<int> adj[]) {

        if(node == n)
            return true;

        for(int color = 1;
            color <= m;
            color++) {

            if(isSafe(node,
                      color,
                      colors,
                      adj)) {

                colors[node] = color;

                if(solve(node + 1,
                         colors,
                         m,
                         n,
                         adj))
                    return true;

                colors[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges,
                       int m,
                       int n) {

        vector<int> adj[n];

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, 0);

        return solve(0,
                     colors,
                     m,
                     n,
                     adj);
    }
};
