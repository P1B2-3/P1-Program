
#include "TheIncludeFile.c" /*File to include!*/
/* input af antal */

int main(void){


	/* Array af structs */
	Data_elever_t ElevData[ANTALELEVERE];
	Data_laerer_t Laerer_Data[ANTALLAERER];
	Data_eksamen_t EksamenData[ANTALEKSAMNER]:
	Data_lokale_t Lokale_Data[ANTALLOKALER];



	Make_database();

	Load_database();




	return 0;
}
