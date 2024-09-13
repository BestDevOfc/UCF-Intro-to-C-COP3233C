// unit2.hw
// Muhammad Ali
#include <stdio.h>
#include <stdlib.h>


/*  
    [*] using a structure to keep everthing tidy, otherwise managing all these variables will get messy
*/


int is_valid_score( float score );
int retry_get_score( float* score_ptr, char* var_name );
int get_score( float* score_ptr, char* instruction, char* var_name );
int start_over();
int start_over_check( int score_return_status );
int main();


typedef struct student{
    float hw_avg;
    float project_avg;
    float lab_avg;
    float midterm_one;
    float midterm_two;
    float final;
    float overall_avg;
    char* final_letter_grade;
    char* letter_to_score;
}student;


int calculate_final_avg( student* s ){
    /* Calculates the final average */

    s->overall_avg = (s->hw_avg*.2 + s->project_avg*.2 + s->lab_avg*.05 + (s->midterm_one+s->midterm_two+s->final)*.55/3.0);

    // assign a letter grade to that average score,
    // if conditions are just less messy than switch + nested-ifs
    
    // Creating a custom hashmap (kind of) for mapping scores to their respective letter grades
    int scores[] = {
        94, 90, 87, 84, 80, 77, 74, 70, 67, 64, 61, 0
    };

    const char* letter_grades[] = {
        "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"
    };
    
    int avg = (int)s->overall_avg;
    
    int num_elements = sizeof( scores ) / sizeof( scores[0] );
    
    for( int index=0; index < num_elements; index++){
        if( avg >= scores[index] ){
            s->final_letter_grade = (char*)letter_grades[index];
            break;
        }
    }

    return 0;
}

int is_valid_score( float score ){
    /* Simple way to check if the scor is within the valid range */
    return  score >= 0.0 && score <= 100.0;
}


int retry_get_score( float* score_ptr, char* var_name ){
    /* If you give an invalid score it'll retry 2 more times */

    int score_tries = 0;
    while ( score_tries != 2 ){ // not 3 because the initial try still counts towards the total three
        score_tries += 1; 
        printf("Invalid %s score. Try again: ", var_name);
        scanf("%f", score_ptr);
        if( !is_valid_score( *score_ptr ) ){
            continue;
        }
        
        return 0;
        
    }
    printf("\nI'm sorry...You tried too many times.\n");
    return -1;
}

int get_score( float* score_ptr, char* instruction, char* var_name ){
    /* Reusable way to retrieve scores */
    printf("\n%s", instruction);
    scanf("%f", score_ptr);
    if ( is_valid_score( *score_ptr ) ){
        return 0;
    }
    
    // if the score is invalid we'll ask them 2 more times to enter a valid one.
    return retry_get_score( score_ptr, var_name );

}

int start_over(){
    /* Easy way to start over */
    printf("\nWould you like to start over (Y/N): ");
    int num_printed = 0;
    for(int i=0; i< 3; i++){
        char choice;
        
        scanf(" %c", &choice); // the " " before the "%c" is there to ignore whitespaces + '\n'
                            // if we don't do this the previous printf's '\n' will be taken as input to the scanf function
        
        if( choice == 'y' || choice == 'Y' ){
            return 1;
        }
        else if( choice == 'n' || choice == 'N' ){
            return 0;
        }
        else{
            // they chose an invalid character
            if(num_printed != 2){
                num_printed += 1;
                printf("Invalid character. Try again: ");                
            }

        }
    }
    return -1;
}

int start_over_check( int score_return_status ){
    /*
    
        If a user enters an incorrect score 3 times the status will be = -1, 
        if this is the case we want to ask the user to start over since they have entered an invalid score
        too many times.

    */
    if( score_return_status == -1 ){
        switch( start_over() ){
            case 1: // True
                printf("*************************************\n\n");
                main(); // calling main function again to get all scores.
                break;
            case 0: // False
                printf("\t\t\tGood-bye!\n");
                exit(0);
            default: // 3 tries met, exiting...
                printf("\t\t\tProgram terminated!\n");
                exit(-1);
        }
    }
    return 0;
}


int main() {    
    /*
    
        All function code is tied together here.

    */
    while ( 1 ){
        student student_one;
    
        int score_return_status = 0;
        score_return_status = get_score( &student_one.hw_avg, "Enter the hw average score: ", "Homework Average" );
        // if they failed to enter a proper score we'll ask if they want to restart.
        start_over_check( score_return_status );
        
        score_return_status = get_score( &student_one.project_avg, "Enter the project average score: ", "Project Average" );
        start_over_check( score_return_status );

        score_return_status = get_score( &student_one.lab_avg, "Enter lab average score: ", "Lab Average" );
        start_over_check( score_return_status );
        
        // this is because of the way the inputs will be handled in one go
        // the var name also is included in the error message just like the others ^^^
        
        printf("\nEnter midterm1, midterm2 and the final: ");
        scanf("%f %f %f", &student_one.midterm_one, &student_one.midterm_two, &student_one.final);
        if( !is_valid_score( student_one.midterm_one ) ){
            start_over_check(retry_get_score( &student_one.midterm_one, "midterm1" ));
        }
        if( !is_valid_score( student_one.midterm_two ) ){
            start_over_check(retry_get_score( &student_one.midterm_two, "midterm2" ));
        }
        if( !is_valid_score( student_one.final ) ){
            start_over_check(retry_get_score( &student_one.final, "final" ));
        }

        // calculating the final average
        calculate_final_avg( &student_one );

        // ***PRINT AVERAGES: ***
        printf("\nHere are all your average scores: \n");
        printf("\tHW            : %.2f\n", student_one.hw_avg);
        printf("\tPROJECTS      : %.2f\n", student_one.project_avg);
        printf("\tLABS          : %.2f\n", student_one.lab_avg);
        printf("\tMIDTERM1      : %.2f\n", student_one.midterm_one);
        printf("\tMIDTERM2      : %.2f\n", student_one.midterm_two);
        printf("\tFINAL         : %.2f\n", student_one.final);
        printf("\n------------------------------------\n");
        printf("OVERALL AVERAGE : %.2f\n", student_one.overall_avg);
        printf("(%.2f*.2 + %.2f*.2 + %.2f*.05 + (%.2f+%.2f+%.2f)*.55/3) is %.2f", 
                student_one.hw_avg,
                student_one.project_avg,
                student_one.lab_avg,
                student_one.midterm_one,
                student_one.midterm_two,
                student_one.final,
                student_one.overall_avg);
        printf("\n------------------------------------\n");
        printf("\t\t\tFINAL LETTER GRADE: %s\n", student_one.final_letter_grade);
        
        
        start_over_check(-1);
    }
    return 0;   
}