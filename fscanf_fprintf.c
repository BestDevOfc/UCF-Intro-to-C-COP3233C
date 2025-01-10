#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

const unsigned int MAX_BUFFER = 500;

int main(){

    FILE* ifstream = fopen( "in.txt", "r" );
    // remember out -> LEAVING out program and going into a file. This comes in handy for C++.
    FILE* ofstream = fopen( "out.txt", "w" );

    // ensure the file streams have opened up properly:
    if( ifstream == NULL ){
        fprintf( stderr, "[ Failed to open the \'in.txt\' file!\n ]" );
        return 2;
    }

    if( ofstream == NULL ){
        fprintf( stderr, "[ Failed to create the \'out.txt\' file for saving the results ! ]\n" );
        return 2;
    }

    // so we don't have to keep on re-initializing our variables in the For loop:
    int num_students = 0;
    int student_ID = 0;
    char student_name[ MAX_BUFFER ];
    int grades[3] = {0, 0, 0};
    float average = 0.0;

    fscanf( ifstream, "%d", &num_students );
    printf("[ Number of students in the records ]: %d\n", num_students);
    while( !feof(ifstream) ){
        fscanf( ifstream, "%d %s %d %d %d", &student_ID, student_name, &grades[0], &grades[1], &grades[2] );

        average = (float)( grades[0] + grades[1] + grades[2] ) / 3.0;

        // to save the data into the file, could just run the program with a redirection operator "> out.txt", but better to learn
        // basic C File IOs.
        fprintf(  ofstream, " ====================== \n" \
                " [+] - StudentID: %d \n" \
                " [+] - StudentName: %s \n" \
                " [+] - Scores: %d, %d, %d \n" \
                " [+] - Average: %.2f \n" \
                " ====================== \n ",

                student_ID, student_name, grades[0], grades[1], grades[2], average
        );

        printf(  " ====================== \n" \
                " [+] - StudentID: %d \n" \
                " [+] - StudentName: %s \n" \
                " [+] - Scores: %d, %d, %d \n" \
                " [+] - Average: %.2f \n" \
                " ====================== \n ",

                student_ID, student_name, grades[0], grades[1], grades[2], average
        );

    }

    printf("\n");

    // close and clean up the buffer for the file pointers.
    if( fclose( ifstream ) != 0 ){
        fprintf( stderr, "[ Failed to successfully close the \'in.txt\' input filestream! ]\n" );
    }

    if( fclose(ofstream) != 0 ){
        fprintf( stderr, "[ Failed to close the output file! Data MAY not be written if fclose() does not successfully return! ]\n" );
        // a bigger deal since the buffer will not close properly and the output MAY not show up.
        return 2;
    }


    return 0;
}

