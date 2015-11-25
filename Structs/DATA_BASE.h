/* main.c,  */

/* antal dage skal komme ind hvor lang eksamens perioden er. Antal_dage */ 
/* struct med data for alle eksamnerne */

struct data_students_t{
    int unikID;
    char studentName;
    char studentSurname;
    int Mm;     /*Mundlig matmatik */ 
    int Sm;     /*Skriftlig matmatik */ 
    int Md;     /*Mundlig dansk */ 
    int Sd;     /*Skriftlig dansk */ 
    int Mf;     /*Mundlig fysik */ 
    int Sf;     /*Skriftlig fysik */ 
    int Me;     /*Mundlig engelsk */ 
    int Se;     /*Skriftlig engelsk */ 
    int Mk;     /*Mundlig kemi */ 
    int Sk;     /*Skriftlig kemi */ 
    int Mt;     /*Mundlig teknologi */ 
    int Mp;     /*Mundlig programmering */ 
    int Mi;     /*Mundlig indehistorie */ 
    int Mb;     /*Mundlig biologi */ 
    int Mki;    /*Mundlig kom it */ 
    int Ms;     /*Mundlig samfundsfag */
    int Mth;    /*Mundlig teknologi historie */
};

struct data_Teachers_t{
    int unikID
    char teacherName;
    char teacherSurname;
    int Mm;     /*Mundlig matmatik */ 
    int Sm;     /*Skriftlig matmatik */ 
    int Md;     /*Mundlig dansk */ 
    int Sd;     /*Skriftlig dansk */ 
    int Mf;     /*Mundlig fysik */ 
    int Sf;     /*Skriftlig fysik */ 
    int Me;     /*Mundlig engelsk */ 
    int Se;     /*Skriftlig engelsk */ 
    int Mk;     /*Mundlig kemi */ 
    int Sk;     /*Skriftlig kemi */ 
    int Mt;     /*Mundlig teknologi */ 
    int Mp;     /*Mundlig programmering */ 
    int Mi;     /*Mundlig indehistorie */ 
    int Mb;     /*Mundlig biologi */ 
    int Mki;    /*Mundlig kom it */ 
    int Ms;     /*Mundlig samfundsfag */
    int Mth;    /*Mundlig teknologi historie */
    int cancelled[numberOfDays];  /* indehoder 0 og 1 for hvilke dage de ikke kan påtage sig eksamner */
    int sensor[numberOfDays];
};

struct data_eksamen_t{
    char studentName;
    char studentSurname;
    char teacherName;
    char teacherSurname;

    char building;
    int room;

    char examName;
    int examNumber;

    int date;
    int time;
};

struct data_lokale_t{
    char building;
    int room;

    int date;
    int time;
};
struct data_after_sorting_t{
    int unikID;
    char name;
    char surname;
};

/* typedef */
typedef struct data_students_t data_students_t;
typedef struct data_Teachers_t data_Teachers_t;
typedef struct data_eksamen_t data_eksamen_t;
typedef struct data_lokale_t data_lokale_t;
typedef struct data_after_sorting_t data_after_sorting_t;
