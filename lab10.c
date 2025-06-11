#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int temp;
    int i = low + 1, j = high;

    while (1) {
        while (i <= high && a[i] <= pivot) {
            i++;
            count++;
        }
        while (j >= low && a[j] > pivot) {
            j--;
            count++;
        }

        count += 2;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else if (i > j) {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        } else {
            return j;
        }
    }
}


void quicksort(int a[], int low, int high) {
    if (low < high) {
        int s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int main() {
    int a[10000], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000; // Keeping values within 0–9999
    }

    printf("\nSorting...\n");

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nNumber of comparisons: %d", count);
    printf("\nTime taken to sort %d arrays is: %.6f seconds\n",n, time_taken);

    return 0;
}
