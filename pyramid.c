#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
 

int main(){
    int rows = 4;
    char symbol = '*';
    
    // keeps track of the number of symols to print, every row just adds 2 to this
    int num_print = 1;
    
    for( int i = 0; i < rows; i++ ){
        printf("\n");
        // print the spaces
        for( int j = 0; j < rows-(i+1); j++ ){
            printf(" ");
        }
        // print the symbol
        for( int k = 0; k < num_print; k++ ){
            printf("%c", symbol);
        }
        num_print += 2;

    }
    printf("\n");
    return 0;
}




/*

Rows: 4
Left Symbols = rows-(i+1)
symbols = i+3


   *   
  ***  
 ***** 
*******

*/
