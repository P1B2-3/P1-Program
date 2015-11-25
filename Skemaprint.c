#include <stdio.h>

void printScheduleGrid(void);

int main(void) {
	printf("This program will print a shedule grid: \n");
	printScheduleGrid();

	return 0;
}

void printScheduleGrid(void) {
	int unikID = 219, examTime = 1, dateDay = 6, dateMonth = 6, roomNr = 125;
	double timeFrom = 10.30, timeTo = 11.30;
	char studentFirstName[] = "Jens", studentLastName[] = "Nielsen", exam[] = "Fysik Mundtlig", teacher[] = "Soerensen", censor[] = "Kjaer";

	printf("X---------------------------------------------------X \n");
	printf("| ID:      %d                                         \n", unikID);
	printf("|                                                     \n");
	printf("X---------------------------------------------------X \n");
	printf("| Navn:    %s %s                                      \n", studentFirstName, studentLastName);
	printf("|                                                     \n");
	printf("X---------------------------------------------------X \n");
	printf("| Eksamen: %s                                         \n", exam);
	printf("|                                                     \n");
	printf("| Lokale:  %d                                         \n", roomNr);
	printf("|                                                     \n");
	printf("| Laerer:  %s  Censor: %s                             \n", teacher, censor);
	printf("|                                                     \n");
	printf("| Tid:     %d time(r)  %lf til %lf                    \n", examTime, timeFrom, timeTo);
	printf("|                                                     \n");	
	printf("| Dato:    %d/%d                                      \n", dateDay, dateMonth);
	printf("|                                                     \n");
	printf("X---------------------------------------------------X \n");
}
