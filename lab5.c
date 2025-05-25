#include <stdio.h>
int cost[10][10], n, colsum[10];

void calculateColSum() {
    for (int j = 0; j < n; j++) {
        colsum[j] = 0;
        for (int i = 0; i < n; i++)
            colsum[j] += cost[i][j];
    }
}

void sourceRemoval() {
    int selected[10] = {0};
    printf("Topological Ordering: ");

    for (int count = 0; count < n; count++) {
        calculateColSum();
        int j;
        for (j = 0; j < n; j++)
            if (!selected[j] && colsum[j] == 0)
                break;

        printf("%d ", j);
        selected[j] = 1;

        for (int k = 0; k < n; k++)
            cost[j][k] = 0;  // Remove the selected vertex (j)
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost (adjacency) matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    sourceRemoval();
    return 0;
}
