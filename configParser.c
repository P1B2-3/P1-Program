/*
This function (getConfig(string)) will search for, and read a given string's value
in the config.ini file.

example:
getConfig("s.numberOfStudents") - returns the value 24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getConfig(char* in);

struct line{
    char line[1024];
    int value;
};

int main(void){

    printf("%i\n", getConfig("g.totalExamPeriodTo"));

    return 0;
}

int getConfig(char* in) {

    struct line line[20];
    int i;

    FILE *file;

    file = fopen("config.ini", "r");

    /*LOAD LINES TO STRUCT*/
    for(i = 0; i <= 20; i++){

        fscanf(file," %[a-zA-Z.] - %i" ,line[i].line, &line[i].value);
        fgetc(file);

        if (feof(file)){
            break;
        }
    }

    fclose(file);

    /*CHECK IF == INPUT*/
    for(i = 0; i <= 20 ; i++){
        if(strstr(in, line[i].line)){
            return line[i].value;
        }
    }

    return 0; /*If this returns, input did not find corosponding*/
}