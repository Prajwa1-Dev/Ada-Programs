#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10000], n, count = 0;

void selection_sort() {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            count++; // Count comparisons
            if (a[j] < a[min])
                min = j;
        }
        // Swap a[i] and a[min]
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n > 10000) {
        printf("Limit exceeded. Maximum allowed: 10000 elements.\n");
        return 1;
    }

    srand(time(0)); // Seed for randomness
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }

    clock_t start = clock();

    selection_sort();

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nNumber of basic operations = %d\n", count);
    printf("Time taken to sort %d elements = %.6f seconds\n", n, time_taken);

    return 0;
}
