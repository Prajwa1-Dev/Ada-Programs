#include <stdio.h>

int n, m, p[10], w[10];

void greedy_knapsack() {
    float profit = 0;
    int capacity = m;

    printf("Items included: ");

    while (capacity > 0) {
        float max_ratio = 0;
        int idx = -1;

        // Find item with max price/weight ratio
        for (int i = 0; i < n; i++) {
            if (w[i] != 0 && ((float)p[i] / w[i]) > max_ratio) {
                max_ratio = (float)p[i] / w[i];
                idx = i;
            }
        }

        if (idx == -1) break; // No items left

        if (w[idx] <= capacity) {
            // Include whole item
            printf("%d ", idx);
            capacity -= w[idx];
            profit += p[idx];
            w[idx] = 0;  // Mark item as used
        } else {
            // Include fraction of item
            float fraction = (float)capacity / w[idx];
            printf("%d (%.2f portion)", idx, fraction);
            profit += fraction * p[idx];
            capacity = 0; // Knapsack full
        }
    }

    printf("\nTotal profit = %.2f\n", profit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    printf("Enter prices: ");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    greedy_knapsack();
    return 0;
}
