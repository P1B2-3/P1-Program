void mutation(int genome, Exam_block_t *****genome_data)
{
    int i, j, k, l,
        week, gWeek,
        day, gDay,
        room, gRoom,
        numOfMut,
        numOfRooms,
        numOfWeeks,
        xamLenght,
        gXamLenght;
    time_t t;
    Exam_block_t temp_data[10]; /*Compiler says it is not used, but it is used.....*/

    srand((unsigned) time(&t));

    numOfMut = (int)getConfig("a.mutationSize");
    numOfRooms = (int)getConfig("s.numberOfRooms");
    numOfWeeks = (int)getConfig("s.numberOfWeeks");

    /*varierer mængden af mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMut;

    for (l = 0; l < numOfMut; l++)
    {
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(k < 30000)
        {
            k++;
            week = rand() % numOfWeeks; /*eksamensperiode længde, standard er 8*/
            day = rand() % 5;                 /*antal dage på en uge*/
            room = rand() % numOfRooms; /*antal rum, standard er 10*/

            gWeek = rand() % numOfWeeks;
            gDay = rand() % 5;
            gRoom = rand() % numOfRooms;

            xamLenght = genome_data[genome][week][day][room][0].days; /*varigheden af eksamen*/
            gXamLenght = genome_data[genome][gWeek][gDay][gRoom][0].days; /*varighed af den flyttede eksamenslængde.*/
            /*følgende if-else kæden finder ud af om eksamnen bliver placeret over en weekend eller ej*/
            if (day <= 2 && gDay <= 2)
            {
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week][day+xamLenght][room][0].year != 0 && 
                    genome_data[genome][week][day][room][0].classname == 
                    genome_data[genome][week][day+xamLenght-1][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == 
                    genome_data[genome][week][day+xamLenght-1][room][0].year)
                {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && 
                        genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0)
                    {   /*double for-loop indsætter al data i den næste position,*/
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay+gXamLenght][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname == 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year == 
                    genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay <= 2)
            {
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week+1][day-xamLenght][room][0].year != 0 &&
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week+1][day-xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == genome_data[genome][week+1][day-xamLenght][room][0].year)
                {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (day + j <= 4)
                                {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                                else{
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay+gXamLenght][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year == genome_data[genome][gWeek][gDay+gXamLenght-1][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (day + j <= 4)
                                {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day <= 2 && gDay > 2)
            {
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week][day+xamLenght][room][0].year != 0 && 
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week][day+xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == genome_data[genome][week][day+xamLenght][room][0].year)
                {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4)
                                {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                                else{
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }

                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4)
                                {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay > 2)
            {
                if (genome_data[genome][week][day][room][0].year != 0 && 
                    genome_data[genome][week+1][day-xamLenght][room][0].year != 0 &&
                    genome_data[genome][week][day][room][0].classname == genome_data[genome][week+1][day-xamLenght][room][0].classname &&
                    genome_data[genome][week][day][room][0].year == genome_data[genome][week+1][day-xamLenght][room][0].year)
                {
                    if (genome_data[genome][gWeek][gDay][gRoom][0].year == 0 && genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4 && day + j <= 4)
                                {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                                else if (gDay + j <= 4 && day + j > 4)
                                {
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                                else if (gDay + j > 4 && day + j <= 4)
                                {
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    memset(genome_data[genome][week][day+j][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                                else{
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    memset(genome_data[genome][week+1][day+j-5][room], 0, sizeof(Exam_block_t)*numOfRooms);
                                }
                            }
                        }
                        break;
                    }
                    else if (genome_data[genome][gWeek][gDay][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                    genome_data[genome][gWeek][gDay][gRoom][0].classname == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                    genome_data[genome][gWeek][gDay][gRoom][0].year == genome_data[genome][gWeek+1][gDay-gXamLenght][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRooms; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4 && day + j <= 4)
                                {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j <= 4 && day + j > 4)
                                {
                                    temp_data[i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                    genome_data[genome][gWeek][gDay+j][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = genome_data[genome][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j > 4 && day + j <= 4)
                                {
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week][day+j][room][i];
                                    genome_data[genome][week][day+j][room][i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                                else{
                                    temp_data[i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                    genome_data[genome][gWeek+1][gDay+j-5][gRoom][i] = genome_data[genome][week+1][day+j-5][room][i];
                                    genome_data[genome][week+1][day+j-5][room][i] = genome_data[genome][gWeek+1][gDay+j-5][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        printf("number of mutation tries: %i\n", k);
        k = 0;
    }
}
