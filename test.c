
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char read[128];

    FILE *input_file_pointer;

    input_file_pointer = fopen("config.ini", "r");


    fseek(input_file_pointer, 12, SEEK_CUR);
    fgets(read, 128, input_file_pointer);

    printf("%s\n", read);

    fclose(input_file_pointer);
    

    return 0;
}