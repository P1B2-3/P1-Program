void ZeroMem(Exam_block_t *****genome_data, int genome, int week, int day, int room, int exam);
int IsClassname(Exam_block_t *****genome_data, int genome, int week, int day, int room, int exam);

void Mutation(int genome, Exam_block_t *****genome_data) {
    int i, j, k, l,
        week, gWeek,
        day, gDay,
        room, gRoom,
        derp = 100000,
        numOfMut,
        numOfRooms,
        numOfWeeks,
        numOfExams,
        xamLenght,
        gXamLenght;
    Exam_block_t *temp_data;

    numOfMut   = (int)GetConfig("a.mutationSize");
    numOfRooms = (int)GetConfig("s.numberOfRooms");
    numOfWeeks = (int)GetConfig("s.numberOfWeeks");
    numOfExams = (int)GetConfig("s.numberOfExams");

    temp_data = (Exam_block_t *) malloc( numOfExams * sizeof( Exam_block_t));

    if (temp_data == NULL){
        printf("Error not memory\n");
        assert(0);
    }

    /*varierer mængden af Mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMut;

    for (l = 0; l < numOfMut; l++) {
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(k < derp) {
            k++;
            week = rand() % (numOfWeeks); /*eksamensperiode længde, standard er 8*/
            day = rand() % 5;                 /*antal dage på en uge*/
            room = rand() % numOfRooms; /*antal rum, standard er 10*/

            gWeek = rand() % (numOfWeeks);
            gDay = rand() % 5;
            gRoom = rand() % numOfRooms;


            xamLenght = genome_data[genome][week][day][room][0].days; /*varigheden af eksamen*/
            gXamLenght = genome_data[genome][gWeek][gDay][gRoom][0].days; /*varighed af den flyttede eksamenslængde*/
            /*følgende if-else kæden finder ud af om eksamnen bliver placeret over en weekend eller ej*/
            if (day <= 2 && gDay <= 2) {
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week][day+xamLenght-1][room][0].year != 0 && 
                    genome_data[genome][week][day][room][0].classname == 
                    genome_data[genome][week][day+xamLenght-1][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == 
                    genome_data[genome][week][day+xamLenght-1][room][0].year) {

                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && 
                        gXamLenght != 0 &&
                        genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0) {   

                        /*double for-loop indsætter al data i den næste position,*/
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                ZeroMem(genome_data,genome,week,day+j,room,i);
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname == 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year == 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                genome_data[genome][week][day+j][room][i]    = temp_data[i];
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay <= 2) {
                if (week != 7 &&
                    genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week+1][day-xamLenght][room][0].year != 0 &&
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week+1][day-xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year      == genome_data[genome][week+1][day-xamLenght][room][0].year){

                    if (gXamLenght != 0 &&
                        genome_data[genome][gWeek][gDay][gRoom][0].year == 0 &&
                        genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0) {
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (day + j <= 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    ZeroMem(genome_data,genome,week,day+j,room,i);
                                }
                                else {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    ZeroMem(genome_data,genome,week+1,day+j-5,room,i);
                                }
                            }
                        }
                        break;
                    }
                    else if (week != 7 &&
                             genome_data[genome][gWeek][gDay][gRoom][0].year   != 0 && 
                             genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year != 0 && 
                             genome_data[genome][gWeek][gDay][gRoom][0].classname       == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                             genome_data[genome][gWeek][gDay][gRoom][0].year            == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year) {
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (day + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]    = temp_data[i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i]  = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = temp_data[i];
                                }
                            }
                        }
                        break;
                    }
                }
            }/*
            else if (day <= 2 && gDay > 2){
                if (gWeek != 7 &&
                    genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week][day+xamLenght-1][room][0].year != 0 && 
                    genome_data[genome][week][day][room][0].classname      == genome_data[genome][week][day+xamLenght-1][room][0].classname &&
                    genome_data[genome][week][day][room][0].year           == genome_data[genome][week][day+xamLenght-1][room][0].year){
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && 
                        genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0 &&
                        IsClassname(genome_data, genome, gWeek, gDay, gRoom, 0) &&
                        IsClassname(genome_data, genome, gWeek+1, gDay-gXamLenght, gRoom, 0)) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (gDay + j <= 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    ZeroMem(genome_data,genome,week,day+j,room,i);
                                }
                                else{
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    ZeroMem(genome_data,genome,week,day+j,room,i);
                                }
                            }
                        }
                        break;
                    }
                    else if (gWeek != 7 &&
                             genome_data[genome][gWeek][gDay][gRoom][0].classname         == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                             genome_data[genome][gWeek][gDay][gRoom][0].year              == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year) {
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (gDay + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]    = temp_data[i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]        = temp_data[i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay > 2) {
                if (week != 7 && gWeek != 7 &&
                    genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week+1][day-xamLenght][room][0].year != 0 &&
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week+1][day-xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == genome_data[genome][week+1][day-xamLenght][room][0].year) {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++){
                                if (gDay + j <= 4 && day + j <= 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    ZeroMem(genome_data,genome,week,day+j,room,i);
                                }
                                else if (gDay + j <= 4 && day + j > 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    ZeroMem(genome_data,genome,week+1,day+j-5,room,i);
                                }
                                else if (gDay + j > 4 && day + j <= 4) {
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    ZeroMem(genome_data,genome,week,day+j,room,i);
                                }
                                else {
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    ZeroMem(genome_data,genome,week+1,day+j-5,room,i);
                                }
                            }
                        }
                        break;
                    }
                    else if (week != 7 && gWeek != 7 &&
                             genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                             genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                             genome_data[genome][gWeek][gDay][gRoom][0].classname         == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                             genome_data[genome][gWeek][gDay][gRoom][0].year              == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                
                                if (gDay + j <= 4 && day + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]    = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j <= 4 && day + j > 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i]  = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = temp_data[i];
                                }
                                else if (gDay + j > 4 && day + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]        = temp_data[i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i]    = temp_data[i];
                                }
                            }
                        }
                        break;
                    }
                }
            }*/
        }
        k = 0;
    }
    free(temp_data);
}

