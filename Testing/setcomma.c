#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j, k;
    char str[2000],
         tempStr[2000],
         bigletter;

    for(i = 0; i < 2000; i++) {
        if(fscanf(fptr,"%[A-Z]%[a-z]"),bigletter,tempStr) == 2) {
            strcpy(str,bigletter);
            strcat(str,tempStr);
            fprintf(fptr,",");
            

        }
    }
}