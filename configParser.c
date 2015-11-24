/*
This function (getConfig(string)) will search for, and read a given string's value
in the config.ini file.

example:
getConfig(s.numberOfStudents) - returns the value 24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getConfig(char* str) {

  FILE *input_file_pointer;

  char *value[16];
  char tmp[1024];

  input_file_pointer = fopen("config.ini", "r");

  if (input_file_pointer != NULL) {
      
        /*Do stuff

        search for given string, and read the corresponding value,
        to store in value[16]
        */

    while(fgets(tmp, 1024, input_file_pointer) != NULL) {
        
        if((strstr(tmp, str)) != NULL) {

            strcpy(*value, (strchr(tmp, *str)) );

        }
        
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