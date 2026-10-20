
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V = 4;

    int graph[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    vector<bool> visited(V, false);
    int totalCost = 0;

    visited[0] = true;

    cout << "Roads selected for minimum cost:\n";

    for (int count = 0; count < V - 1; count++) {
        int minCost = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minCost) {
                        minCost = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v == -1) {
            cout << "All cities cannot be connected.\n";
            return 0;
        }

        visited[v] = true;
        totalCost += minCost;

        cout << u + 1 << " - " << v + 1
             << " : Cost = " << minCost << '\n';
    }

    cout << "Minimum total construction cost: "
         << totalCost << '\n';

    return 0;
}
