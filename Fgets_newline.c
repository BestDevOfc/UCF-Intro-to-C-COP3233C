#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

const unsigned int MAX_BUFFER = 100;

int main(){
    // for char we'd need to use dynamic allocation, by default char* strings are IMMUTABLE!
    char name[ MAX_BUFFER ];

    // get input
    printf("[ Enter your name ]: ");
    fgets( name, sizeof(name), stdin );

    // remove the newline, Fgets captures everything in the buffer, even the newlines
    // strcspn returns the number of characters BEFORE the specified characters are found
    // replacing the newline with a null terminator
    name[ strcspn( name, "\n" ) ] = 0;

    printf("Your name is: %s\n", name);

    return 0;
}
