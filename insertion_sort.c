#include <stdio.h>

void insertion_sort_array(int* array, int len) {
  int i = 0;
  int aux2;
  while(i < len -1) {
    int aux = i;
    int k = i+1;
    while(aux >= 0 && k < len && array[k] < array[aux]) {
      aux2 = array[k];
      array[k] = array[aux];
      array[aux] = aux2;
      k--;
      aux--;
    }
    i++;
  }
}