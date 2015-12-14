/*Defines*/
#define SIZE_OF_NAMES 200
#define AMOUNT_OF_STUDENTS 624
#define STUDENDTS_IN_CLASS 30
#define NUMBER_OF_SUBJECTS 40

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
    int studentAmount = getConfig(), /* data fra config */
        teacherAmount = getConfig(),
        eksamenAmount = getConfig(),
        roomAmount    = getConfig();

    /* Array af structs */
    Data_students_t         StudentData[studentAmount];
    Data_Teachers_t         TeacherData[teacherAmount];
    Data_eksamen_t          EksamenData[eksamenAmount]:
    Data_room_t             RoomData[roomAmount];
    Data_after_sorting_t        DataSort[studentAmount];

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
