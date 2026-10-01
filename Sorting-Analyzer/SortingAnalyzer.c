#include <stdio.h>

void copyArray(int source[], int destination[], int size){
    for(int i = 0; i < size; i++){
        destination[i] = source[i];

    }
}

void bubbleSort(int arr[], int size, int *comparisons, int *swaps){
    for(int i = 0; i < size - 1; i++){
        int swapped = 0;

        for(int j = 0; j < size - 1 -i; j++){
            (*comparisons)++;
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
                swapped = 1;
            }
        }

        if(swapped == 0){
            break;
        }
    }
}

void selectionSort(int arr[], int size, int *comparisons, int *swaps){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < size; j++){
            (*comparisons)++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            (*swaps)++;
        }
    }
}

void insertionSort(int arr[], int size, int *comparisons, int *shifts){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0){
            (*comparisons)++;

            if(arr[j] > key){
                arr[j + 1] = arr[j];
                (*shifts)++;
                j--;
            }
            else{
                break;
            }
        }

        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;

    printf("Original Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int bubble[5];
    int selection[5];
    int insertion[5];

    copyArray(arr, bubble, size);
    int comparisons = 0;
    int swaps = 0;

    bubbleSort(bubble, size, &comparisons, &swaps);

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);
    printf("Bubble Sorted: ");
    for(int i = 0; i < size; i++){
        printf("%d ", bubble[i]);
    }
    printf("\n\n");

    copyArray(arr, selection, size);
    comparisons = 0;
    swaps = 0;

    selectionSort(selection, size, &comparisons, &swaps);

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);
    printf("Selection Sorted: ");
    for(int i = 0; i < size; i++){
        printf("%d ", selection[i]);
    }
    printf("\n\n");

    copyArray(arr, insertion, size);
    comparisons = 0;
    int shifts = 0;

    insertionSort(insertion, size, &comparisons, &shifts);

    printf("Comparisons: %d\n", comparisons);
    printf("Shifts: %d\n", shifts);
    printf("Insertion Sorted: ");
    for(int i = 0; i < size; i++){
        printf("%d ", insertion[i]);
    }
    printf("\n\n");

    return 0;
}
