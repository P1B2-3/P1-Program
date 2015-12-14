#define SIZE_OF_NAMES 200
#define AMOUNT_OF_STUDENTS 624
#define STUDENTS_IN_CLASS 30
#define NUMBER_OF_SUBJECTS 40
/****************** pre-skema struct *****************/

typedef struct{
    char name[SIZE_OF_NAMES],
         surname[SIZE_OF_NAMES];
    int ID;   
}Teacher_t;

typedef struct{
    char name[SIZE_OF_NAMES],
         surname[SIZE_OF_NAMES];
    int ID;
}Censor_t;

typedef struct{
    char name[SIZE_OF_NAMES],
         surname[SIZE_OF_NAMES];
    int unikID,
        exam_number;
}Student_t;

typedef struct{
    Censor_t       censor;
    Teacher_t      teacher;
    char subject[SIZE_OF_NAMES];
    int y_or_n, /* 1 betydet de skal op i det. */
        verbal;
}Subject_t;

typedef struct{
    Student_t students[STUDENTS_IN_CLASS];
    Subject_t subjects[NUMBER_OF_SUBJECTS];
    int student_num,
        year;
    char name;
}Class_t;

/* struct over en eksamen */
typedef struct{	
    Student_t  student;
    Subject_t  subjects;
    int period_start,
        days;
    int year;
    char classname;
}Exam_block_t;

/*Genetic algorithm structs*/
typedef struct {
    int max, 
        min,
        fitness;
} rankings_t;

/* generator structs */	
typedef struct{
    int CMp,CMb,CMki,CMs,
        CMth,CMps,CMa;
}foersteG;

typedef struct{
    int BMm,BSm,BMf,BSf,
        BMe,BSe,BMk,BSk,
        BMt,BMi,BMb,BMki,
        BMs,BMth;
}andenG;

typedef struct {
    int AMm,ASm,AMd,ASd,
        AMf,AMe,ASe,AMk,ASf,
        ASk,AMt,AMbi,AMki;
}tredjeG;
