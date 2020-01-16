#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"



int main() {

  clock_t start, stop;

  printf("--------------------------------------------------------------------------------\n");
  printf("          Algorithm           |  SORTED?  |       TIME       |   n. of ITEMS    \n");
  printf("--------------------------------------------------------------------------------\n");
  
  //insertion sort (C)
  int* array = create_array(ARRAY_LEN, 0, 300);
  start = clock();
  insertion_sort_array(array, ARRAY_LEN);
  stop = clock();
  check_results("Insertion sort (C)", array, ARRAY_LEN, stop-start);
  free(array);
  printf("--------------------------------------------------------------------------------\n");

  //insertion sort (ASMx64)
  array = create_array(ARRAY_LEN, 0, 300);
  start = clock();
  int* x = insertion_sort(array, sizeof(int)*ARRAY_LEN, 4);
  stop = clock();
  check_results("Insertion sort (ASMx64)", array, ARRAY_LEN, stop-start);
  free(array);
  printf("--------------------------------------------------------------------------------\n");


/*
  //Quick sort (C) THIS IS NOT WORKING PROPERLY

  array = create_array(50, 0, 300);
  start = clock();
  quick_sort(array, 19, 0, ARRAY_LEN-1);
  stop = clock();
  check_results("Quick sort (C)", array, ARRAY_LEN, stop-start);
*/


  //Merge sort (C)
  array = create_array(ARRAY_LEN, 0, 300);
  start = clock();
  merge_sort(array,0,ARRAY_LEN-1);
  stop = clock();
  check_results("Mege sort (C)", array, ARRAY_LEN, stop-start);
  free(array);
  printf("--------------------------------------------------------------------------------\n");

  // Merge sort (ASMX64)
  array = create_array(ARRAY_LEN, 0, 300);
  start = clock();
  merge_sort_asm(array, 0, ARRAY_LEN-1);
  stop = clock();
  check_results("Merge sort (ASMx64)", array, ARRAY_LEN, stop-start);
  free(array);
  printf("--------------------------------------------------------------------------------\n");

  return 0;
}






//HELPER FUNCTIONS


//creates a test array
int* create_array(int array_size, int min_rand_val, int max_rand_val) {
  //srand(time(0));
  int* array = malloc(sizeof(int)*array_size);
  for (int i = 0; i < array_size; i++) {
    array[i] = (rand() % (max_rand_val - min_rand_val + 1)) + min_rand_val;
  }
  return array;
}



//print results on screen
void check_results(char* algorithm, int* array, int array_len, float milli) {
  
  int sorted = check_if_sorted(array, array_len);

  //aux string to align algorithm name in printf
  int aux_len = NAME_PRINT_LEN - strlen(algorithm);
  char aux[aux_len];
  memset(aux, ' ', aux_len-1);
  aux[aux_len-1] = '\0';
  
  if (sorted)
    printf("%s%s |  SUCCESS  |  %3.8f sec  |   %d items\n", algorithm, aux, milli/CLOCKS_PER_SEC, array_len);
  else
     printf("%s%s |  FAILURE  |  %8.1f sec  |   %d items\n", algorithm, aux, milli/CLOCKS_PER_SEC, array_len);
}



//return 1 if array is sorted, 0 otherwise
int check_if_sorted(int* array, int len) {
  int i,k, sorted =1;
  for (i=0; i<len-1;i++) {
    k=i+1;
    if (array[i] > array[k])
      sorted = 0;
  }
  return sorted;
}
