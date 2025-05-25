#include <stdio.h>

#define MAX 10

// Function to compute the transitive closure using Warshall's Algorithm
void warshall(int A[MAX][MAX], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    warshall(adj, n);

    printf("Transitive closure of the given graph is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
