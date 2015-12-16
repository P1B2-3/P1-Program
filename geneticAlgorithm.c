/*
ENOUGH_FITNESS er ikke definerert? Skal den i config? Hvad bestemmer den?
Skriv Mutationsfunktionen om således den passer til den måde den bruges heri. 
QsortByFitness skal kunne sortere hovedarrayet. 

Tror ikke de forskellige srand skal bruges. Bare træk det i main, no?

crossoverType og crossoverSize benyttes ikke.

Prop configs i funktionerne som parametre.

Bør alle generation size osv laves til ikke-hardcodede værdier? Brug af malloc og lign.?*/
double killPerGeneration = 0.5;
int elitismAmount = 1;
/*From config.*/

void RankFitness(rankings_t rankArray[]);
void GeneticAlgorithm(Exam_block_t *****solutions);

/*int QsortByFitness (const void *a, const void *b);*/
int FindHighestFitness(rankings_t rankArray[]);
int FitnessLimit(int bestFitness);
void PopulateNextGen(Exam_block_t *****solutions, rankings_t rankArray[], int generationNo);
void KillPercentage(Exam_block_t *****solutions, Exam_block_t *****parents, rankings_t rankArray[], int generationNo);
void FillRest(Exam_block_t *****parents, Exam_block_t *****nextGen, rankings_t rankArray[], int generationNo, int nextGenCount);
void ReplaceSolution(Exam_block_t ****old, Exam_block_t ****new);

void GeneticAlgorithm(Exam_block_t *****solutions) {
    int i;
    rankings_t rankArray[GENERATION_SIZE];

    RankFitness(rankArray);
    for (i = 0; i < MAX_GENERATIONS; i++) {
        Fitness(solutions);
        /*qsort(solutions, GENERATION_SIZE, sizeof(int), QsortByFitness);*/
        if (FitnessLimit(FindHighestFitness(rankArray))){
            break;
        }
        PopulateNextGen(solutions, rankArray, i);
    }
}

void RankFitness(rankings_t rankArray[]) {
    int i, curr;
    for (i = 0, curr = 0; i < GENERATION_SIZE; i++) {
        rankArray[i].min = curr;
        curr += i;
        rankArray[i].max = curr;
    }
}

int FindHighestFitness(rankings_t rankArray[]) {
/*Only solution array was qsorted. To avoid having to sort the whole 
rankArray this function simply finds the best fitness.*/
int i, bestFitness = 0;

    for (i = 0; i < GENERATION_SIZE; i++) {
        if (rankArray[i].fitness > bestFitness) {
            bestFitness = rankArray[i].fitness;
        }
    }
    return bestFitness;
}


int FitnessLimit(int bestFitness) {
/*Check whether the top solution is good enough*/
    if (bestFitness < ENOUGH_FITNESS) {
        return 1;
    }
    return 0;
}


void PopulateNextGen(Exam_block_t *****solutions, rankings_t rankArray[], int generationNo) {
    int i, j, k, l, m, n;

    Exam_block_t *****nextGen;
    Exam_block_t *****parents;

    nextGen = (Exam_block_t *****) calloc(SCHEMA_SIZE,sizeof(Exam_block_t*****));
        if (nextGen == NULL)
            printf("Error not memory for nextGen(1)\n");      /* fejl kode, hvor at (x) er hvilken dimission der er fejl i */

        for (i = 0; i < SCHEMA_SIZE; i++) {
            nextGen[i] = (Exam_block_t ****) calloc(WEEK_SIZE,sizeof(Exam_block_t ***));
            if (nextGen == NULL)
                printf("Error not memory for nextGen(2)\n");

            for (j = 0; j < WEEK_SIZE; j++) {
                nextGen[i][j] = (Exam_block_t ***)calloc(DAY_SIZE,sizeof(Exam_block_t**));
                if (nextGen == NULL)
                    printf("Error not memory for nextGen(3)\n");

                for (k = 0; k < DAY_SIZE; k++) {
                    nextGen[i][j][k] = (Exam_block_t **)calloc(ROOM_SIZE,sizeof(Exam_block_t*));
                    if (nextGen == NULL)
                        printf("Error not memory for nextGen(4)\n");

                    for (n = 0; n < ROOM_SIZE; n++) {
                        nextGen[i][j][k][n] = (Exam_block_t *)calloc(EXAM_SIZE,sizeof(Exam_block_t));
                        if (nextGen == NULL)
                            printf("Error not memory for nextGen(5)\n");
                    }
                }
            }
        }
    
    parents = (Exam_block_t *****) calloc(SCHEMA_SIZE,sizeof(Exam_block_t*****));
        if (parents == NULL)
            printf("Error not memory for parents(1)\n");      /* fejl kode, hvor at (x) er hvilken dimission der er fejl i */

        for (i = 0; i < SCHEMA_SIZE; i++) {
            parents[i] = (Exam_block_t ****) calloc(WEEK_SIZE,sizeof(Exam_block_t ***));
            if (parents == NULL)
                printf("Error not memory for parents(2)\n");

            for (j = 0; j < WEEK_SIZE; j++) {
                parents[i][j] = (Exam_block_t ***)calloc(DAY_SIZE,sizeof(Exam_block_t**));
                if (parents == NULL)
                    printf("Error not memory for parents(3)\n");

                for (k = 0; k < DAY_SIZE; k++) {
                    parents[i][j][k] = (Exam_block_t **)calloc(ROOM_SIZE,sizeof(Exam_block_t*));
                    if (parents == NULL)
                        printf("Error not memory for parents(4)\n");

                    for (n = 0; n < ROOM_SIZE; n++) {
                        parents[i][j][k][n] = (Exam_block_t *)calloc(EXAM_SIZE,sizeof(Exam_block_t));
                        if (parents == NULL)
                            printf("Error not memory for parents(5)\n");
                    }
                }
            }
        }

    KillPercentage(solutions, parents, rankArray, generationNo);
    /*Put the surviving solution chromosomes into parent array*/
    
    FillRest(parents, nextGen, rankArray, generationNo, j);
    for (i = 0; i < GENERATION_SIZE; i++) {
        /*Mutation(int genome, Exam_block_t *****genome_data);*/ /*<------- ATTENTION!!!!!!!!!!1!!*/
    }

    /*Replace the chromosomes in each solution in each generation.
    At this time there are 300 solutions per generation. Each solution
    contains 8 weeks, that each contain 5 days, that each contain 10 
    rooms. Every single room contains a maximum of 10 filled hours.*/
    for (i = elitismAmount, j = 0; i < GENERATION_SIZE; i++, j++) {
        for (k = 0; k < AMOUNT_OF_WEEKS; k++) {
            for (l = 0; l < AMOUNT_OF_DAYS; l++) {
                for (m = 0; m < AMOUNT_OF_ROOMS; m++) {
                    for (n = 0; n < AMOUNT_OF_HOURS; n++) {
                        solutions[i][k][l][m][n] = nextGen[i][k][l][m][n]; 
                    }
                }
            }
        }

    }
    /*As many individuals, as have been noted in config, 
    stay unchanged in the array.*/
}

