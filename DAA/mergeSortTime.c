#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void merge(int a[], int b[], int c[], int p, int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < p) {
        a[k++] = b[i++];
    }
    while (j < q) {
        a[k++] = c[j++];
    }
}

void mergesort(int a[], int n) {
    if (n > 1) {
        int *b = malloc((n/2) * sizeof(int));
        int *c = malloc(ceil(n/2.0) * sizeof(int));
        int i;
        for (i = 0; i < n/2; i++) {
            b[i] = a[i];
        }
        for (i = n/2; i < n; i++) {
            c[i - n/2] = a[i];
        }
        mergesort(b, n/2);
        mergesort(c, ceil(n/2.0));
        merge(a, b, c, n/2, ceil(n/2.0));
        free(b);
        free(c);
    }
}

void main() {

    clock_t start, end;
    double cpu_time_used;
    int arr[5000];
    int rn = 5000;

    int a[20], n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    mergesort(a, n);
    end = clock();

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Efficiency for the user Input: %f\n", cpu_time_used);

    for (int i = 0; i < rn; i++) {
        arr[i] = rand();
    }
    /*
    for (int i = 0; i < rn; i++) {
        printf(" %d ",arr[i]);
    }
    */

    start = clock();
    mergesort(arr, rn);
    end = clock();

    /*
    printf("\nSorted random Array:");
    for (int i = 0; i < rn; i++) {
        printf(" %d ",arr[i]);
    }
    */
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Average case time efficiency of random input of %d numbers is : %f\n", rn, cpu_time_used);


}