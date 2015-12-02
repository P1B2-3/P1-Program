#include <stdio.h>

typedef struct{
	char studentName[SIZE_OF_NAMES],
         studentSurname[SIZE_OF_NAMES];
    int unikID,
    	examNumber;

}Data_Student_info_t;

typedef struct{
	char teacherName[SIZE_OF_NAMES],
         teacherSurname[SIZE_OF_NAMES],
         censorName[SIZE_OF_NAMES],
         censorSurName[SIZE_OF_NAMES];
    char subject[SIZE_OF_NAMES];
}Data_Subject_t;

typedef struct{
	Data_Student students[30];
	char className;
	int year;
	int amountOfStudent;

} Data_Class_t;

typedef struct{
	Data_Student_t students[30];
	Data_Subject_t subject[20];
	int room;

}Data_EksamensBlock_t

typedef struct{
	int ID;
	char klasse[3];
	int examNumber;
	char navn[20];
	char efternavn[20];

}temp_student_data_t;

int main(void){

	Data_Student_t studentdata[30];
	Data_Class_t   classdata[30];
	Data_EksamensBlock_t eksamensblok[100];

	return 0 ;
}


void make_subjectdata(){
	char temp_str[1000];
	FILE *fptr;
	int number, i;
	temp_student_data_t tempstudent;

	if (fopen(fptr"All_the_kids.txt") != NULL){
		
		while(fptr != EOF){

			do{fscanf(fptr, "%s",temp_str)

			} while(strcmp(temp_str, "--Class start--") != 0)

			fscanf(fptr, " Number in Class: %d", &number);

			fscanf(fptr,"s",temp_str);

			for (i = 0; i < number; i++){ /* 26 */
				fscanf(fptr, " --Student start--\n
							  Student unikID: %d\n
							  Klasse nr: %s\n
							  Nr in class: %d\n
							  First name: %s\n
							  Last name: %s\n
							  --Student end--"
							  ,&tempstudent.ID
							  ,tempstudent.klasse
							  ,&tempstudent.eksamensnummer
							  ,tempstudent.navn
							  ,tempstudent.efternavn);
			}
			fscanf(fptr, "%s");

		}

	}

}
