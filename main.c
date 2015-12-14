/*Defines*/
#define GENERATION_SIZE 300

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
#define MONTHS 1

#define true 1
#define false 0

#include "TheIncludeFile.h" /*File to include!*/


int main (void){

    Exam_block_t *****schema_data = Make_schema();

    int i,j;
    for (i = 0; i < ROOM_SIZE; i++)
    {
        for (j = 0; j < DAY_SIZE; j++)
        {
            printf("year %i, day %i, room %i\n",schema_data[0][0][j][i][0].year, j, i);
        }
    }

    return 0;
}

/* items */
/* databasen */
