/*Defines*/
#define MAX_GENERATIONS 1000
#define ENOUGH_FITNESS 666
#define AMOUNT_OF_WEEKS 6
#define AMOUNT_OF_DAYS 5
#define AMOUNT_OF_HOURS 8
#define AMOUNT_OF_ROOMS 10

#define SCHEMA_SIZE 300
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
    int k,i;
    time_t t;
    Exam_block_t *****schema_data;
    int **array;
    printf("-2\n");
    srand((unsigned) time(&t)); /* seeder vores random */
    printf("-1\n");
    schema_data = MakeSchema();
    printf("0\n");
    array = Make_2D_Array_int(SCHEMA_SIZE, 1000);
    
    for(k = 0; k < 10; k++) {
        printf("Klasse navn: %c\n",schema_data[0][0][0][0][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][1][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][2][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][3][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][4][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][5][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][6][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][7][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][8][k].classname );
        printf("Klasse navn: %c\n",schema_data[0][0][0][9][k].classname );
        printf("-------------------------------------------------------\n");
    }
    
    
    for (i = 0; i < 20; i++) {
        printf("%i\n",i );
        Length(schema_data, array);
        CalcFitnessOneGeneration(schema_data, array);
        Selection(schema_data);
    }

    Free2DArray_int(array, SCHEMA_SIZE);
    
    Free5DArray(schema_data);
    

    return 0;
}

