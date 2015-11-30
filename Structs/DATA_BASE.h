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
        AMm[SIZE_OF_ARRAYS],
        BMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
        ASm[SIZE_OF_ARRAYS],
        BSm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */ 
        AMd[SIZE_OF_ARRAYS],    /*Mundlig dansk */ 
        ASd[SIZE_OF_ARRAYS],    /*Skriftlig dansk */ 
        AMf[SIZE_OF_ARRAYS],
        BMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */ 
        ASf[SIZE_OF_ARRAYS],
        BSf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */ 
        AMe[SIZE_OF_ARRAYS],
        BMe[SIZE_OF_ARRAYS],
        CMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */ 
        ASe[SIZE_OF_ARRAYS],
        BSe[SIZE_OF_ARRAYS],
        CSe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */ 
        AMk[SIZE_OF_ARRAYS],
        BMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */ 
        ASk[SIZE_OF_ARRAYS],
        Sk[SIZE_OF_ARRAYS],     /*Skriftlig kemi */ 
        AMt[SIZE_OF_ARRAYS],
        BMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */ 
        CMp[SIZE_OF_ARRAYS],    /*Mundlig programmering */ 
        BMi[SIZE_OF_ARRAYS],    /*Mundlig indehistorie */ 
        BMb[SIZE_OF_ARRAYS],
        CMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */ 
        AMbi[SIZE_OF_ARRAYS];   /*Mundlig bioteknologi*/
        AMki[SIZE_OF_ARRAYS],
        BMki[SIZE_OF_ARRAYS],
        CMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */ 
        BMs[SIZE_OF_ARRAYS],
        Ms[SIZE_OF_ARRAYS],     /*Mundlig samfundsfag */
        BMth[SIZE_OF_ARRAYS];    /*Mundlig teknologi historie */
}Data_students_t;

typedef struct {
    char teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES],
         studentClass[SIZE_OF_NAMES];
    int unikID,
        AMm[SIZE_OF_ARRAYS],
        BMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
        ASm[SIZE_OF_ARRAYS],
        BSm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */ 
        AMd[SIZE_OF_ARRAYS],    /*Mundlig dansk */ 
        ASd[SIZE_OF_ARRAYS],    /*Skriftlig dansk */ 
        AMf[SIZE_OF_ARRAYS],
        BMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */ 
        ASf[SIZE_OF_ARRAYS],
        BSf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */ 
        AMe[SIZE_OF_ARRAYS],
        BMe[SIZE_OF_ARRAYS],
        CMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */ 
        ASe[SIZE_OF_ARRAYS],
        BSe[SIZE_OF_ARRAYS],
        CSe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */ 
        AMk[SIZE_OF_ARRAYS],
        BMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */ 
        ASk[SIZE_OF_ARRAYS],
        Sk[SIZE_OF_ARRAYS],     /*Skriftlig kemi */ 
        AMt[SIZE_OF_ARRAYS],
        BMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */ 
        CMp[SIZE_OF_ARRAYS],    /*Mundlig programmering */ 
        BMi[SIZE_OF_ARRAYS],    /*Mundlig indehistorie */ 
        BMb[SIZE_OF_ARRAYS],
        CMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */ 
        AMbi[SIZE_OF_ARRAYS];   /*Mundlig bioteknologi*/
        AMki[SIZE_OF_ARRAYS],
        BMki[SIZE_OF_ARRAYS],
        CMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */ 
        BMs[SIZE_OF_ARRAYS],
        Ms[SIZE_OF_ARRAYS],     /*Mundlig samfundsfag */
        BMth[SIZE_OF_ARRAYS];    /*Mundlig teknologi historie */
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
