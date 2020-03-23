ASSEMBLY AND C ALGORITHMS COMPARISON




DESCRIPTION:
  This is a small program that calculates the runtime of sorting algorithms, implemented both in C and Assemblyx64 code.




HOW TO COMPILE AND RUN: 
  
   $ as insertion_sort.s -o insertion_sort.o
   $ as merge_sort.s -o merge_sort.o
   $ gcc -O main.c merge_sort.c insertion_sort.c insertion_sort.o merge_sort.o -o main
   $ ./main


NOTE:
 you can compile it without the optimization flag, ( -o ) in order to see the real difference between C code and Assemblyx86
