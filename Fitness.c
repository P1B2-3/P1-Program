void CalcFitnessOneGeneration( Exam_block_t *****schema_data,  int **array) {
    int fitness = 0;
    int i, j, k, r, p;
    
for (i = 0; i < SCHEMA_SIZE; i++) {
        
        /* læser alle tal i arrayet ud fra r. */
        while (array[i][r] < 1000) { /* vi ved sætter ne stop blok ind i vores array, og da vi ved at der aldrig er 1000 dagen i en eksamens periode*/
            if (array[i][r] >= 2) {
                fitness++;
            }
        r++;
       }
       /* sammenligning om der er den samme klasse flere gange på dagen*/
    for (j = 0; j < WEEK_SIZE; j++) {
        for (k = 0; k < DAY_SIZE; k++) {
            for (p = 0; p < ROOM_SIZE; p++) {
                if (schema_data[i][j][k][p][0].classname != schema_data[i][j][k][k][0].classname && schema_data[i][j][k][k][0].year != schema_data[i][j][k][p][0].year) {
                    fitness++;
                    }
                }
            }
        }
    schema_data[i][0][0][0][0].fitness = fitness;
    fitness = 0;
    }
}
