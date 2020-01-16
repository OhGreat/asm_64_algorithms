#define ARRAY_LEN 10000
#define NAME_PRINT_LEN 30

//sorting algorithms
void insertion_sort_array(int* array, int len);
int* insertion_sort(int* array, int len, int cell_size);

void quick_sort(int* array, int len, int low, int high);

void merge_sort(int* array, int low, int high);
void merge_sort_asm(int* array, int low, int high);

//helper functions
int* create_array(int array_size, int min_rand_val, int max_rand_val);
void check_results(char* algorithm, int* array, int len, float milli);
int check_if_sorted(int* array, int len);