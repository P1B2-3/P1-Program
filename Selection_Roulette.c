#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENERATION_SIZE 300

typedef struct{
    int fitness,
        position,
        saved;
} fitness_struct;

int sortFitness (const void *a, const void *b);
float select();
void fill(Exam_block_t *****filled_data, Exam_block_t *****filling_data);
void kill(int position, Exam_block_t *****genome);
void nextGen(int breed, int survivors, fitness_struct fit[], Exam_block_t *****genome);
void child(int numOfParents, int numOfChildren, fitness_struct fit[], Exam_block_t *****genome);
void makeChild(int parentPos, int childPos, Exam_block_t *****genome);


void selection(Exam_block_t *****genome_data, int fitness[]){
    int i, 
        survivors = 0,
        chosen,
        mutationRate,
        savePerGen,
        breedPerGen,
        totFitness;
    float survivalChance[GENERATION_SIZE],
          selected;
    fitness_struct tempFitness[GENERATION_SIZE];      
    Exam_block_t *****temp_genome = Make_5D_Array(GENERATION_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);

    mutationRate = (int)getConfig("a.mutationRate");

    /*ændrer procentsats til brøk, f.eks. 50% -> 1/2. Tager dog kun heltalsbrøk*/
    savePerGen =  100 / (100 - (int)getConfig("a.killPerGeneration"));
    breedPerGen = 100 / (int)getConfig("a.breedPerGeneration");
    fill(temp_genome, genome_data);

    for (i = 0; i < GENERATION_SIZE; i++)
    {
        tempFitness[i].fitness = fitness[i];
        tempFitness[i].position = i;
        tempFitness[i].saved = false;
    }

    while (survivors < GENERATION_SIZE / savePerGen)
    {
        qsort(tempFitness, GENERATION_SIZE, sizeof(int), sortFitness);

        for (i = 0; i < GENERATION_SIZE; i++)
        {
            totFitness += tempFitness[i].fitness;
        }

        for (i = 0; i < GENERATION_SIZE; i++)
        {
            survivalChance[i] = (((float)tempFitness[i].fitness / (float)totFitness) * 100);
        }
        
        selected = select();

        for ( i = GENERATION_SIZE; i > 0; i--)
        {
            chosen += survivalChance[i];
            if (chosen > selected)
            {
                tempFitness[i].saved = true;
                survivors++;
                break;
            }
        }
    }

    for (i = 0; i < GENERATION_SIZE; i++)
    {
        if (tempFitness[i].saved = false){
            kill(tempFitness[i].position, temp_genome);
            tempFitness[i].fitness = 0;
        }
    }

    nextGen(breedPerGen, survivors, tempFitness, temp_genome);

    for (i = 0; i < GENERATION_SIZE; i++)
    {
        if (rand() % 100 < mutationRate){
            mutation(i, temp_genome);
        }
    }

    fill(genome_data, temp_genome);
    free(temp_genome);
}

int sortFitness (const void *a, const void *b){
    int f1 = ((fitness_struct *)a)->fitness;
    int f2 = ((fitness_struct *)b)->fitness;

    if (f1 < f2 || f2 == 0) {
        return 1;
    }
    else if (f1 > f2 || f1 == 0) {
        return -1;
    }
    else {
        return 0;
    }
}

float select(){
    int interger;
    time_t t;

    srand((unsigned) time(&t)); /*skal fjernes hvis man kun behøver et seed i main*/

    interger = rand() % 10000;

    return ((float)interger / 100);
}

void fill(Exam_block_t *****filled_data, Exam_block_t *****filling_data){
    int i, k, l, m, n;

    numOfRooms = (int)getConfig("s.numberOfRooms");
    numOfWeeks = (int)getConfig("s.numberOfWeeks");
    numOfExams = (int)getConfig("s.numberOfExams");
    
    for (i = 0; i < GENERATION_SIZE; i++) {
        for (k = 0; k < numOfWeeks; k++) {
            for (l = 0; l < 5; l++) {
                for (m = 0; m < numOfRooms; m++) {
                    for (n = 0; n < numOfExams; n++) {
                        filled_data[i][k][l][m][n] = filling_data[i][k][l][m][n];
                    }
                }
            }
        }
    }
}

void kill(int position, Exam_block_t *****genome){
    int k, l, m, n,
        numOfRooms,
        numOfWeeks,
        numOfExams;
    Exam_block_t *zero;

    /*laver et struct som er fyldt med 0*/
    zero = (Exam_block_t *)calloc(1,sizeof(Exam_block_t));

    numOfRooms = (int)getConfig("s.numberOfRooms");
    numOfWeeks = (int)getConfig("s.numberOfWeeks");
    numOfExams = (int)getConfig("s.numberOfExams");

    
    for (k = 0; k < numOfWeeks; k++) 
    {
        for (l = 0; l < 5; l++) 
        {
            for (m = 0; m < numOfRooms; m++) 
            {
                for (n = 0; n < numOfExams; n++) 
                {
                    genome[position][k][l][m][n] = zero[0];
                }
            }
        }
    }
    free(zero);
}

void nextGen(int breed, int survivors, fitness_struct fit[], Exam_block_t *****genome){
    int i,
        missing;

    missing = GENERATION_SIZE - survivors;

    while (missing < GENERATION_SIZE)
    {
        for (i = 0; i < GENERATION_SIZE; i++)
        {
            if (fit[i].saved == false)
            {
                child(breed, missing, fit, genome);
                fit[i].saved = true;
                break;
            }
        }
    }
}

void child(int numOfParents, int numOfChildren, fitness_struct fit[], Exam_block_t *****genome){
    int i, j,
        totFitness,
        chosen,
        selected,
        breedingChance[GENERATION_SIZE];

    for (i = 0; i < numOfChildren; i++)
    {
        totFitness += fit[i].fitness;
    }

    for (i = 0; i < numOfChildren; i++)
    {
        breedingChance[i] = (((float)fit[i].fitness / (float)totFitness) * 100);
    }

    for ( i = 0; i < numOfChildren; i++)
    {
        chosen += breedingChance[i];
        if (chosen > selected)
        {
            for (j = 0; j < numOfChildren; j++)
            {
                if (fit[j].fitness == 0)
                {
                    makeChild(fit[i].position, fit[j].position, genome);
                    fit[i].fitness = fit[fit[i].position].fitness;
                    break;
                }
            }
            break;
        }
    }
}

void makeChild(int parentPos, int childPos, Exam_block_t *****genome){
    int k, l, m, n;

    numOfRooms = (int)getConfig("s.numberOfRooms");
    numOfWeeks = (int)getConfig("s.numberOfWeeks");
    numOfExams = (int)getConfig("s.numberOfExams");

    for (k = 0; k < numOfWeeks; k++) 
    {
        for (l = 0; l < 5; l++) 
        {
            for (m = 0; m < numOfRooms; m++) 
            {
                for (n = 0; n < numOfExams; n++) 
                {
                    genome[childPos][k][l][m][n] = genome[parentPos][k][l][m][n];
                }
            }
        }
    }
}
