#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mutation(int skema, Data_block_t *****skema_data)
{
    int numOfMut,
        i,
        week, gWeek,
        day, gDay,
        room, gRoom;
    time_t t;

    srand((unsigned) time(&t));

    /*varierer mængden af mutation baseret på en config (foreslået på ca. 9)*/
    numOfMut = rand() % numOfMutConfig;

    for (i = 0; i < numOfMut; i++){
        /*while-løkken sørger for at ændringerne er acceptable*/
        while(1){
            /*incDec bestemmer om ændringen øger eller sænker værdien*/
            /*hvilken eksamen der bliver ændret på*/
            week = rand() % 8;
            day = rand() % 5;
            room = rand() % 10;

            gWeek = rand() % 8;
            gDay = rand() % 5;
            gRoom = rand() % 10;

            days = skema_data[skema][week][day][room][0].days;
            gDays = skema_data[skema][gWeek][gDay][gRoom][0].days;
            if (day <= 2 && gDay <= 2){
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week][day+days][room][0].year != 0 && 
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week][day+days-1][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week][day+days-1][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek][gDay+gDays-1][gRoom][0].year == 0){
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 3; ++j)
                            {
                                skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                            }
                        }
                        break;
                    }
                }
            }
            else if (day > 2 && gDays <= 2){
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week+1][day-days][room][0].year != 0 &&
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week+1][day-days][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week+1][day-days][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek][gDay+gDays-1][gRoom][0].year == 0)
                    {
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 3; ++j)
                            {
                                if (day + j <= 4){
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                                }
                                else{
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*10);
                                }

                            }
                        }
                        break;
                    }
                }
            }
            else if (day <= 2 && gDays > 2){
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week][day+days][room][0].year != 0 && 
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week][day+days][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week][day+days][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek+1][gDay-gDays][gRoom][0].year == 0)
                    {
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 3; ++j)
                            {
                                if (gDay + j <= 4){
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                                }
                                else{
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                                }

                            }
                        }
                    }
                }

            }
            else if (day > 2 && gDays > 2){
                if (skema_data[skema][week][day][room][0].year != 0 && 
                    skema_data[skema][week+1][day-days][room][0].year != 0 &&
                    skema_data[skema][week][day][room][0].classname == skema_data[skema][week+1][day-days][room][0].classname &&
                    skema_data[skema][week][day][room][0].year == skema_data[skema][week+1][day-days][room][0].year)
                {
                    if (skema_data[skema][gWeek][gDay][gRoom][0].year == 0 && skema_data[skema][gWeek+1][gDay-gDays][gRoom][0].year == 0)
                    {
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 3; ++j)
                            {
                                if (gDay + j <= 4 && day + j <=4){
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                                }
                                else if (gDay + j <= 4 && day + j > 4){
                                    skema_data[skema][gWeek][gDay+j][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*10);
                                }
                                else if (gDay + j > 4 && day + j <= 4){
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week][day+j][room][i];
                                    memset(skema_data[skema][week][day+j][room], 0, sizeof(Data_block_t)*10);
                                }
                                else{
                                    skema_data[skema][gWeek+1][gDay+j-5][gRoom][i] = skema_data[skema][week+1][day+j-5][room][i];
                                    memset(skema_data[skema][week+1][day+j-5][room], 0, sizeof(Data_block_t)*10);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
