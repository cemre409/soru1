#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int X[SIZE], arr1[SIZE], arr2[SIZE];
    int i;

    srand(time(NULL));

    // Rastgele sayılar oluştur
    for (i = 0; i < SIZE; i++) {
        X[i] = rand() % 1001; // 0-1000 arası
    }

    // Diziyi kopyala
    for (i = 0; i < SIZE; i++) {
        arr1[i] = X[i];
        arr2[i] = X[i];
    }

    clock_t start, end;
    double time_insertion, time_selection;

    // Insertion Sort zamanı
    start = clock();
    insertionSort(arr1, SIZE);
    end = clock();
    time_insertion = (double)(end - start) / CLOCKS_PER_SEC;

    // Selection Sort zamanı
    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    time_selection = (double)(end - start) / CLOCKS_PER_SEC;

    // Sonuçları yazdır
    printf("Insertion Sort Süresi: %f saniye\n", time_insertion);
    printf("Selection Sort Süresi: %f saniye\n", time_selection);

    return 0;
}