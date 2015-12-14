/*
ENOUGH_FITNESS er ikke definerert? Skal den i config? Hvad bestemmer den?
Skriv mutationsfunktionen om således den passer til den måde den bruges heri. 
QsortByFitness skal kunne sortere hovedarrayet. 

Tror ikke de forskellige srand skal bruges. Bare træk det i main, no?

crossoverType og crossoverSize benyttes ikke.

Prop configs i funktionerne som parametre.

Bør alle generation size osv laves til ikke-hardcodede værdier? Brug af malloc og lign.?

Hvor skal fitness proppes hen? Skal det i rankarray? Så skal jeg sortere array vha. rankarray: 
http://stackoverflow.com/questions/6076720/sorting-a-c-array-based-on-contents-of-another-array
http://stackoverflow.com/questions/10584894/sort-an-array-based-on-members-of-another-array-in-c
*/

#include <stdio.h>
#include <stdlib.h>
#define GENERATION_SIZE 300
#define GENERATION_HALF 150
#define MAX_GENERATIONS 1000
#define ENOUGH_FITNESS 666
#define AMOUNT_OF_WEEKS 6
#define AMOUNT_OF_DAYS 5
#define AMOUNT_OF_HOURS 8
#define AMOUNT_OF_ROOMS 10

int killPerGeneration = 0.5;
int elitismAmount = 1;
/*From config.*/

typedef struct {
    int max, 
        min,
        fitness;
} rankings;

typedef struct{ 
    int students, subjects;
/*    Data_Student_t  student;
    Data_Subject_t  subjects; */
    int lokale,
        period_start,
        year;
    char classname;
}Data_block_t;

void RankFitness(rankings rankArray[]);
void GeneticAlgorithm(Data_block_t *****solutions);
void Fitness(Data_block_t *****solutions);
int QsortByFitness (const void *a, const void *b);
int FindHighestFitness(rankings rankArray[]);
int FitnessLimit(int bestFitness);
void PopulateNextGen(Data_block_t *****solutions, rankings rankArray[], int generationNo);
void KillPercentage(Data_block_t *****solutions, Data_block_t *****parents, rankings rankArray[], int generationNo);
void FillRest(Data_block_t *****parents, Data_block_t *****nextGen, rankings rankArray[], int generationNo, int nextGenCount);
int Mutation(Data_block_t *****individual, int i);
void ReplaceSolution(Data_block_t ****old, Data_block_t ****new);


void GeneticAlgorithm(Data_block_t *****solutions) {
    int i;
    rankings rankArray[GENERATION_SIZE];

    RankFitness(rankArray);
    for (i = 0; i < MAX_GENERATIONS; i++) {
        Fitness(solutions);
        qsort(solutions, GENERATION_SIZE, sizeof(int), QsortByFitness);
        if (FitnessLimit(FindHighestFitness(rankArray))){
            break;
        }
        PopulateNextGen(solutions, rankArray, i);
    }
}

/*---------------------------------------------------------------------------*/

void RankFitness(rankings rankArray[]) {
    int i, curr;
    for (i = 0, curr = 0; i < GENERATION_SIZE; i++) {
        rankArray[i].min = curr;
        curr += i;
        rankArray[i].max = curr;
    }
}

/*---------------------------------------------------------------------------*/

void Fitness(Data_block_t *****solutions) {
/*Fill the array/struct with the fitness of the individuals.*/
}

/*---------------------------------------------------------------------------*/

int QsortByFitness (const void *a, const void *b) {
    int f1 = ((struct rankArray*)a)->fitness;
    int f2 = ((struct rankArray*)b)->fitness;

    if (f1 < f2) {
        return 1;
    }
    else if (f1 > f2) {
        return -1;
    }
    else {
        return 0;
        /*Lige nu er der bias for dem, som starter øverst på arrayet. 
        Vurderet til at være ok.*/
    }
}

/*GØR SÅLEDES DET SORTERER SOLUTIONS ARRAY VHA. HVAD DER STÅR I RANKARRAY.*/

/*---------------------------------------------------------------------------*/

int FindHighestFitness(rankings rankArray[]) {
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

/*---------------------------------------------------------------------------*/

int FitnessLimit(int bestFitness) {
/*Check whether the top solution is good enough*/
    if (bestFitness < ENOUGH_FITNESS) {
        return 1;
    }
    return 0;
}

/*---------------------------------------------------------------------------*/

void PopulateNextGen(Data_block_t *****solutions, rankings rankArray[], int generationNo) {
    int i, j, k, l, m, n;
    Data_block_t nextGen[GENERATION_SIZE], 
                 parents[GENERATION_HALF];

/*LAV MAYBE MALLOC FUNCTION HER!*/

    KillPercentage(solutions, parents, rankArray, generationNo);
    /*Put the surviving solution chromosomes into parent array*/
    
    FillRest(parents, nextGen, rankArray, generationNo, j);
    for (i = 0; i < GENERATION_SIZE; i++) {
        Mutation(nextGen, i);
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

void KillPercentage(Data_block_t *****solutions, Data_block_t *****parents, rankings rankArray[], int generationNo) {
    int killAmount = (killPerGeneration * GENERATION_SIZE) % (GENERATION_HALF + 1);
    int i, j, k = 0, l, m, n, o, rand1, 
        survivors[killAmount - GENERATION_SIZE], skip;
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

/*---------------------------------------------------------------------------*/

void FillRest(Data_block_t *****parents, Data_block_t *****nextGen, rankings rankArray[], int generationNo, int nextGenCount) {
    int i, rand1;

    srand((unsigned) generationNo);
    for (; nextGenCount < GENERATION_SIZE; nextGenCount++) {
        rand1 = rand() % rankArray[GENERATION_HALF].max;
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

/*---------------------------------------------------------------------------*/

int Mutation(Data_block_t *****individual, int i) {
/*Mutate the single individual. 
Change one (or more??) random part of a random gene.*/
    return individual;
}

/*---------------------------------------------------------------------------*/

void ReplaceSolution(Data_block_t ****old, Data_block_t ****new) {
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

/*---------------------------------------------------------------------------*/
