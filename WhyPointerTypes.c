#include <stdio.h>
#include <stdlib.h>

int main(){
    char* test = "jhi";
    printf("Size of a char pointer --> %lu\n", sizeof(test));
    // they will be stored sequentially
    printf("Address of test[0] --> %p\n", &test[0]);
    printf("Address of test[1] --> %p\n", &test[1]);

    // will be the same size, but the reason it needs to know is because data is stored differently!
    // for example, integer can be stored wherever (in stack since it's statically allocated by compiler)
    // buttt, the test is also stored in the stack but stored sequentially because that's how the data type is stored.
    int* a = NULL;
    printf("Size of a int pointer --> %lu\n", sizeof(a));

    return 0;
}
