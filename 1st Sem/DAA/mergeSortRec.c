#include<stdio.h>
#include <stdlib.h>
#include <math.h>

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

    int *b, *c;
    int i, p, q;

    if (n > 1) {
        
        p = n/2;
        q = ceil(n/2);

        b = malloc(p * sizeof(int));
        c = malloc(q * sizeof(int));
        
        for (i = 1; i <= p; i++) {
            b[i] = a[i];
        }
        for (i = q; i < n; i++) {
            c[i - n/2] = a[i];
        }
        mergesort(b, p);
        mergesort(c, q);
        merge(a, b, c, p, q);
        free(b);
        free(c);
    }
}

void main() {

    int a[20], n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    mergesort(a, n);

    printf("\nSorted array:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

}