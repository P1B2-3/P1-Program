void Free5DArray(Exam_block_t *****schema_data) {
    int i,j,l,m;

    for(i = 0; i < SCHEMA_SIZE; i++) {
        if(schema_data[i] != NULL) {
            for(j = 0; j < WEEK_SIZE; j++) {
                if(schema_data[i][j] != NULL) {
                    for(l = 0; l < DAY_SIZE; l++) {
                        if(schema_data[i][j][l] != NULL) {
                            for(m = 0; m < ROOM_SIZE; m++) {
                                if(schema_data[i][j][l][m] != NULL) {
                                    free(schema_data[i][j][l][m]);
                                }
                            }
                            free(schema_data[i][j][l]);
                        }
                    }
                    free(schema_data[i][j]);
                }
            }
            free(schema_data[i]);
        }
    }
}

void Free2DArray_Ex(Exam_block_t **array, int day) {
    int i;
    for(i = 0; i < day; i++) {
        if(array[i] != NULL) {
            free(array[i]);
        }
    }
}
void Free2DArray_int(int **array, int day) {
    int i;
    for(i = 0; i < day; i++) {
        if(array[i] != NULL) {
            free(array[i]);
        }
    }
}

