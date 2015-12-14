/*En funktion, som tager dato start og dato slut som input og giver antal dage imellem tilbage.*/

/* NOTICE!!!
THERE IS NO INPUTVALIDATION NOR SAFETY FOR WHEN THE NUMBERS GET TOO HIGH TO HANDLE. 
Will have to be changed to work as function and might have to be tweaked in the way it recieves input or handles it.
80 line threshhold not taken into account properly.*/

int AmountOfDays(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);
int DaysInMonth(int month, int year);
int IsLeapYear(int year);

int main(void) {
    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    printf("DD,MM,YYYY DD,MM,YYYY\n");
    scanf("%i,%i,%i %i,%i,%i", &startDay, &startMonth, &startYear, &endDay, &endMonth, &endYear);
    printf("%i/%i-%i to %i/%i-%i = %i day(s)\n", startDay, startMonth, startYear, endDay, endMonth, endYear, 
                                                 AmountOfDays(startDay, startMonth, startYear, endDay, endMonth, endYear));

    return 0;
}

int AmountOfDays(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
    int i, resDays;
    
    if (startYear > endYear || 
       (startYear == endYear && startMonth > endMonth) || 
       (startYear == endYear && startMonth == endMonth && startDay > endDay)) {
        printf("Warning: End date lower than start date.\n");
        return AmountOfDays(endDay, endMonth, endYear, startDay, startMonth, startYear);
    }
    /*If date 1 is greater than date 2 then interchange them and run this function again*/

    if (startYear == endYear && startMonth == endMonth && startDay == endDay) {
        printf("ERROR: SAME DATE\n");
        exit(-1);
    }
    /*Same day, same month, same year.*/

    else {
        if (startMonth == endMonth && startYear == endYear) {
            resDays = endDay - startDay;
        }
        /*Same month, same year*/

        else {
            i = startMonth;
            resDays = (DaysInMonth(startMonth, startYear) - startDay) + endDay;
            /*Amount of relevant days in the first and last month*/

            if (startYear == endYear) {
                while (i < endMonth - 1) {
                    resDays += DaysInMonth(i, startYear);
                    i++;
                }
            }
            /*Different month.*/

            else {
                int j;
                for (j = startYear; j < endYear; j++) {
                    for (; i < 12; i++) {
                        resDays += DaysInMonth(i, startYear);
                    }
                    for (i = 1; i < endMonth; i++) {
                        resDays += DaysInMonth(i, endYear);
                    }
                }
            }
            /*Different year*/
        }
    }
    return resDays;
}

int DaysInMonth(int month, int year) {
    int numberOfDays;
    switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        numberOfDays = 31; break;
    case 4: case 6: case 9: case 11: 
        numberOfDays = 30; break;
    case 2:
        if (IsLeapYear(year)) numberOfDays = 29; 
        else numberOfDays = 28; break;
    default: exit(-1);  break;
    }
    return numberOfDays;
}

int IsLeapYear(int year) {
    if (year % 4) {
        return 0;
    }
    else if (year % 100 && !(year % 400)) {
        return 0;
    }
    else {
        return 1;
    }
}
