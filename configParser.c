/*
This function (getConfig(string)) will search for, and read a given string's value
in the config.ini file.

example:
getConfig(s.numberOfStudents) - returns the value 24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE *input_file_pointer;

    char *str = "s.numberOfStudents";
    char *value[16];
    char tmp[1024];
    const char s[] = {':', ';'};
    char *pch[128];

    int line_num = 1;
    int find_result = 0;

    input_file_pointer = fopen("config.ini", "r");

    if (input_file_pointer != NULL) {

        while(fgets(tmp, 1024, input_file_pointer) != NULL) {
            
            if((strstr(tmp, *str)) != NULL) {


                /*line_num here = line with word on it*/

                /*pch = strtok(getline(line_num, 100, input_file_pointer));*/

                printf("%s\n", getline(line_num, 100, input_file_pointer) );
            }

            line_num++;
        
        }

        fclose(input_file_pointer);
        return *value;

    }

    else{
        printf("ERROR: Config.ini not found.");
        exit(EXIT_FAILURE);
        return 0;
    }
}