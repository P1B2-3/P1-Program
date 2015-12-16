void Mutation(int genome, Exam_block_t *****genome_data) {
    int i, j, k, l,
        week, gWeek,
        day, gDay,
        room, gRoom,
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

    printf("numOfMut %i\n",numOfMut);
    temp_data = (Exam_block_t *) malloc( numOfExams * sizeof( Exam_block_t));

    if (temp_data == NULL){
        printf("Error not memory\n");
        assert(0);
    }
    printf("START! mutation.\n");

    /*varierer mængden af Mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMut;

    for (l = 0; l < numOfMut; l++) {
        printf("forLoekke %i\n",l );
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(k < 30000) {
            k++;
            week = rand() % (numOfWeeks-1); /*eksamensperiode længde, standard er 8*/
            day = rand() % 5;                 /*antal dage på en uge*/
            room = rand() % numOfRooms; /*antal rum, standard er 10*/

            gWeek = rand() % (numOfWeeks-1);
            gDay = rand() % 5;
            gRoom = rand() % numOfRooms;
            printf("week: %i day: %i room: %i\n",week,day,room );
            printf("gWeek: %i gDay: %i gRoom: %i\n",gWeek,gDay,gRoom );


            xamLenght = genome_data[genome][week][day][room][0].days; /*varigheden af eksamen*/
            gXamLenght = genome_data[genome][gWeek][gDay][gRoom][0].days; /*varighed af den flyttede eksamenslængde*/
            printf("xamLenght ; %i && gXamLenght ; %i\n",xamLenght,gXamLenght);
            /*følgende if-else kæden finder ud af om eksamnen bliver placeret over en weekend eller ej*/
            if (day <= 2 && gDay <= 2) {
                printf("enteres here. ub day <= 2 && gDay <= 2\n");
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
                                memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
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
                                genome_data[genome][week][day+j][room][i]    = genome_data[genome][gWeek][gDay+j][gRoom][i];
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay <= 2) {
                printf("here it gets :day > 2 && gDay <=2\n");
                if (genome_data[genome][week][day][room][0].year != 0 && 
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
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                                else {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year   != 0 && 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname       == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year            == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year) {
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (day + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]    = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i]  = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day <= 2 && gDay > 2){
                printf("Here it gets: day <= 2 && gDay > 2\n");
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week][day+xamLenght-1][room][0].year != 0 && 
                    genome_data[genome][week][day][room][0].classname      == genome_data[genome][week][day+xamLenght-1][room][0].classname &&
                    genome_data[genome][week][day][room][0].year           == genome_data[genome][week][day+xamLenght-1][room][0].year){
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (gDay + j <= 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                                else{
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }

                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year     != 0 && 
                    genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname         == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year              == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year) {
                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++) {
                                if (gDay + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]    = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]        = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay > 2) {
                printf("here it gets : day > 2 && gDay > 2\n");
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week+1][day-xamLenght][room][0].year != 0 &&
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week+1][day-xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == genome_data[genome][week+1][day-xamLenght][room][0].year) {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0) {

                        for (i = 0; i < numOfExams; i++) {
                            for (j = 0; j < xamLenght; j++){
                                if (gDay + j <= 4 && day + j <= 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                                else if (gDay + j <= 4 && day + j > 4) {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                                else if (gDay + j > 4 && day + j <= 4) {
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                                else {
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfExams);
                                }
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year     != 0 && 
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
                                    genome_data[genome][week+1][day+j-5][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j > 4 && day + j <= 4) {
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i]        = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i]    = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        printf("Number of Mutation tries: %i\n", k);
        k = 0;
    }
    free(temp_data);
}
