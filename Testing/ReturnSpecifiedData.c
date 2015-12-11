/*
 *  Funktion der skal returnere en af følgende:
 *
 *  -$$ x y z(bloknummer)
 *  -examens_class_ID;
 *  -name_surname
 *  -Class
 *  -unikID
 *  -subject_number
 *  -subject_name
 *  -lokale
 *  -periodestart
 *  -periode slut
 *
 *  Ud fra et af indputsne. Returnere en pointer til endten Char* eller int
 *  Så den skal "fanges" i en void pointer, som så senere kan blive defineret til
 *  til en type.
 *
 *  Author: Asger Geel Weirsøe
 *  Version: 1.00
 */

typedef int datint;

datint ReturnSpeceficData(char * indput, datint indput_nr_class,   datint indput_nr_subject, 
                           datint indput_nr_student, datint indput_nr_teacher,
                           datint indput_nr_censor,  datint indput_nr_classexam, 
                           datint indput_nr_exam,    datint indput_nr_datablock,
                           Data_block_t datablock[]) {
    char tempStr[200],buffer[200];
    if(!strcmp(indput,"examens_class_ID")) {
        return "there is no unikID for examens_class"
    }
    else if(strstr(indput,"name_surname")) {
        if(indput_nr_teacher != -1 
        && indput_nr_censor  == -1
        && indput_nr_student == -1) {
            strcpy(tempStr,datablock[].datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].teacher.name);
            strcat(tempStr," ");
            strcat(tempStr,datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].teacher.surname)
            return tempStr;
        }else if(indput_nr_teacher == -1 
             && indput_nr_censor  != -1
             && indput_nr_student == -1){
            strcpy(tempStr,datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].censor.name);
            strcat(tempStr," ");
            strcat(tempStr,datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].censor.surname)
            return tempStr;
        }else if(indput_nr_teacher == -1 
             && indput_nr_censor  == -1
             && indput_nr_student != -1){
            strcpy(tempStr,datablock[indput_nr_datablock].classdata.student[indput_nr_student].name);
            strcat(tempStr," ");
            strcat(tempStr,datablock[indput_nr_datablock].classdata.student[indput_nr_student].surname)
            return tempStr;
        }else
            printf("Error; indput nr incorrect.")
    }
    else if(!strcmp(indput,"klasse")) {
        itoa(datablock[indput_nr_datablock].classdata.year,buffer,10);

        strcpy(tempStr,buffer);
        strcat(tempStr,".");
        strcat(tempStr,datablock[indput_nr_datablock].classdata.name);
        return tempStr;
    }
    else if(!strcmp(indput,"unikID")) {
        if(indput_nr_teacher != -1 
        && indput_nr_censor  == -1
        && indput_nr_student == -1) 
            return datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].teacher.unikID;
        else if(indput_nr_teacher == -1 
             && indput_nr_censor  != -1
             && indput_nr_student == -1)
            return datablock[indput_nr_datablock].classdata.subjects[indput_nr_subject].censor.unikID;
        else if(indput_nr_teacher == -1 
             && indput_nr_censor  == -1
             && indput_nr_student != -1)
            return datablock[indput_nr_datablock].classdata.student[indput_nr_student].unikID;
        else
            printf("Error; indput nr incorrect.")
    }
    else if(!strcmp(indput,"subject_number")) {
        return datablock[input_nr_datablock].classdata.student[indput_nr_student].exam_numbrer
    }
    else if(!strcmp(indput,"subject_name")) {
        return datablock[indput_nr_datablock].classdata.subject[indput_nr_subject].subject
    }
    else if(!strcmp(indput,"lokale")) {
        return datablock[indput_nr_datablock].classdata.subject[indput_nr_subject].ClassExam[indput_nr_subject].room;
    }
    else if(!strcmp(indput,"period_start")) {
        return datablock[indput_nr_datablock].periode_start;
    }
    else if(!strcmp(indput,"period_end")) {
        return datablock[indput_nr_datablock].periode_slut;
    }
}

