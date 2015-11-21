/* main.c,  */


/* antal dage skal komme ind hvor lang eksamens perioden er. Antal_dage */ 
/* struct med data for alle eksamnerne */

struct Data_elever_t{
    int unikID;
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

struct Data_lærer_t{
    char navn;
    char fag;               /* hvilke eksamner læreren kan tage */
    int afbud[Antal_dage];  /* indehoder 0 og 1 for hvilke dage de ikke kan påtage sig eksamner */
    int ude_sensor[Antal_dage];
};

struct Data_eksamen_t{
    char elev_navn;
    char lærer_navn;
    char sensor_navn;

    char bygning;
    int lokale;

    char eksamen_navn;
    int eksamen_nummer

    int dato;
    int tid;
};

struct Data_lokale_t{
    char bygning;
    int lokale;

    int dato;
    int tid;
};

/* typedef */
typedef struct Data_elever_t Data_elever_t;
typedef struct Data_lærer_t Data_lærer_t;
typedef struct Data_eksamen_t Data_eksamen_t;
typedef struct Data_lokale_t Data_lokale_t;
