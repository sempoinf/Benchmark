#include "arr_handler.h"

int* arr_gen(int n) {
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}
