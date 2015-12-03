typedef struct{
    int room,
        date,
        period;

}Data_Exam_t;

typedef struct{
    Data_Exam_t exam[STUDENDTS_IN_CLASS]

}Data_Class_Exam_t;

typedef struct{
    char teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES];
    int teacher_ID;   

}Data_Teacher_t;

typedef struct{
    char censorName[SIZE_OF_NAMES],
         censorSurname[SIZE_OF_NAMES];
    int censor_ID;

}Data_Censor_t;

typedef struct{
    char studentName[SIZE_OF_NAMES],
         studentSurname[SIZE_OF_NAMES];
    int unikID,
        exam_number;

}Data_Student_t;

typedef struct{
    Data_Censor_t       censors[NUMBER_OF_SUBJETS];
    Data_Teacher_t      teachers[NUMBER_OF_SUBJETS];
    Data_Class_Exam_t   class_Exams[NUMBER_OF_SUBJETS];
    char subject[SIZE_OF_NAMES];

}Data_Subject_t;

typedef struct{
    Data_Student_t students[STUDENDTS_IN_CLASS];
    Data_Subject_t subjects[NUMBER_OF_SUBJETS];
    int students,
        year;
    char name;

}Data_Class_t;
