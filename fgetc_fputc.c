#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

const unsigned int MAX_BUFFER = 500;

int main(){

    FILE* ofstream = fopen( "out.txt", "w" );
    FILE* ifstream = fopen( "test.txt", "r" );

    char ch = ' ';

    // in -> data is going INto our program
    // we do !feof but we could just do while(1) and inside do if(ch == EOF) break;
    while( !feof( ifstream ) ){
        ch = fgetc( ifstream );
        if( ch != EOF ){
            printf("%c", ch);
            fputc( ch, ofstream );
        }
        
        // fputc( ch, ofstream );
    }

    // close the file pointers, and clear out buffer to prevent memory leaks
    if( fclose( ofstream )!= 0 || fclose( ifstream ) != 0 ){
        printf("[ Failed to close the ofstream/ifstream! ]\n");
        return 2;
    }

    printf("\n");
    return 0;
}

