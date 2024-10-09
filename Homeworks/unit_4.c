// Unit 4
// Muhammad Ali
// Ardian Peach 

#include <stdio.h>
#include <stdlib.h>


int main(){
    // creating a block in the heap to hold 10 integers and returning a pointer to that address in heap (dynamic, won't be in stack)
    int* num_elements = (int*)malloc( sizeof(int) );
    *num_elements = 10;

    int* myArray = (int*)malloc( sizeof(int) * 10 );

    myArray[0] = 18;
    myArray[1] = 26;
    myArray[2] = -12;
    myArray[3] = 32;
    myArray[4] = 47;
    myArray[5] = 2;
    myArray[6] = 3;
    myArray[7] = 2;
    myArray[8] = 9;
    myArray[9] = 10;


    ////////////////////////////////////////////////////////////////////
    // Get the maximum value:
    int* max_value = &myArray[0];

    int* i = (int*)malloc( sizeof(int) );
    *i = 0;

    // get the maximum value
    for( *i = 0; *i < *num_elements; (*i)++ ){
        // determining maximum value
        if( myArray[ *i ] > *max_value ){
            max_value = &myArray[ *i ];
        }
    }
    printf("1) Largest value = %d\n", *max_value);
    ////////////////////////////////////////////////////////////////////
    // Get the average value as a float:

    float* sum = (float*)malloc( sizeof(float) );
    *i = 0;
    for( *i = 0; *i < *num_elements; (*i)++ ){
        // calculating total sum to get the average value
        *sum += (float)myArray[ *i ];
    }
    
    float* avg_value = (float*)malloc( sizeof(float) );
    *avg_value = (*sum) / (float)*num_elements;
    
    printf("2) Average value as a float = %.2f\n", *avg_value);


    ////////////////////////////////////////////////////////////////////
    // Check for duplicates:
    int* has_dupes = (int*)malloc( sizeof(int) );
    int* j = (int*)malloc( sizeof(int) );
    
    *has_dupes = 0;
    *i = 0;
    *j = 0;

    for(*i = 0; *i < *num_elements; (*i)++){
        for( *j = *(i)+1; *j < *num_elements; (*j)++ ){
            // printf("does %d == %d ? \n", myArray[i], myArray[j]);
            if( myArray[ *i ]  == myArray[ *j ] ){
                *has_dupes = 1;
                break; // no need to keep checking, we got our answer.
            }
        }
    }


    if( *has_dupes ) printf("3) The array has duplicates. \n");
    else printf("3) The array does not have duplicates. \n");

    ////////////////////////////////////////////////////////////////////

    
    ////////////////////////////////////////////////////////////////////
    // Clean up! - don't want memory leaks    
    free(num_elements);
    free(myArray);
    free(i);
    free(sum);
    free(avg_value);
    free(has_dupes);
    free(j);
    ////////////////////////////////////////////////////////////////////

    return 0;
}