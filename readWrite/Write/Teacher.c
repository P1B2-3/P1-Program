/*
This function is created by: Asger Geel Weirsøe for use only in the P1-Project.
The function creates a document that writes the data used to generate a school schedule.


Date:           8/11
Version:        1.00
*/

#include <stdlib.h>
#include <string.h>
 #if defined(_WIN32)
    _mkdir("./data");
 #else 
    mkdir("./data", 0700); 
 #endif    


int TeacherData(int *teacherData, char teacherFirstName, char teacherLastName, int numOfTeachers){




    int i;
    FILE *fptr;

    if ((fptr=fopen("data/TeacherData.txt","r"))!=NULL){
        
        printf("Did not find file, creating new\n");
        fptr = fopen("data/TeacherData.txt", "w"); 
        fputs("//This entire document is dedicated to the processing of a school schedule.\n",fptr);
        fputs("//Please do not edit this file for any reasons. Unless you know what you are doing.\n\n",fptr);
        fputs("//For the teachers, there will be data that tells what classes they can participate in,\n",fptr);
        fputs("//0 = they can not participate, 1 = they can be an replacement & 2 = they can do the class fully\n\n");
        fputs("//The following data will represent: \n",fptr);
        fputs("//Unique ID:                 ID:\n",fptr);
        fputs("//Name:                      Name:\n",fptr);
        fputs("//Mundtlig Matematik:        Mm:\n",fptr);
        fputs("//Skriftlig Matematik:       Sm:\n",fptr);
        fputs("//Mundtlig Dansk:            Md:\n",fptr);
        fputs("//Skriftlig Dansk:           Sd:\n",fptr);
        fputs("//Mundtlig Fysik:            Mf:\n",fptr);
        fputs("//Skriftlig Fysik:           Sf:\n",fptr);
        fputs("//Mundtlig Engelsk:          Me:\n",fptr);
        fputs("//Skriftlig Engelsk:         Se:\n",fptr);
        fputs("//Mundtlig Kemi:             Mk:\n",fptr);
        fputs("//Skriftlig Kemi:            Sk:\n",fptr);
        fputs("//Mundtlig Teknologi:        Mt:\n",fptr);
        fputs("//Mundtlig Programmering:    Mp:\n",fptr);
        fputs("//Mundtlig Idéhistorie:      Mi:\n",fptr);
        fputs("//Mundtlig Biologi:          Mb:\n",fptr);
        fputs("//Mundtlig kom/it:           Mki:\n",fptr);
        fputs("//Mundtlig Samfundsfag:      Ms:\n\n\n\n",fptr);

        fputs("--------ALL TEACHERS--------\n",fptr);
        for(i = 0;i<numOfTeachers;i++){
            fputs("--Teacher Start--\n",fptr);
            fputs("Teacher Number: %i\n",fptr,i);
            fputs("ID: %i\n",fptr,teacherData[0]);
            fputs("Name: %s %s\n",fptr,teacherFirstName,teacherLastName);
            fputs("Mm: %i\n",fptr,teacherData[1]);
            fputs("Sm: %i\n",fptr,teacherData[2]);
            fputs("Md: %i\n",fptr,teacherData[3]);
            fputs("Sd: %i\n",fptr,teacherData[4]);
            fputs("Mf: %i\n",fptr,teacherData[5]);
            fputs("Sf: %i\n",fptr,teacherData[6]);
            fputs("Me: %i\n",fptr,teacherData[7]);
            fputs("Se: %i\n",fptr,teacherData[8]);
            fputs("Mk: %i\n",fptr,teacherData[9]);
            fputs("Sk: %i\n",fptr,teacherData[10]);
            fputs("Mt: %i\n",fptr,teacherData[11]);
            fputs("Mp: %i\n",fptr,teacherData[12]);
            fputs("Mi: %i\n",fptr,teacherData[13]);
            fputs("Mb: %i\n",fptr,teacherData[14]);
            fputs("Mki: %i\n",fptr,teacherData[15]);
            fputs("Ms: %i\n",fptr,studentData[16]);
            fputs("--Teacher End--\n\n",fptr);
        }
    }
        
        fclose(fptr);
    return 0;
}