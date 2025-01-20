#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned const int NUM_ELEMENTS = 3;

typedef struct Person{
    int wealth;
    int age;
}Person;

int main(){

    // could just do Person array_of_people[num_elements]; but we want to show 
    // DMA
    // array of addresses to structures
    Person* array_of_people = (Person*)malloc( sizeof(Person)*NUM_ELEMENTS );
    
    srand(time(0));

    for( int i = 0; i < NUM_ELEMENTS; i++ ){
        // going to the address stored at index 'i' and setting the value of the wealth
        // to rand()

        // with a double pointer it would be going to the address stored at index 'i'
        // which is another address that goes to the value of wealth that you can now change
        array_of_people[i].wealth = rand();
        array_of_people[i].age = rand()%10;
        
        printf("Wealth: %d\nAge: %d\n\n", array_of_people[i].wealth, array_of_people[i].age);
    }
    // array_of_people = [addr_ofstruct1, addr_ofstruct2...]
    free( array_of_people );
    array_of_people = NULL;


    // using array of pointers(which store further addresses, this is why it's a double pointer)
    // to structures
    // array_pointers_person = [addr_of_pointer_to_struct1, ...]
    // that's why we do sizeof(Person*), the actual elements being stored are pointers to 
    // structure of type Person
    Person** array_pointers_person = (Person**)malloc( sizeof(Person*) * NUM_ELEMENTS );
    for( int i = 0; i < NUM_ELEMENTS; i++ ){
        /*
        
            Storing Dynamically allocated memory for the structure, where that structure
            is stored in memory is the address which will be stored at the index of 'i'
            in the "array_pointers_person" array.
        
        */
        array_pointers_person[i] = (Person*)malloc( sizeof(Person) );
        array_pointers_person[i]->wealth = rand();
        array_pointers_person[i]->age = rand()%10;

        printf("Wealth: %d\nAge: %d\n\n", array_pointers_person[i]->wealth, array_pointers_person[i]->age);
    }

    // now we'll free the individual memory allocated structures and the memory for the entire array itself
    for( int i = 0; i < NUM_ELEMENTS; i++ ){
        free( array_pointers_person[i] );
    }
    free( array_pointers_person );

    /*
    2d_array = [
        (pointer)addr of first row,           -> [ addr_element1, addr_element2, addr_element3 ],
        (pointer)addr of second row,          -> ...
        ...
    ];
    */

    int num_rows = NUM_ELEMENTS;
    int num_columns = NUM_ELEMENTS;
    Person** two_dimensional = (Person**)malloc( sizeof(Person*)*num_rows );

    for( int i = 0; i < num_rows; i++ ){
        printf("\n\n[ Row: %d ]\n", i);
        two_dimensional[i] = (Person*)malloc( sizeof(Person)*num_columns );
        for( int j = 0; j < num_columns; j++ ){
            two_dimensional[i][j].wealth = rand();
            two_dimensional[i][j].age = rand()%9;
            printf("Wealth: %d\nAge: %d\n", two_dimensional[i][j].wealth, two_dimensional[i][j].age);
        }
    }

    // now free the memory:
    for( int i = 0; i < num_rows; i++ ){
        free(two_dimensional[i]);
    }
    free( two_dimensional );


    // 

    return 0;
}
