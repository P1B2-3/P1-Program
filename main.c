
#include "TheIncludeFile.h" /*File to include!*/
/* input af antal */



int main(void){
	/* Variabels */
	int studentAmount = getConfig(), /* data fra config */
		teacherAmount = getConfig(),
		eksamenAmount = getConfig(),
		roomAmount    = getConfig();


	/* Array af structs */
	Data_students_t 		StudentData[studentAmount];
	Data_Teachers_t 		TeacherData[teacherAmount];
	Data_eksamen_t 			EksamenData[eksamenAmount]:
	Data_room_t 			RoomData[roomAmount];
	Data_after_sorting_t 	DataSort[];	

	/* */


	Make_database();

	Load_database();




	return 0;
}


/* items */
/* databasen */