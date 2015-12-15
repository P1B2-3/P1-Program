int **Make_2D_Array_int( int day, int exam);
void Length(Exam_block_t *****schema_data, int **Day_Array);


int **Make_2D_Array_int( int day, int exam) { /* laver et temp-array som skal bruges til klasse-blokken */
    /* allocering af et 2 dimensionel array "dag, examen"*/
    int i;

    int **temp_int_array;
    temp_int_array = (int **) malloc(day*sizeof(int**));

        for (i = 0; i < day; i++) {
            temp_int_array[i] = (int *) malloc(exam*sizeof(int ));
        }

    if (temp_int_array == NULL) {
        printf("error not memori\n");
    }

    return temp_int_array;
}

void Length(Exam_block_t *****schema_data, int **Day_Array) {
    /* finder længden mellemde for skellige eksamner  */
    int i, j, k; /* indre loop */
    int l, m, n, h;
    int q, u, e;
    int t = 0, skip;
    int temp_day = 0, counter = 0;

    temp_t activeclass[24];
    
    for ( i = 0; i < 24; ++i) {
        
        activeclass[i].year = 0;
        activeclass[i].Class = '0';
        activeclass[i].t_or_f = true;
        activeclass[i].days = 0;
    }

    char current_class_letter;
    int current_class_no;

    for (l = 0; l < SCHEMA_SIZE; l++) {           /* genonom */
        counter = 0;
        for (m = 0; m < WEEK_SIZE; m++) {         /* week*/
            for (n = 0; n < DAY_SIZE; n++) {      /* day*/
                
                    for ( q = 0; q < 24; q++) {
                        if(activeclass[q].days > 0){
                            activeclass[q].days--;}

                    if(activeclass[q].days == 0) {
                        /*printf("derper\n");*/
                        activeclass[q].t_or_f = false;
                    }
                }

                for (h = 0; h < ROOM_SIZE; h++) { /* room*/

                   if (schema_data[l][m][n][h][0].year != 0) { /* 0 is default if there is no data */
                            current_class_no = schema_data[l][m][n][h][0].year;
                            current_class_letter = schema_data[l][m][n][h][0].classname;

                        for(e = 0; e < 24; e++) {
                            if(activeclass[e].Class != current_class_letter && activeclass[e].year != current_class_no) {
                                activeclass[t].Class = current_class_letter;
                                activeclass[t].year = current_class_no;
                                t++;
                            }
                        }

                        for (u = 0; u < 24; u++) {
                            skip = 0;

                            if( activeclass[u].t_or_f == false && activeclass[u].year == current_class_no && activeclass[u].Class == current_class_letter) {
        
                                j = (n + schema_data[l][m][n][h][0].days);
                                k = m + j/DAY_SIZE;
                                j %= DAY_SIZE;
                                
                                classfound:

                                if(skip != 1) {
                                    for (; k < WEEK_SIZE; k++) {        /* week */
                                        for (; j < DAY_SIZE; j++) {     /* day */
                                            temp_day++;                     /* tæller for dage mellem eksamner*/
                                            for (i = 0; i < ROOM_SIZE; i++) { /* room */
                                                if(schema_data[l][k][j][i][0].classname == current_class_letter 
                                                && schema_data[l][k][j][i][0].year      == current_class_no) {  

                                                    Day_Array[l][counter] = temp_day;
                                                    counter++;
                                                    /*printf("%i\n", counter);*/
                                                    temp_day = 0;
                                                    skip = 1;
                                                    j = k = 0;
                                                   /* printf("they see me rolling\n");*/
                                                    goto classfound;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                j =0; k =0; temp_day = 0;
                            }  
                        }  
                    }
                }
            }
        }
    }
    Day_Array[l][counter+1] = 1000;
}

