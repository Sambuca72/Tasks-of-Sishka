#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to implement merge sort
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "rb");
    FILE *outputFile = fopen("output.txt", "wb");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int N;
    fread(&N, sizeof(int), 1, inputFile);

    int *A = (int *)malloc(N * sizeof(int));
    fread(A, sizeof(int), N, inputFile);

    fclose(inputFile);

    // Sort the array using merge sort
    mergeSort(A, 0, N - 1);

    // Write the sorted array to the output file
    fwrite(A, sizeof(int), N, outputFile);

    fclose(outputFile);
    free(A);

    return 0;
}