void ZeroMem(Exam_block_t *****genome_data, int genome, int week, int day, int room, int exam){

    genome_data[genome][week][day][room][exam].subjects.teacher.ID = 0;
    strcpy(genome_data[genome][week][day][room][exam].subjects.teacher.name, "0");
    strcpy(genome_data[genome][week][day][room][exam].subjects.teacher.surname, "0");
    genome_data[genome][week][day][room][exam].subjects.censor.ID = 0;
    strcpy(genome_data[genome][week][day][room][exam].subjects.censor.name, "0");
    strcpy(genome_data[genome][week][day][room][exam].subjects.censor.surname, "0");
    genome_data[genome][week][day][room][exam].subjects.y_or_n = 0;
    genome_data[genome][week][day][room][exam].subjects.verbal = 0;
    strcpy(genome_data[genome][week][day][room][exam].student.name, "0");
    strcpy(genome_data[genome][week][day][room][exam].student.surname, "0");
    genome_data[genome][week][day][room][exam].student.unikID = 0;
    genome_data[genome][week][day][room][exam].student.exam_number = 0;
    genome_data[genome][week][day][room][exam].classname = '0';
    genome_data[genome][week][day][room][exam].period_start = 0;
    genome_data[genome][week][day][room][exam].days = 0;
    genome_data[genome][week][day][room][exam].year = 0;
    genome_data[genome][week][day][room][exam].fitness = 0;
}

int IsClassname(Exam_block_t *****genome_data, int genome, int week, int day, int room, int exam){
    if (genome_data[genome][week][day][room][exam].classname == 'A' ||
        genome_data[genome][week][day][room][exam].classname == 'B' ||
        genome_data[genome][week][day][room][exam].classname == 'C' ||
        genome_data[genome][week][day][room][exam].classname == 'D' ||
        genome_data[genome][week][day][room][exam].classname == 'E' ||
        genome_data[genome][week][day][room][exam].classname == 'F' ||
        genome_data[genome][week][day][room][exam].classname == 'G' ||
        genome_data[genome][week][day][room][exam].classname == 'H'){
        return 0;
    }
    return 1;
}