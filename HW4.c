#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Sortfolder/arr_handler.h"

int main(void) {
    short flag = 0;
    printf("If you want to run benchmark, enter 1\nIf you want to sort a single array, enter 2\n");
    scanf("%hd", &flag);

    if (flag == 1)
        benchmark();
    else if (flag == 2)
        single_array();

    return 0;
}
