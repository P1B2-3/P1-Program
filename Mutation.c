

void mutation(int skema, Data_block_t *****skema_data)
{
    int numOfMut,
        i, j, k, l,
        week, gWeek,
        day, gDay,
        room, gRoom;
    time_t t;
    Data_block_t temp_data[10];

    srand((unsigned) time(&t));

    /*varierer mængden af mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMutConfig;

    for (l = 0; l < numOfMut; l++)
    {
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(1)
        {
            k++;
            week = rand() % numOfWeeksConfig; /*eksamensperiode længde, standard er 8*/
            day = rand() % 5;                 /*antal dage på en uge*/
            room = rand() % numOfRoomsConfig; /*antal rum, standard er 10*/

            gWeek = rand() % numOfWeeksConfig;
            gDay = rand() % 5;
            gRoom = rand() % numOfRoomsConfig;

            xamLenght = skema_data[skema][week][day][room][0].days; /*varigheden af eksamen*/
            gXamLenght = skema_data[skema][gWeek][gDay][gRoom][0].days; /*varighed af den flyttede eksamenslængde*/
            /*følgende if-else kæden finder ud af om eksamnen bliver placeret over en weekend eller ej*/
            if (day <= 2 && gDay <= 2)
            {
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week][day+xamLenght][room][0].year != 0 && 
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week][day+xamLenght-1][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week][day+xamLenght-1][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0)
                    {   /*double for-loop indsætter al data i den næste position,*/
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                            }
                        }
                        break;
                    }
                    else if (skema_data[skema][gWeek][gDay][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay+gXamLenght][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay][gRoom][0].classname == skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    skema_data[skema][gWeek][gDay][gRoom][0].year == skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];

                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay <= 2)
            {
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week+1][day-xamLenght][room][0].year != 0 &&
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week+1][day-xamLenght][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week+1][day-xamLenght][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (day + j <= 4)
                                {
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                                else{
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                            }
                        }
                        break;
                    }
                    else if (skema_data[skema][gWeek][gDay][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay+gXamLenght][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay][gRoom][0].classname == skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].classname &&
                    skema_data[skema][gWeek][gDay][gRoom][0].year == skema_data[skema][gWeek][gDay+gXamLenght-1][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (day + j <= 4)
                                {
                                    temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    skema_data[skema][week+1][day+j-5][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day <= 2 && gDay > 2)
            {
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week][day+xamLenght][room][0].year != 0 && 
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week][day+xamLenght][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week][day+xamLenght][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4)
                                {
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                                else{
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }

                            }
                        }
                        break;
                    }
                    else if (skema_data[skema][gWeek][gDay][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay][gRoom][0].classname == skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                    skema_data[skema][gWeek][gDay][gRoom][0].year == skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4)
                                {
                                    temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                }
                                else{
                                    temp_data[i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDay > 2)
            {
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week+1][day-xamLenght][room][0].year != 0 &&
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week+1][day-xamLenght][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week+1][day-xamLenght][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year == 0)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4 && day + j <= 4)
                                {
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                                else if (gDay + j <= 4 && day + j > 4)
                                {
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                                else if (gDay + j > 4 && day + j <= 4)
                                {
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                                else{
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*numOfRoomsConfig);
                                }
                            }
                        }
                        break;
                    }
                    else if (skema_data[skema][gWeek][gDay][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year != 0 && 
                    skema_data[skema][gWeek][gDay][gRoom][0].classname == skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].classname &&
                    skema_data[skema][gWeek][gDay][gRoom][0].year == skema_data[skema][gWeek+1][gDay-gXamLenght][gRoom][0].year)
                    {
                        for (i = 0; i < numOfRoomsConfig; i++)
                        {
                            for (j = 0; j < xamLenght; j++)
                            {
                                if (gDay + j <= 4 && day + j <= 4)
                                {
                                    temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j <= 4 && day + j > 4)
                                {
                                    temp_data[i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    skema_data[skema][week+1][day+j-5][room][i] = skema_data[skema][gWeek][gDay+j][gRoom][i];
                                }
                                else if (gDay + j > 4 && day + j <= 4)
                                {
                                    temp_data[i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    skema_data[skema][week][day+j][room][i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
                                }
                                else{
                                    temp_data[i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    skema_data[skema][week+1][day+j-5][room][i] = skema_data[skema][gWeek+1][gDay+j-5][gRoom][i];
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
