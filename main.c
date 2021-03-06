/*Defines*/
#define MAX_GENERATIONS 1000
#define ENOUGH_FITNESS 666
#define AMOUNT_OF_WEEKS 6
#define AMOUNT_OF_DAYS 5
#define AMOUNT_OF_HOURS 8
#define AMOUNT_OF_ROOMS 10
#define RUNS 300

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
    int k,i,n,p,q,sum = 0,fitsum = 0,b = 0,percent;
    int **array;
    int data[RUNS];
    time_t t;
    Exam_block_t *****schema_data;
    double tempPercent;

    srand((unsigned) time(&t)); /* seeder vores random */
    
    
    tempPercent =  RUNS / 100;
    percent = (int)tempPercent;
    
    schema_data = MakeSchema();
    
    array = Make_2D_Array_int(SCHEMA_SIZE, 1000);

    for (i = 0; i < RUNS; i++) {
        
        if(i == 0) {
            fprintf(stderr,"                                                                   %i%%",i );
            b++;
        }
            
        else if(i % percent == 0 && i != 0) {
            fprintf(stderr,"\r                                                                   %i%%",b);
            b++;
        }         

        else if(i % percent == 0 && b == 100 ){
            fprintf(stderr,"\r                                                                   %i%%\n",b );
        }

        Length(schema_data, array);
        CalcFitnessOneGeneration(schema_data, array);
        
        
        Selection(schema_data);
        
        data[i] = fitsum / SCHEMA_SIZE;

    }
    ResultDataOut(data);
    ResultOut(schema_data);
    Free2DArray_int(array, SCHEMA_SIZE);
    
    Free5DArray(schema_data);
    

    return 0;
}

