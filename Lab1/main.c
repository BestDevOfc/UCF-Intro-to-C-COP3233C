#include <stdio.h>
#include <stdlib.h>

int is_prime(int number){
    /*
    
    The reason this works is because it's checking all the numbers within the range (excluding 1,2, itself) and if 
    it can divide with a zero remainder than it is NOT a prime number.

    A prime number is a number that can only be divided by itself and 1.

    */
    for(int i=2; i<number; i++){
        if( number % i == 0 ){
            return 0; // False
        }
    }
    return 1; // True
}


int start_over_check(){
    // split into a function
    while( 1 ){
        char continue_option;
        printf("Would you like to start again? Y/n");
        scanf(" %c", &continue_option);

        if( continue_option == 'y' || continue_option == 'Y' ){
            return 1;
        }
        else if( continue_option == 'n' || continue_option == 'N' ){
            return 0;
        }
        else{
            printf("Invalid Option\n");
        }
    }
}

void print_prime_numbers(int number){
    // any number less than or equal to 3 has no prime number less than it
    if( number <= 3 ){
        printf("There are no prime numbers that are less than %d!\n", number);
    }
    else{
        printf("Here are the prime numbers that are less than %d:\n", number);
        for(int i=2; i<number; i++){
            if( is_prime(i) == 1 ){
                printf("%d ", i);
            }
            
        }
    }
}

int get_number(){
    int number = 0;
    while ( 1 ){            
        printf("Enter your natural number: ");
        scanf("%d", &number);
        if( number < 0 ){
            printf("This is an invalid natural number\n");
        }
        else{
            break;
        }
        
    }
    return number;
}

int main(){
    while( 1 ){
        // Get the number from the user
        int number = get_number();

        // print all the prime numbers:
        print_prime_numbers(number);

        // see if they want to restart or not.
        int choice = start_over_check();
        if( choice != 1 ){
            break;
        }


    }
    printf("Good-bye! \n");
    return 0;
}