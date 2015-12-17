/*Defines*/
#define MAX_GENERATIONS 1000
#define ENOUGH_FITNESS 666
#define AMOUNT_OF_WEEKS 6
#define AMOUNT_OF_DAYS 5
#define AMOUNT_OF_HOURS 8
#define AMOUNT_OF_ROOMS 10

#define SCHEMA_SIZE 80
#define WEEK_SIZE 8
#define DAY_SIZE 5
#define ROOM_SIZE 10
#define EXAM_SIZE 10
#define LINES_TO_READ 200

#define HOURS 8
#define DAYS 5
#define WEEKS 4

#define SIZE_OF_NAMES 200
#define AMOUNT_OF_STUDENTS 624
#define STUDENDTS_IN_CLASS 30
#define NUMBER_OF_SUBJECTS 40
#define MONTHS 1

#define true 1
#define false 0

#include "TheIncludeFile.h" /*File to include!*/
 
/* defines for schema-gen */
 
int main (void) {
    int i,b = 0, max = 200;
    time_t t;
    Exam_block_t *****schema_data;
    int **array;
    
    srand((unsigned) time(&t)); /* seeder vores random */
    
    schema_data = MakeSchema();
    
    array = Make_2D_Array_int(SCHEMA_SIZE, 1000);


    printf("Enter for loekke\n");
    for (i = 0; i < max; i++) {
    
<<<<<<< HEAD
        LoadingScreen(i, max % 20, max-1, b);
        if(i % 20 == max % 20)
            b += 10;
=======
    for (i = 0; i < 1000; i++) {
>>>>>>> e7b0a84799898bac0c2a7122e80ef3ac999226f4

        Length(schema_data, array);
        CalcFitnessOneGeneration(schema_data, array);
        Selection(schema_data);

    }
    ResultOut(schema_data);
    Free2DArray_int(array, SCHEMA_SIZE);
    
    Free5DArray(schema_data);
    

    return 0;
}

