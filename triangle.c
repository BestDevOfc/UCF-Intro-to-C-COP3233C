#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
 

int main(){
    int rows = 4;
    char symbol = '*';
    char medium_symbol = ' ';


    for( int i = 1; i <= rows; i++ ){
        // we're printing top to bottom, so we're subtracting the number of rows we have left by the total number of rows
        // to know how many symbols to print left to right.
        for( int j = 0; j < rows-(rows-i); j++ ){
            printf("%c", symbol);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
