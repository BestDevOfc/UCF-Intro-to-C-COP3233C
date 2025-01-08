#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
 

int main(){
    int number = 6;
    int result = number;
    
    for( int i = number-1; i > 0; i-- ){
        result = result*i;
        printf("%d * ", i);
    }
    printf("[ Factorial of \'%d\' is %d]\n", number, result);
    return 0;
}

