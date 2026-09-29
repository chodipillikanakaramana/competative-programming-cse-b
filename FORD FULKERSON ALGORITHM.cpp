#include <bits/stdc++.h>
using namespace std;

int V;

int bfs(vector<vector<int>>& residual, int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);

    queue<int> q;
    q.push(source);
    parent[source] = -2;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;

                if (v == sink)
                    return 1;

                q.push(v);
            }
        }
    }

    return 0;
}

int fordFulkerson(vector<vector<int>>& capacity, int source, int sink) {

    vector<vector<int>> residual = capacity;

    vector<int> parent(V);

    int maxFlow = 0;

    while (bfs(residual, source, sink, parent)) {

        // Find minimum residual capacity
        // along the augmenting path
        int pathFlow = INT_MAX;

        int v = sink;

        while (v != source) {
            int u = parent[v];

            pathFlow = min(pathFlow, residual[u][v]);

            v = u;
        }

        // Update residual capacities
        v = sink;

        while (v != source) {
            int u = parent[v];

            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;

            v = u;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int E;

    cin >> V >> E;

    vector<vector<int>> capacity(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        capacity[u][v] += c;
    }

    cout << fordFulkerson(capacity, 0, V - 1);

    return 0;
}
