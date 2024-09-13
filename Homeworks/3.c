// unit3.hw
// Muhammad Ali
#include <stdio.h>
#include <stdlib.h>

/*
Write a C program that declares an array of 10 INTs.
Assign any values to the 10 elements of the array.  Your code is supposed to print the following information:

1) Largest value
2) Average value as a float
3) Whether the array has duplicates or not 

1) Largest value = 47
2) Average value as a float = 13.70
3) The array has duplicates. 

*/

float get_average( int arr[], int num_elements ){
    float sum = 0.0;
    for( int i = 0; i < num_elements; i++ ){
        // calculating total sum to get the average value
        sum += (float)arr[i];
    }
    
    return (sum) / (float)num_elements;
}

int get_max( int arr[], int num_elements ){
    int max_val = 0;
    
    max_val = arr[0];

    for( int i = 0; i < num_elements; i++ ){
        // determining maximum value
        if( arr[i] > max_val ){
            max_val = arr[i];
        }
    }

    return max_val;
}

int has_duplicates( int arr[], int num_elements ){
    // determining whether there are duplicates or not
    int has_dupes = 0;
    for(int i = 0; i < num_elements; i++){
        for( int j = i+1; j < num_elements; j++ ){
            // printf("does %d == %d ? \n", myArray[i], myArray[j]);
            if( arr[i]  == arr[j] ){
                has_dupes = 1;
                break; // no need to keep checking, we got our answer.
            }
        }
    }
    return has_dupes;
}

int main(){
    int myArray[10] = {
        18, 26, -12, 32, 47, 2, 3, 2, 9, 10
    };
    int num_elements = sizeof(myArray) / sizeof(myArray[0]);

    int max_val = get_max( myArray, num_elements );
    float average = get_average( myArray, num_elements );
    int have_duplicates = has_duplicates( myArray, num_elements );
    


    printf("1) Largest value = %d\n", max_val);
    printf("2) Average value as a float = %.2f\n", average);
    
    if( have_duplicates ) printf("3) The array has duplicates. \n");
    else printf("3) The array does not have duplicates. \n");
    

    return 0;
}