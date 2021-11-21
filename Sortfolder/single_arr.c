#include "arr_handler.h"

void sort(int* arr1, int* arr2, int size) {
    FILE *output;
    double time_taken;
    clock_t start, end;
    output = fopen("../result.txt", "w");

    start = clock();
    quick_sort(arr1, 0, (size - 1));
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "quick sort results:\nTime taken: %f\nSorted array:\n", time_taken);
    for (int i = 0; i < size; i++)
        fprintf(output, "%d\n", arr1[i]);
    fprintf(output, "\n\n");

    start = clock();
    counting_sort(arr2, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(output, "counting sort results:\nTime taken: %f\nSorted array:\n", time_taken);
    for (int i = 0; i < size; i++)
        fprintf(output, "%d\n", arr2[i]);

    fclose(output);
}

void txt_input(void) {
    printf("\nEnter the path to your .txt file:\n");
    char* path = (char*)malloc(100 * sizeof(char));
    scanf("%s", path);
    FILE *input;
    input = fopen(path, "r");
    int* array;
    int* array_copy;
    int size;
    
    fscanf(input, "%d\n\n", &size);
    array = (int*)malloc(size * sizeof(int));
    array_copy = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(input, "%d\n", &(array[i]));
        array_copy[i] = array[i];
    }

    fclose(input);
    sort(array, array_copy, size);
}

void random_array() {
    printf("Enter the size of array to be generated:\n");
    int size;
    scanf("%d", &size);
    int* array;
    int* array_copy = (int*)malloc(size * sizeof(int));

    srand(time(NULL));
    array = arr_gen(size);
    for (int i = 0; i < size; i++) 
        array_copy[i] = array[i];

    sort(array, array_copy, size);
}

void single_array(void) {
    printf("\nIf you want to generate random array enter 1\n");
    printf("If you already have the unsorted array in .txt file enter 2\n");
    short flag;
    scanf("%hd", &flag);

    if (flag == 1) {
        random_array();
    }
    else if (flag == 2) {
        txt_input();
    }
    else {
        printf("Wrong input. Try again.");
        exit(0);
    }
}
