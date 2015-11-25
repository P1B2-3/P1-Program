/* main.c,  */

/* antal dage skal komme ind hvor lang eksamens perioden er. Antal_dage */ 
/* struct med data for alle eksamnerne */

/* To Do, indsættelse af C,B,A for eksamnerne 
eks Mn = [0,1]->[False or True, 1->3] */

#define SIZE_OF_ARRAYS 2
#define SIZE_OF_NAMES 20
typedef struct {
    char studentName[SIZE_OF_NAMES],
         studentSurname[SIZE_OF_NAMES],
         studentClass[SIZE_OF_NAMES];
    int unikID,
        Mm[SIZE_OF_ARRAYS],     /*Mundlig matmatik */ 
        Sm[SIZE_OF_ARRAYS],     /*Skriftlig matmatik */ 
        Md[SIZE_OF_ARRAYS],     /*Mundlig dansk */ 
        Sd[SIZE_OF_ARRAYS],     /*Skriftlig dansk */ 
        Mf[SIZE_OF_ARRAYS],     /*Mundlig fysik */ 
        Sf[SIZE_OF_ARRAYS],     /*Skriftlig fysik */ 
        Me[SIZE_OF_ARRAYS],     /*Mundlig engelsk */ 
        Se[SIZE_OF_ARRAYS],     /*Skriftlig engelsk */ 
        Mk[SIZE_OF_ARRAYS],     /*Mundlig kemi */ 
        Sk[SIZE_OF_ARRAYS],     /*Skriftlig kemi */ 
        Mt[SIZE_OF_ARRAYS],     /*Mundlig teknologi */ 
        Mp[SIZE_OF_ARRAYS],     /*Mundlig programmering */ 
        Mi[SIZE_OF_ARRAYS],     /*Mundlig indehistorie */ 
        Mb[SIZE_OF_ARRAYS],     /*Mundlig biologi */ 
        Mki[SIZE_OF_ARRAYS],    /*Mundlig kom it */ 
        Ms[SIZE_OF_ARRAYS],    /*Mundlig samfundsfag */
        Mth[SIZE_OF_ARRAYS];    /*Mundlig teknologi historie */
}Data_students_t;

typedef struct {
    char teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES],
         studentClass[SIZE_OF_NAMES];
    int unikID,
        Mm[SIZE_OF_ARRAYS],     /*Mundlig matmatik */ 
        Sm[SIZE_OF_ARRAYS],     /*Skriftlig matmatik */ 
        Md[SIZE_OF_ARRAYS],     /*Mundlig dansk */ 
        Sd[SIZE_OF_ARRAYS],     /*Skriftlig dansk */ 
        Mf[SIZE_OF_ARRAYS],     /*Mundlig fysik */ 
        Sf[SIZE_OF_ARRAYS],     /*Skriftlig fysik */ 
        Me[SIZE_OF_ARRAYS],     /*Mundlig engelsk */ 
        Se[SIZE_OF_ARRAYS],     /*Skriftlig engelsk */ 
        Mk[SIZE_OF_ARRAYS],     /*Mundlig kemi */ 
        Sk[SIZE_OF_ARRAYS],     /*Skriftlig kemi */ 
        Mt[SIZE_OF_ARRAYS],     /*Mundlig teknologi */ 
        Mp[SIZE_OF_ARRAYS],     /*Mundlig programmering */ 
        Mi[SIZE_OF_ARRAYS],     /*Mundlig indehistorie */ 
        Mb[SIZE_OF_ARRAYS],     /*Mundlig biologi */ 
        Mki[SIZE_OF_ARRAYS],    /*Mundlig kom it */ 
        Ms[SIZE_OF_ARRAYS],     /*Mundlig samfundsfag */
        Mth[SIZE_OF_ARRAYS],    /*Mundlig teknologi historie */
        cancelled[numOfDays],  /* indehoder 0 og 1 for hvilke dage de ikke kan påtage sig eksamner */
        sensor[numOfDays];
}Data_Teachers_t;

typedef struct {
    char studentName[SIZE_OF_NAMES],
         studentSurname[SIZE_OF_NAMES],
         teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES];
    char building[SIZE_OF_NAMES];
    int room;

    char examName[SIZE_OF_NAMES];
    int examNumber;

    int date[3],
        period;
}Data_eksamen_t;

typedef struct {
    char building[SIZE_OF_NAMES];
        room,
        date,
        period;
}Data_room_t;

typedef struct {
    int unikID;
    char name[SIZE_OF_NAMES],
         surname[SIZE_OF_NAMES];
}Data_after_sorting_t;

/* typedef *//*
typedef struct Data_students_t      Data_students_t;
typedef struct Data_Teachers_t      Data_Teachers_t;
typedef struct Data_eksamen_t       Data_eksamen_t;
typedef struct Data_room_t          Data_room_t;
typedef struct Data_after_sorting_t Data_after_sorting_t;
*/