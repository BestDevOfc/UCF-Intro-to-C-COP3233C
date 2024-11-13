
/*
    Muhammad Ali
    Ardian Peach
    Kevin Bernichio
    Gabe Edwards
*/
//----------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CREDIT_HRS_RATE 236.45
#define ADMINISTRATIVE_FEE 52
#define GPA_DISCOUNT_MIN 3.85
#define MAX_STUDENTS_MEMBERS 100
#define MAX_FACULTY_MEMBERS 30
#define UPPER_OFFSET ('a' - 'A') 
#define MAX_USER_INPUT 50
// Should be 32 ^^^



//---------------------------
// Constants:
const char *deptNames[] = {"MATH", "CS", "SCIENCE"};
const char *rankNames[] = {"PROFESSOR", "ADJUNCT"};

//---------------------------
// Structures here:

typedef struct faculty_member{
    // NOTE: had a bug where we were trying to push data into a char* null pointer, be careful y'all!!!
    char full_name[MAX_USER_INPUT+1];
    char ID[MAX_USER_INPUT+1];
    char department[MAX_USER_INPUT+1]; // math, cs or science are the only departments we are considering in this project
    char rank[MAX_USER_INPUT+1];     // professor and adjunct are the only ranks we are considering in this project
}faculty;

typedef struct student_member{
    char full_name[MAX_USER_INPUT+1];
    char ID[MAX_USER_INPUT+1];
    float GPA;
    int num_credit_hrs;
}student;

//---------------------------
// Function protoypes here:
int menu ();
int attempt_exit();
char* normalize_input(char* input);
char* uppercase_str(char* input);
int is_letter(char input);
int is_upper(char input);
int add_faculty( faculty faculty_list[], int index );
void clear_buffer();
void get_input(char *str, int size);
//---------------------------

// Function definitions here:
int main() { 
    student students_list[ MAX_STUDENTS_MEMBERS ];
    faculty faculty_list[ MAX_FACULTY_MEMBERS ];

    int faculty_index = 0;
    int student_index = 0;

    int option = menu();
    switch( option ){
        case 1:
            add_faculty( faculty_list, faculty_index );
            faculty_index += 1;
            break;
        default:
            // not possible bcs menu() checks for us.
            menu();
            break;
            

    }

    printf("First faculty name: %s\n", faculty_list[0].full_name);

    return 0; 
  }

 //---------------------------

int is_valid_rank( char* rank ){
    char* upper_rank = normalize_input( rank );
    for( int i = 0; i < sizeof( rankNames ) / sizeof( rankNames[0] ); i++ ){
        if( strcmp( rankNames[i], upper_rank ) == 0 ){
            return 1;
        }
    }
    return 0;
}

int get_rank( faculty* member ){
    for( int i = 0; i < 3; i++ ){

        printf("\nRank: ");
        get_input(member->rank, MAX_USER_INPUT);
        

        if( is_valid_rank(member->rank) != 1 ){
            printf("Sorry entered rank (%s) is invalid. Try again.\n", member->rank);
        }
        else{
            return 1;
        }

    }
    // took them three attempts, exit.
    return attempt_exit();
    
    
}

int add_faculty( faculty faculty_list[], int index ){
    faculty member;

    printf("Enter the faculty’s info:\n"    \
            "\t Name of the faculty: "    
    );
    
    get_input(member.full_name, MAX_USER_INPUT);

    printf("\nID: ");
    get_input(member.ID, MAX_USER_INPUT);

    get_rank( &member );

    faculty_list[index] = member;
    
    return 0;
}

int is_upper(char input){
    return (input >= 'A' && input <= 'Z');
    
}
int is_letter(char input){
    return ((input >= 'A' && input <= 'a') || (input >= 'a' && input <= 'z'));
}
char* uppercase_str(char* input){
    // +1 for the stupid null terminator
    // NOTE: don't forget to free to prevent memory leaks !!!
    char* uppercased_input = (char*)malloc( strlen(input) + 1 );

    strcpy( uppercased_input, input );

    if( uppercased_input == NULL ){
        printf("[ Failed to allocate memory for C program - Please Check your Computer's TaskMGR! ]");
        exit(-1);
    }

    for(int i = 0; i < strlen(input); i++){
        // printf("%c\n", input[i]);
        // is NOT a letter, don't perform anything on it
        if( is_letter(input[i]) == 0 ){
            // printf("// is NOT a letter, don't perform anything on it\n");
            uppercased_input[i] = input[i];
        }
        else if( is_upper(input[i]) == 1 ){ // already uppercased
            // printf("// already uppercased\n");
            uppercased_input[i] = input[i];
        }
        else{ // is lowercased letter, time to convert to uppercase:
            // using ASCII digit logic.
            // printf("// is lowercased letter, time to convert to uppercase:\n");
            uppercased_input[i] = input[i] - UPPER_OFFSET;
        }
        
    }
    return uppercased_input;
}
char* normalize_input(char* input){
    // takes in user input or data and normalizes them ( in this case: just uppercases them )
    return uppercase_str(input);
}
void clear_buffer(){
    int character = 0;
    while( character != '\n' && character != EOF ){
        character = getchar();
    }
}

int attempt_exit(){
    printf("You have tried too many times…\n" \
		"Thank you for using PerPro. Goodbye!\n");
    exit(-1);
}
int menu (){
	for(int i=0; i<3; i++){
        int  option;

        printf("Choose one of the options:\n" \
                    "\t1. Add a new faculty member\n"  \
                    "\t2. Add a new student\n"  \
                    "\t3. Print tuition invoice for a student\n"  \
                    "\t4. Print information of a faculty\n"  \
                    "\t5. Exit Program \n" 
            );
        printf("Enter your selection: \n");
        scanf("%d", &option);
        // get rid of the null terminator from scanf from before as it is still in the memory STDIN buffer.
        // getc(stdin);
        clear_buffer();

        if( option >= 1 && option <= 5 ){
            return option;
        }
        else{
            printf("Sorry entered selection %d is invalid. Try again.", option);
        }
        
    }

    return 0;

}


void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void get_input(char *str, int size) {
    // helper function to remove the trailing newline character.
    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0'; // Remove the newline if present
    }
}
