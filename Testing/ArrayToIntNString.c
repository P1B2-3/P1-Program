int arrayToIntNString(int n, int array[], char examType[]){
    int exam;

    switch (array[n]){
        case 0:
            exam = 0;
            break;
        case 1:
            exam = 1;
            break;
        default :
            printf("invalid exam\n");
    }

    switch (n){
        case 0:
            /*Mundtlig matmatik*/
            strcpy(examType,"AMm");
            break;
        case 1:
            /*Skriftlig matmatik*/
            strcpy(examType,"ASm");
            break;
        case 2:
            /*Mundtlig dansk*/
            strcpy(examType,"AMd");
            break;
        case 3:
            /*Skriftlig dansk*/
            strcpy(examType,"ASd");
            break;
        case 4:
            /*Mundtlig fysik*/ 
            strcpy(examType,"AMf");
            break;
        case 5:
            /*Skriftlig fysik*/
            strcpy(examType,"ASf");
            break;
        case 6:
            /*Mundtlig engelsk*/
            strcpy(examType,"AMe");
            break;
        case 7:
            /*Skriftlig engelsk*/
            strcpy(examType,"ASe");
            break;
        case 8:
            /*Mundtlig kemi*/
            strcpy(examType,"AMk");
            break;
        case 9:
            /*Skriftlig kemi*/
            strcpy(examType,"ASk");
            break;
        case 10:
            /*Mundtlig teknologi*/
            strcpy(examType,"AMt");
            break;
        case 11:
            /*Mundtlig bioteknologi*/
            strcpy(examType,"AMbt");
            break;
        case 12:
            /*Mundtlig kom it*/
            strcpy(examType,"AMki");
            break;
        case 13:
            /*Mundtlig matmatik*/
            strcpy(examType,"BMm");
            break;
        case 14:
            /*Skriftlig matmatik*/
            strcpy(examType,"BSm");
            break;
        case 15:
            /*Mundtlig fysik*/
            strcpy(examType,"BMf");
            break;
        case 16:
            /*Skriftlig fysik*/
            strcpy(examType,"BSf");
            break;
        case 17:
            /*Mundtlig engelsk*/
            strcpy(examType,"BMe");
            break;
        case 18:
            /*Skriftlig engelsk*/
            strcpy(examType,"BSe");
            break;
        case 19:
            /*Mundtlig kemi*/
            strcpy(examType,"BMk");
            break;
        case 20:
            /*Skriftlig kemi*/
            strcpy(examType,"BSk");
            break;
        case 21:
            /*Mundtlig teknologi*/
            strcpy(examType,"BMt");
            break;
        case 22:
            /*Mundtlig indehistorie*/
            strcpy(examType,"BMi");
            break;
        case 23:
            /*Mundtlig biologi*/
            strcpy(examType,"BMb");
            break;
        case 24:
            /*Mundtlig kom it*/
            strcpy(examType,"BMki");
            break;
        case 25:
            /*Mundtlig samfundsfag*/
            strcpy(examType,"BMs");
            break;
        case 26:
            /*Mundtlig teknologi historie*/
            strcpy(examType,"BMth");
            break;
        case 27:
            /*Mundtlig programmering*/
            strcpy(examType,"1Mp");
            break;
        case 28:
            /*Mundtlig biologi*/
            strcpy(examType,"1Mb");
            break;
        case 29:
            /*Mundtlig kom it*/
            strcpy(examType,"1Mki");
            break;
        case 30:
            /*Mundtlig samfundsfag*/
            strcpy(examType,"1Ms");
            break;
        case 31:
            /*Mundtlig teknologi historie*/
            strcpy(examType,"1Mth");
            break;
        case 32:
            /*Mundtlig psykologi*/
            strcpy(examType,"CMps");
            break;
        case 33:
            /*Mundtlig astronomi*/
            strcpy(examType,"CMa");
            break;
        default :
            printf("faulty input\n");
    }
    return (exam);
}
