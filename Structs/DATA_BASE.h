/* main.c,  */

/* antal dage skal komme ind hvor lang eksamens perioden er. Antal_dage */ 
/* struct med data for alle eksamnerne */


#define SIZE_OF_ARRAYS 2
#define SIZE_OF_NAMES 20
typedef struct {
    char studentName[SIZE_OF_NAMES],
         studentSurname[SIZE_OF_NAMES],
         studentClass[SIZE_OF_NAMES];
    int unikID,
     /*0*/   AMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
     /*1*/   ASm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */
     /*2*/    AMd[SIZE_OF_ARRAYS],    /*Mundlig dansk */ 
     /*3*/   ASd[SIZE_OF_ARRAYS],    /*Skriftlig dansk */ 
     /*4*/   AMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */ 
     /*5*/   ASf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */
     /*6*/   AMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */
     /*7*/   ASe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */
     /*8*/   AMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */
     /*9*/   ASk[SIZE_OF_ARRAYS],    /*Skriftlig kemi */
     /*10*/   AMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */
     /*11*/   AMbi[SIZE_OF_ARRAYS];   /*Mundlig bioteknologi*/
     /*12*/   AMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */
        
     /*13*/   BMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
     /*14*/   BSm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */
     /*15*/   BMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */    
     /*16*/   BSf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */
     /*17*/   BMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */
     /*18*/   BSe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */
     /*19*/   BMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */        
     /*20*/   BSk[SIZE_OF_ARRAYS],    /*Skriftlig kemi */    
     /*21*/   BMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */
     /*22*/   BMi[SIZE_OF_ARRAYS],    /*Mundlig indehistorie */ 
     /*23*/   BMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */   
     /*24*/   BMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */
     /*25*/   BMs[SIZE_OF_ARRAYS],    /*Mundlig samfundsfag */
     /*26*/   BMth[SIZE_OF_ARRAYS];   /*Mundlig teknologi historie */
        
     /*27*/   CMp[SIZE_OF_ARRAYS],    /*Mundlig programmering */
     /*28*/   CMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */
     /*29*/   CMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */ 
     /*30*/   CMs[SIZE_OF_ARRAYS],    /*Mundlig samfundsfag */
     /*31*/   CMth[SIZE_OF_ARRAYS];   /*Mundlig teknologi historie */
    
        /*Valgfag*/
     /*32*/   CMps[SIze_OF_ARRAYS];    /*Mundtlig psykologi*/
     /*33*/   CMa[SIze_OF_ARRAYS];    /*Mundtlig astronomi*/
        
        
        
        /*A = 12
          B = 13
          C = 6*/
}Data_students_t;

typedef struct {
    char teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES],
         studentClass[SIZE_OF_NAMES];
    int unikID,
        AMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
        ASm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */
        AMd[SIZE_OF_ARRAYS],    /*Mundlig dansk */ 
        ASd[SIZE_OF_ARRAYS],    /*Skriftlig dansk */ 
        AMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */ 
        ASf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */
        AMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */
        ASe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */
        AMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */
        ASk[SIZE_OF_ARRAYS],    /*Skriftlig kemi */
        AMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */
        AMbi[SIZE_OF_ARRAYS];   /*Mundlig bioteknologi*/
        AMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */
        
        BMm[SIZE_OF_ARRAYS],    /*Mundlig matmatik */ 
        BSm[SIZE_OF_ARRAYS],    /*Skriftlig matmatik */
        BMf[SIZE_OF_ARRAYS],    /*Mundlig fysik */    
        BSf[SIZE_OF_ARRAYS],    /*Skriftlig fysik */
        BMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */
        BSe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */
        BMk[SIZE_OF_ARRAYS],    /*Mundlig kemi */        
        BSk[SIZE_OF_ARRAYS],    /*Skriftlig kemi */    
        BMt[SIZE_OF_ARRAYS],    /*Mundlig teknologi */
        BMi[SIZE_OF_ARRAYS],    /*Mundlig indehistorie */ 
        BMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */   
        BMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */
        BMs[SIZE_OF_ARRAYS],    /*Mundlig samfundsfag */
        BMth[SIZE_OF_ARRAYS];   /*Mundlig teknologi historie */
        
        CMe[SIZE_OF_ARRAYS],    /*Mundlig engelsk */
        CSe[SIZE_OF_ARRAYS],    /*Skriftlig engelsk */
        CMp[SIZE_OF_ARRAYS],    /*Mundlig programmering */
        CMb[SIZE_OF_ARRAYS],    /*Mundlig biologi */
        CMki[SIZE_OF_ARRAYS],   /*Mundlig kom it */ 
        CMs[SIZE_OF_ARRAYS],    /*Mundlig samfundsfag */
        
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
