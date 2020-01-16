#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int low, int m, int high) {
    int i, j, aux;

    i = low;
    j = m+1;

    aux = 0;
    int aux_len = high-low+1;
    int* arr_aux = malloc(sizeof(int)*aux_len);
    while (i <= m && j <= high) {
        if (array[i] <= array[j]) {
            arr_aux[aux] = array[i];
            i++;
        }
        else {
            arr_aux[aux] = array[j];
            j++;
        }
        aux++;
    }
    while (i <= m) {
        arr_aux[aux] = array[i];
        aux++;
        i++;
    }
    while (j <= high) {
        arr_aux[aux] = array[j];
        aux++;
        j++;
    }

    i = low;
    aux = 0;
    while(i <= high) {
        array[i] = arr_aux[aux];
        i++;
        aux++;   
    }
    free(arr_aux);
}


void merge_sort(int* array, int low, int high) {

    if (low < high) {

        int m = low + (high - low) / 2;

        merge_sort(array, low, m);
        merge_sort(array,m+1, high);

        merge(array, low, m, high);
    }
}

