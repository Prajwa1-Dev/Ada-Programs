#include <stdio.h>

int n, m, w[10], p[10];

int max(int a, int b) { return (a > b ? a : b); }

void knapsack_DP() {
    int V[10][10];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (w[i] > j)
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], p[i] + V[i - 1][j - w[i]]);
        }
    }

    // Print DP table (optional)
    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            printf("%d ", V[i][j]);
        printf("\n");
    }

    // Traceback to find selected items
    printf("Items included: ");
    int i = n, j = m;
    while (i > 0) {
        if (V[i][j] != V[i - 1][j]) {
            printf("%d ", i);
            j -= w[i];
        }
        i--;
    }

    printf("\nMaximum Profit: %d\n", V[n][m]);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    printf("Enter profits: ");
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    knapsack_DP();
    return 0;
}
