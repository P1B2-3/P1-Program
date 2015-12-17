

void MakeChild(int parentPos, int ChildPos, Exam_block_t *****genome);
void child(int *numOfChildren, fitness_struct fit[], Exam_block_t *****genome);
void NextGen(int survivors, fitness_struct fit[], Exam_block_t *****genome);
void Kill(int position, Exam_block_t *****genome);
void Fill(Exam_block_t *****dest, Exam_block_t *****src);
float Select();
int SortFitness (const void *a, const void *b);
void Selection(Exam_block_t *****genome_data);



void Selection(Exam_block_t *****genome_data) {

    int i, k,n,p,q,
        survivors = 0,
        mutationRate,
        savePerGen,
        sum1 = 0, sum2 = 0,
        totFitness;
    float survivalChance[SCHEMA_SIZE], chosen,
          Selected;
    fitness_struct tempFitness[SCHEMA_SIZE];      
    Exam_block_t *****temp_genome = Make_5D_Array(SCHEMA_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);

    mutationRate = GetConfig("a.mutationRate");

    /*ændrer procentsats til brøk, f.eks. 50% -> 1/2. Tager dog kun heltalsbrøk*/
    savePerGen =  100 / (100 - GetConfig("a.killPerGeneration"));

    Fill(temp_genome, genome_data);
    
    for (i = 0; i < SCHEMA_SIZE; i++) {
		tempFitness[i].fitness  = genome_data[i][0][0][0][0].fitness;
		tempFitness[i].position = i;
		tempFitness[i].saved    = 0;
    }

    qsort(tempFitness, SCHEMA_SIZE, sizeof(fitness_struct), SortFitness);

    for (i = 0; i < SCHEMA_SIZE; i++) {
        totFitness += tempFitness[i].fitness;
    }

    while (survivors < SCHEMA_SIZE / savePerGen) {

        for (i = 0; i < SCHEMA_SIZE; i++) {
            survivalChance[i] = (((float)tempFitness[i].fitness / (float)totFitness) * 100.00);

        }

        Selected = Select();

        chosen = 0;

        for ( i = 0; i < SCHEMA_SIZE; i++) {
            chosen += survivalChance[i];
            if (chosen > Selected) {
                tempFitness[i].saved = 1;
                survivors++;
                break;
            }
        }
    }

    for (i = 0; i < SCHEMA_SIZE; i++)
    {
        if (tempFitness[i].saved == 0){
            tempFitness[i].fitness = 0;
        }
    }


    NextGen(survivors, tempFitness, temp_genome);
    
    
    for (i = 0; i < SCHEMA_SIZE; i++)
    {
        if (rand() % 100 < mutationRate){
            
            Mutation(i, temp_genome);
        }
    }

    for (i = 0; i < SCHEMA_SIZE; i++) {
        for(k = 0; WEEK_SIZE < 8; k++) {
            for(n = 0; DAY_SIZE < 5; n++) {
                for(p = 0; ROOM_SIZE < 10; p++) {
                    for(q = 0; EXAM_SIZE < 10; q++) {
                        sum1 += genome_data[i][k][n][p][q].year;
                        sum2 += temp_genome[i][k][n][p][q].year;
                    }
                }
            }
        }
    }
    if (sum1 != sum2)
    {
        return;
    }


    Fill(genome_data, temp_genome);

    Free5DArray(temp_genome);

}
        
int SortFitness (const void *a, const void *b){
    int f1 = ((fitness_struct *)a)->fitness;
    int f2 = ((fitness_struct *)b)->fitness;

    if (f1 < f2 || f2 == 0 || f2 < 0) {
        return 1;
    }
    else if (f1 > f2 || f1 == 0 || f1 < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

float Select(){
    int interger;

    interger = rand() % 10000;

    return ((float)interger / 100);
}


void Fill(Exam_block_t *****dest, Exam_block_t *****src) {

    int i, k, l, m, n,numOfRooms,numOfWeeks,numOfExams;

    numOfRooms = GetConfig("s.numberOfRooms");
    numOfWeeks = GetConfig("s.numberOfWeeks");
    numOfExams = GetConfig("s.numberOfExams");

    for (i = 0; i < SCHEMA_SIZE; i++) {
        for (k = 0; k < numOfWeeks; k++) {
            for (l = 0; l < 5; l++) {
                for (m = 0; m < numOfRooms; m++) {
                    for (n = 0; n < numOfExams; n++) {
                        dest[i][k][l][m][n] = src[i][k][l][m][n];
                    }
                }
            }
        }
    }
}

void NextGen(int survivors, fitness_struct fit[], Exam_block_t *****genome) {
    int missing;

    missing = SCHEMA_SIZE - survivors;
    while (missing < SCHEMA_SIZE)
    {
        child(&missing, fit, genome);
    }
}

void child(int *numOfChildren, fitness_struct fit[], Exam_block_t *****genome) {

    int i, k,
        totFitness = 0;
    float parent = 0.0,
          Selected,
          breedingChance[SCHEMA_SIZE];

    for (i = 0; i < SCHEMA_SIZE; i++)
    {   
        if (fit[i].fitness > 0) {

            totFitness += fit[i].fitness;
        }
    }

    for (i = 0; i < SCHEMA_SIZE; i++)
    { 
        
        if (fit[i].fitness > 0) {

            breedingChance[i] = (((float)fit[i].fitness / (float)totFitness) * 100);
            }
        else {
            breedingChance[i] = 0.0;
        }
    }

    Selected = Select();

    for (i = 0; i < SCHEMA_SIZE; i++) {

        parent += breedingChance[i];
        
        if (parent > Selected) {

            for (k = 0; k < SCHEMA_SIZE; k++) {

                if (fit[k].fitness == 0) {
                    MakeChild(fit[i].position, fit[k].position, genome);
					fit[k].fitness = -1;
					*numOfChildren = *numOfChildren+1;
                    break;    
                }
            }
            break;
        }
    }
}

void MakeChild(int parentPos, int ChildPos, Exam_block_t *****genome) {

    int k, l, m, n,numOfRooms,numOfWeeks,numOfExams;

    numOfRooms = (int)GetConfig("s.numberOfRooms");
    numOfWeeks = (int)GetConfig("s.numberOfWeeks");
    numOfExams = (int)GetConfig("s.numberOfExams");

    for (k = 0; k < numOfWeeks; k++)  {

        for (l = 0; l < 5; l++)  {

            for (m = 0; m < numOfRooms; m++)  {

                for (n = 0; n < numOfExams; n++)  {

                    genome[ChildPos][k][l][m][n] = genome[parentPos][k][l][m][n];
                }
            }
        }
    }
}
