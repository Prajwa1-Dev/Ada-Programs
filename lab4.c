#include <stdio.h>
#define INF 999
int cost[10][10], dist[10], n;

void dijkstra(int src) {
    int vis[10] = {0}, min, u;
    for (int i = 0; i < n; i++) dist[i] = cost[src][i];
    dist[src] = 0; vis[src] = 1;

    for (int i = 0; i < n - 1; i++) {
        min = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && dist[j] < min) min = dist[j], u = j;

        vis[u] = 1;
        for (int v = 0; v < n; v++)
            if (!vis[v] && cost[u][v] != INF)
                if (dist[u] + cost[u][v] < dist[v])
                    dist[v] = dist[u] + cost[u][v];
    }
}

int main() {
    int src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use 999 for INF):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(src);

    printf("Shortest distances from %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("To %d: %d\n", i, dist[i]);

    return 0;
}
