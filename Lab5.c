// insertion sort using ONLY pointers:

#include <stdio.h>
#include <stdlib.h>

int main(){

    float* arr = (float*)malloc( 5 * sizeof(float) );
    arr[0] = 12.5;
    arr[1] = 1.3;
    arr[2] = 13.6;
    arr[3] = 7.5;
    arr[4] = 6;

    float* key = (float*)malloc( sizeof(float) );

    int* n = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));
    int* j = (int*)malloc(sizeof(int));

    *n = 5;
    *i = 0;
    *j = 0;
    
    printf("_________________________\n");
    printf("BEFORE SORTING: \n");
    for(; *i < *n; ++(*i))
        printf("%.2f\t", arr[*i]);
    printf("\n_________________________\n");

    for(*i = 1; *i < *n; ++(*i)){
        *key = arr[*i];
        *j = *i - 1;
        while( *j >= 0 && arr[*j] > *key ){
            arr[*j + 1] = arr[*j];
            *j -= 1;
        }
        arr[*j + 1] = *key;
    }

    printf("AFTER SORTED: \n");
    for(*i = 0; *i < *n; ++(*i)){
        printf("%.2f\t", arr[*i]);
    }

    // don't want no memory leaks here:
    free(arr);
    free(n);
    free(i);
    free(j);
    
    return 0;
}
