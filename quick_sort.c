#include <stdio.h>

void quick_sort(int* array, int len, int low, int high) {

  if (low < high) {

    int pivot, start_ptr, end_ptr, aux;
    pivot = len/2 + low;
    start_ptr = low;
    end_ptr = high;

    while (start_ptr < end_ptr) {
      //increment pointers
      while(array[start_ptr] <= array[pivot] && start_ptr <= high) {
        start_ptr++;
      }
      while(array[end_ptr] > array[pivot] && end_ptr >= low) {
        end_ptr--;
      }

      
      if (start_ptr < end_ptr) {
        aux = array[start_ptr];
        array[start_ptr] = array[end_ptr];
        array[end_ptr] = aux;
      }

      aux = array[end_ptr];
      array[end_ptr] = array[pivot];
      array[pivot] = aux;

      quick_sort(array, end_ptr-low, low, end_ptr-1);
      quick_sort(array,high-end_ptr, end_ptr+1, high);

    }
  }
}