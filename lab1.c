#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], n;

void kruskal() {
    int par[MAX];
    int a, b, u, v;
    int mincost = 0, ne = 0;

    // Initialize parent array
    for (int i = 0; i < n; i++)
        par[i] = -1;

    printf("The minimum spanning tree edges are:\n");

    while (ne < n - 1) {
        int min = INF;
        a = b = -1;

        // Find the minimum cost edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find absolute parent of u and v
        while (par[u] != -1)
            u = par[u];
        while (par[v] != -1)
            v = par[v];

        // If they are in different sets, include this edge
        if (u != v) {
            printf("From vertex %d to vertex %d with cost = %d\n", a, b, min);
            mincost += min;
            par[v] = u;  // Union
            ne++;
        }

        // Mark this edge as used
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Cost of Minimum Spanning Tree = %d\n", mincost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    kruskal();
    return 0;
}
