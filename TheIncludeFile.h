/*
File just to include, includers..

You know.. The new school-(reform?) says, that we should be better to include others, rather than exclude...
So, now.. Because of this, we've made a file, only to include.
We love you special kids! <3
*/
/*Standard lib*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

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

#define true 1
#define false 0

/*Files*/
#include "Structs/DATA_BASE.h" /* struct data */
#include "readWrite/Write/DaysWhereTeacherIsAbcent.c"
#include "readWrite/Write/StudentData.c"
#include "readWrite/Write/TeacherData.c"
#include "Sorting/Get_exames_student.c"
#include "Sorting/Sort_for_examns.c"
#include "configParser.c"
#include "Structs/Structs-1.h"
#include "Schema-gen.c"
#include "ArrayTilBlokke.c"
#include "Mutation.c"
#include "Skemaprint.c"
#include "amountOfDays.c"
#include "crossoverConcept.c"
#include ""
