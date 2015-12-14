
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
