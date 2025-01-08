#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

const unsigned int MAX_ELEMENTS = 4;

typedef struct bookrec{
    char name[20];
    int price;
} Book;

int main(){
    Book library[ MAX_ELEMENTS ];

    char c = ' ';

    for( int i = 0; i < MAX_ELEMENTS; i++ ){
        printf("[ Ener the name of the book ]: ");
        fgets( library[i].name, sizeof(library[i].name), stdin );
        
        // replacing the first occurence of '\n' with null terminator since fgets gets EVERYTHING
        library[i].name[ strcspn( library[i].name, "\n" ) ] = 0;

        printf("\n[ Enter the price of the book as a whole dollar ]: ");
        int status = scanf("%d", &library[i].price);
        
        // scanf discards the '\n' and throws it into the STDIN buffer, so we need to clean it for the next iteration
        while( (c = getchar()) != '\n' && c != EOF );
        
        if( status != 1 ){
            printf("[ Failed to scan the integer, you may have entered an invalid number! ]\n");
            return 1;
        }
    }

    for( int i = 0; i < MAX_ELEMENTS; i++ ){
        printf("[ Book Name ]: %s\n", library[i].name);
        printf("[ Book Price ]: %d\n", library[i].price);
        printf("\n\n");
    }


    return 0;
}
