#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mutation(inputs)
{
    int random,
        numOfMut,
        i,
        j;
    time_t t;

    srand((unsigned) time(&t));

    /*varierer mængden af mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMutConfig;

    for (i = 0; i < numOfMut; ++i){
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(task == 0){
            /*incDec bestemmer om ændringen øger eller sænker værdien*/
            incDec = rand() % 2;
            /*den værdi der bliver lagt til mutationen*/
            random = rand() % examDayLenghtConfig;
            /*hvilken eksamen der bliver ændret på*/
            classExam = rand() % numOfExamsT;

            /*tilfælde hvor værdien bliver øget*/
            if (incDec == 1 &&
                (examStartDateT[classExam] + random) > examDayLenghtConfig){
                /*ændrer værdien for alle elever i den givne klasse*/
                for (j = 0; j < StudentsInClassT[classExam]; ++j){
                    examStartDateT[classExam].Student[i] =+ random;
                    examEndDateT[classExam].Student[i] =+ random;
                    task = 1;
                }
            }
            /*tilfælde hvor værdien bliver sænket*/
            else if (incDec == 0 &&
                     (examEndDateT[classExam] - random) < 0){

                for (j = 0; j < StudentsInClassT[classExam]; ++j){
                    examStartDateT[classExam].Student[i] =- random;
                    examEndDateT[c].Student[i] =- random;
                    task = 1;
                }
            }
        }
        task = 0;
    }
    return 0;
}
