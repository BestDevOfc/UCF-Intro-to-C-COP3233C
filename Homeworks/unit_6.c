// unit6.hw 
// Group members: Muhammad Ali, Ardian Peach, Kevin Bernichio

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


// Prototypes 
char most_occuring_character ( char * str); 
void count_low_up_digit ( char * str, int* lower, int* upper , int *digit); 
char * Up_letters ( char * str); 
int isalphabet(char character);
int is_upper(char letter);
int is_lower(char letter);
char to_upper(char letter);


// Function definitions... 
int is_upper(char letter){
    return letter >= 'A' && letter <= 'Z';
}
int is_lower(char letter){
    return letter >= 'a' && letter <= 'z';
}
char to_upper(char letter){
    return letter - 32;
}
int isalphabet(char character){
    // Check if this character is a letter
    if( (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') ){
        return 1;
    }
    return 0;
}
char most_occuring_character ( char *str ){
    // Your code goes here
    int freq[94] = { 0 };
    for(int i=0; i<strlen(str); i++){
        if( ! (str[i] <= '~' && str[i] >= '!') ){
            continue;
        }

        int index = str[i] - 33;
        freq[index] += 1;
    }

    int init_val = freq[0];
    int all_same = 1;
    int max_val = 0;
    int max_index = 0;
    for(int i=0; i<93; i++){
        if( freq[i] != init_val && (init_val != 0 && freq[i] != 0) ){
            all_same = 0;
        }


        if( freq[i] > max_val ){
            max_val = freq[i];
            max_index = i;
        }
        
    }
    
    if( all_same == 1 ){
        return -1;
    }
    char most_occuring = max_index+33;
    return most_occuring;
}  


void count_low_up_digit ( char *str, int *lower, int *upper , int *digit){ 
    // This function counts how many lower, upper and digit characters. 

    for(int i=0; i<strlen(str); i++){
        if( str[i] >= 65 && str[i] <= 90 ){
            *upper += 1;
        }
        else if( str[i] >= 97 && str[i] <= 122 ){
            *lower += 1;
        }
        else if( str[i] >= 48 && str[i] <= 57 ){
            *digit += 1;
        }
        else{
            continue;
        }
    }
    return;
}


char *Up_letters(char *str) {
    int count_letters = 0;
    
    // First, count the number of letters
    for (int i = 0; i < strlen(str); i++) {
        if ( isalphabet(str[i]) ) {
            count_letters++;
        }
    }

    // Allocate memory for the uppercase letters + null terminator
    char *copy_str = (char *)malloc(count_letters + 1);

    if (copy_str == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }

    // Extract letters + convert to uppercase if need be
    int current_idx = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            copy_str[current_idx] = str[i];
            current_idx++;
        }
        else if( str[i] >= 'a' && str[i] <= 'z' ){
            copy_str[current_idx] = to_upper(str[i]);
            current_idx++;
        }
        else{
            continue;
        }
        
    }
    copy_str[current_idx] = '\0';  // Null-terminate the string

    // Sort the extracted uppercase letters
    for (int i = 0; i < count_letters - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < count_letters; j++) {
            if (copy_str[j] < copy_str[min_idx]) {
                min_idx = j;
            }
        }
        // Swap
        char temp = copy_str[min_idx];
        copy_str[min_idx] = copy_str[i];
        copy_str[i] = temp;
    }

    return copy_str;  // Return the sorted uppercase letters
}

// The following main function is to remain UNCHANGED! 
int main(){        
    char str[50] =""; 
    char *upper_sorted; 
    char most_occur = -1; 
    int lower_case=0 , upper_case=0, digits=0; 

    printf("Enter your string: "); 
    gets(str); 

    most_occur = most_occuring_character ( str ); 
    if ( most_occur == -1 ) printf ("All characters appears once\n"); 
    else printf ("The most occuring character is: %c \n", most_occur); 

    count_low_up_digit ( str, &lower_case, &upper_case , &digits ); 
    printf ("There is/are %d lower case letter(s)\n", lower_case); 
    printf ("There is/are %d upper case letter(s)\n", upper_case); 
    printf ("There is/are %d digit(s)\n", digits); 

    upper_sorted = Up_letters ( str ); 
    printf ("%s\n", upper_sorted); 
    printf ("%s\n", str); 

    // bruh, we can't modify main ;(
    // // avoid memory leaks:
    // if(upper_sorted != NULL){
    //     free(upper_sorted);
    // }

    return 0;
}
