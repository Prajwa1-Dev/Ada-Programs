#include <stdio.h>
#define INF 999

int cost[10][10], n;

void prim() {
    int visited[10] = {0}, a, b, min, ne = 0, mincost = 0;
    visited[0] = 1;

    while (ne < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++)
            if (visited[i])
                for (int j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i; b = j;
                    }

        visited[b] = 1;
        printf("Edge %d: %d -> %d | Cost: %d\n", ne + 1, a, b, min);
        mincost += min;
        cost[a][b] = cost[b][a] = INF;
        ne++;
    }
    printf("Total MST cost: %d\n", mincost);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    prim();
    return 0;
}
