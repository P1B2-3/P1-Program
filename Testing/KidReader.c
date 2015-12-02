#include <stdio.h>
#include <string.h>

#define NUMBER_OF_STUDENTS 2000
#define NUMBER_OF_CLASSES 200

void make_subjectdata(void);
void make_subjectdata2(void);

struct student{
    int unikID;
    int numberInClass;
    char firstname[1024];
    char lastname[1024];
    char class[1024];
};

struct class{
    char class[1024];
    int studentAmount;
    int idRangeFrom;
    int idRangeTo;
};

struct student student[NUMBER_OF_STUDENTS];
struct class class[NUMBER_OF_CLASSES];

int main(void){

  make_subjectdata();

  printf("Student unikID: %i \nNr in class: %i \nFirst name: %s \nLast name: %s \n--Student end--\n"
          ,student[4].unikID
          ,student[4].numberInClass
          ,student[4].firstname
          ,student[4].lastname);

  return 0;
}

void make_subjectdata(){

    int number = NUMBER_OF_STUDENTS;
    int i;

    FILE *file;
    file = fopen("text.txt", "r");

    if (!feof(file)){
            for (i = 1; i < number; i++){
                fscanf(file, " --Student start--\n"
                              "Student unikID: %i\n"
                              "Nr in class: %i\n"
                              "First name: %s\n"
                              "Last name: %s\n"
                              "--Student end--"
                              ,&student[i].unikID
                              ,&student[i].numberInClass
                              ,student[i].firstname
                              ,student[i].lastname);
                if(feof(file)){
                  break;
                }
            }
    }
}

void make_subjectdata2(){

    int number = NUMBER_OF_STUDENTS;
    int i;

    FILE *file;
    file = fopen("text.txt", "r");

    if (!feof(file)){
            for (i = 1; i < number; i++){
                fscanf(file," Number in class: %i\n"
                            "Id range: %i-%i\n"
                            ,&class[i].studentAmount
                            ,&class[i].idRangeFrom
                            ,&class[i].idRangeTo);
                if(feof(file)){
                  break;
                }
            }
    }
}