#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

const unsigned int MAX_ELEMENTS = 10;

int main(){
    int numbers[ 4 ][ MAX_ELEMENTS ] = {
        { 1, 5, 4, 3, 7, 8, 9, 3, 2, 1 },
        { 9, 8, 7, 4, 5, 4, 3, 2, 1, 66 },
        { 34, 65, 98, 21, 33, 22, 60, 72, 42, 13 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 },
    };
    
    // set an inital value to the first element of the array
    

    for( int row = 0; row < 4; row++ ){
        // current row, first column initial value
        int max_number = numbers[row][0];
        int max_col = 0;
        
        // even though our MAX is 10, we may not have actually 10 elements/columns for every row, 
        // so we calculate it dynamically
        int number_of_cols = sizeof(numbers[row])/sizeof(numbers[row][0]);
        
        for( int col = 0; col < number_of_cols; col++  ){
            // if a new greater value is found, update it
            if( max_number < numbers[row][col] ){
                max_number = numbers[row][col];
                max_col = col;
            }
        }
        // print the number and position of the largest value in this 2D array
        printf("[ For row \'%d\' the largest value is \'%d\' at column \'%d\' ]\n", row, max_number, max_col);

    }

    return 0;
}
