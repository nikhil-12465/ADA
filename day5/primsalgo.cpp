#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

void primsMST(vector<vector<int>> &cost, int n) {
    vector<int> near(n, INF); // To track nearest vertex
    vector<vector<int>> t(n - 1, vector<int>(2)); // MST edges
    int minCost = 0;

    // Step 1: Find the first minimum edge
    int k = 0, l = 0, min = INF;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    
    t[0][0] = k;
    t[0][1] = l;
    minCost += cost[k][l];

    // Step 2: Initialize near array
    for (int i = 0; i < n; i++) {
        if (cost[i][k] < cost[i][l]) {
            near[i] = k;
        } else {
            near[i] = l;
        }
    }
    near[k] = near[l] = -1; // Mark as included in MST

    // Step 3: Repeat for remaining n-2 edges
    for (int i = 1; i < n - 1; i++) {
        int u = -1;
        min = INF;

        // Find the nearest vertex not in MST
        for (int j = 0; j < n; j++) {
            if (near[j] != -1 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                u = j;
            }
        }

        t[i][0] = u;
        t[i][1] = near[u];
        minCost += cost[u][near[u]];
        near[u] = -1; // Mark as included

        // Update near array
        for (int w = 0; w < n; w++) {
            if (near[w] != -1 && cost[w][near[w]] > cost[w][u]) {
                near[w] = u;
            }
        }
    }

    // Print MST
    cout << "Minimum Cost: " << minCost << endl;
    cout << "Edges in MST:\n";
    for (int i = 0; i < n - 1; i++) {
        cout << t[i][0] << " - " << t[i][1] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n, INF));

    cout << "Enter the adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    primsMST(cost, n);

    return 0;
}
