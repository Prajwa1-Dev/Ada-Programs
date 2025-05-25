#include <stdio.h>

#define MAX 10
#define INF 99999

// Function to find minimum of two values
int min(int a, int b) {
    return (a < b ? a : b);
}

// Floyd-Warshall Algorithm
void floyd(int D[MAX][MAX], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (use 99999 for INF):\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    floyd(cost, n);

    printf("All-Pairs Shortest Path Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}