/*---------------------------------------------------------------------------*/

void KillPercentage(Exam_block_t *****solutions, Exam_block_t *****parents, rankings_t rankArray[], int generationNo) {
    int tmp, i, j, k = 0, l, m, n, o, rand1, skip;
    int killAmount, survivingAmount;
    int survivors[(tmp >= GENERATION_SIZE/2)?(tmp):(0)]; 
    /*FUNGERER DETTE? KillPerGen er en double.*/
    
    
    tmp = killPerGeneration * GENERATION_SIZE;
    killAmount = (tmp != GENERATION_SIZE && tmp != 0) ? (tmp) : (0);

    tmp = GENERATION_SIZE - killAmount;
    survivingAmount = (tmp >= GENERATION_SIZE/2)?(tmp):(0);

    memset(survivors, (survivingAmount + 1), survivingAmount);
    /*ULOVLIGHEDER!!!! "ISO C90 forbids variable length array ‘survivors’"*/
    /*Der bliver ikke lagt noget over i survivors, så det du har her er et array fyldt med predeffinerede tegn, not good for buisness :P
      Find ud af hvad der skal være i survivors, og kom tilbage til denher :P*/
    
    /*NOGET MED MEMSET 999 ELLER LIGN, således den ikke skipper det nulte array*/

    /*killPerGeneration from config is used. 
    Maximally half the generation, otherwise the array could 
    overflow if crossover was being used*/

    srand((unsigned) generationNo);
    for (i = 0; i < killAmount; i++) {

        do {
            rand1 = rand() % rankArray[GENERATION_SIZE].max;
            /*The solution that has rand1 within its rank fitness will survive
            to build the next generation.*/
            for (j = 0; 
                rand1 > rankArray[j].min && 
                rand1 <= rankArray[j].max; 
                j++) {
            }
            /*Find the position of the selected solution.*/
            
            skip = 0;
            for (o = 0; o < i; o++) {
                if (survivors[o] == j) {
                    skip = 1;
                    break;
                }
            }
        } while (skip == 1);
        /*Repeat while rand1 is pointing towards a solution that has already survived to build next generation.*/
        survivors[i] = j;
        
        for (k = 0; k < AMOUNT_OF_WEEKS; k++){
            for (l = 0; l < AMOUNT_OF_DAYS; l++) {
                for (m = 0; m < AMOUNT_OF_ROOMS; m++) {
                    for (n = 0; n < AMOUNT_OF_HOURS; n++) {
                        parents[i][k][l][m][n] = solutions[j][k][l][m][n];
                    }
                }
            }
        }
    }
}


void FillRest(Exam_block_t *****parents, Exam_block_t *****nextGen, rankings_t rankArray[], int generationNo, int nextGenCount) {
    int i, rand1;

    srand((unsigned) generationNo);
    for (; nextGenCount < GENERATION_SIZE; nextGenCount++) {
        rand1 = rand() % rankArray[GENERATION_SIZE/2].max;
        /*The solution that has rand1 within its rank fitness will survive
        to build the next generation*/
        for (i = 0; 
            rand1 > rankArray[i].min && 
            rand1 <= rankArray[i].max; 
            i++) {
        }
        /*Find the position of the selected solution*/
        ReplaceSolution (nextGen[nextGenCount], parents[i]);
    }
}


void ReplaceSolution(Exam_block_t ****old, Exam_block_t ****new) {
int i, j, k, l;

    for (i = 0; i < AMOUNT_OF_WEEKS; i++){
        for (j = 0; j < AMOUNT_OF_DAYS; j++) {
            for (k = 0; k < AMOUNT_OF_ROOMS; k++) {
                for (l = 0; l < AMOUNT_OF_HOURS; l++) {
                    old[i][j][k][l] = new[i][j][k][l];
                }
            }
        }
    }
}
