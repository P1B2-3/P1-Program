#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENERATION_SIZE 300

typedef struct{
    int fitness,
        position,
        saved;
} fitness_struct;

void moving(Exam_block_t *****child, Exam_block_t *****parent, int genome, int p1_day, int p1_week, int p2_week, int p2_day);
void doCrossover(int genome_p1,int genome_p2, Exam_block_t *****parent, Exam_block_t *****child);
void makeCrossover(int genome_p1, int genome_p2, Exam_block_t *****parent, Exam_block_t *****child_1, Exam_block_t *****child_2);
void insert(int childPos, Exam_block_t *****genome);
void makeChild(int parent1Pos, int parent2pos, int childPos1,int childPos2, Exam_block_t *****genome);
void child(int numOfParents, int numOfChildren, fitness_struct fit[], Exam_block_t *****genome);
void nextGen(int breed, int survivors, fitness_struct fit[], Exam_block_t *****genome);
void kill(int position, Exam_block_t *****genome);
void fill(Exam_block_t *****dest, Exam_block_t *****src);
float select();
int sortFitness (const void *a, const void *b);
void selection(Exam_block_t *****genome_data);


void selection(Exam_block_t *****genome_data){
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

    mutationRate = getConfig("a.mutationRate");

    /*ændrer procentsats til brøk, f.eks. 50% -> 1/2. Tager dog kun heltalsbrøk*/
    savePerGen =  100 / (100 - getConfig("a.killPerGeneration"));
    breedPerGen = 100 / getConfig("a.breedPerGeneration");
    fill(temp_genome, genome_data);

    for (i = 0; i < GENERATION_SIZE; i++)
    {
        tempFitness[i].fitness = genome_data[i][0][0][0][0].fitness;
        tempFitness[i].position = i;
        tempFitness[i].saved = false;
    }

    qsort(tempFitness, GENERATION_SIZE, sizeof(int), sortFitness);

    for (i = 0; i < GENERATION_SIZE; i++)
    {
        totFitness += tempFitness[i].fitness;
    }

    while (survivors < GENERATION_SIZE / savePerGen)
    {
        for (i = 0; i < GENERATION_SIZE; i++)
        {
            survivalChance[i] = (((float)tempFitness[i].fitness / (float)totFitness) * 100.00);
        }
        
        selected = select();

        chosen = 0;
        
        for ( i = GENERATION_SIZE; i > 0; i++)
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
        if (tempFitness[i].saved == false){
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

float select(){
    int interger;
    time_t t;

    srand((unsigned) time(&t)); /*skal fjernes hvis man kun behøver et seed i main*/

    interger = rand() % 10000;

    return ((float)interger / 100);
}

void fill(Exam_block_t *****dest, Exam_block_t *****src){
    int i, k, l, m, n,numOfRooms,numOfWeeks,numOfExams;

    numOfRooms = getConfig("s.numberOfRooms");
    numOfWeeks = getConfig("s.numberOfWeeks");
    numOfExams = getConfig("s.numberOfExams");
    
    for (i = 0; i < GENERATION_SIZE; i++) {
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

void kill(int position, Exam_block_t *****genome){
    int k, l, m, n,
        numOfRooms,
        numOfWeeks,
        numOfExams;
    Exam_block_t *zero;

    /*laver et struct som er fyldt med 0*/
    zero = (Exam_block_t *)calloc(1,sizeof(Exam_block_t));

    numOfRooms = getConfig("s.numberOfRooms");
    numOfWeeks = getConfig("s.numberOfWeeks");
    numOfExams = getConfig("s.numberOfExams");

    
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
    int i, j, k, l,
        totFitness;
    float parent1, parent2,
          selected1, selected2,
          breedingChance[GENERATION_SIZE];

    for (i = 0; i < numOfChildren; i++)
    {
        if (fit[i].fitness > 0){
            totFitness += fit[i].fitness;
        }
    }

    for (i = 0; i < numOfChildren; i++)
    {
        if (fit[i].fitness > 0){
            breedingChance[i] = (((float)fit[i].fitness / (float)totFitness) * 100);
        }
    }

    selected1 = select();
    selected2 = select();

    for (i = 0; i < numOfChildren; i++)
    {
        parent1 += breedingChance[i];
        if (parent1 > selected1)
        {
            for (k = 0; k < numOfChildren; k++)
            {
                parent2 += breedingChance[i];
                if (parent2 > selected2){
                    for (j = 0; j < numOfChildren; j++)
                    {
                        if (fit[j].fitness == 0)
                        {
                            for (l = j+1; l < numOfChildren; l++)
                            {
                                if (fit[l].fitness == 0){
                                    makeChild(fit[i].position, fit[k].position, fit[j].position, fit[l].position, genome);
                                    fit[j].fitness = -1;
                                    fit[l].fitness = -1;
                                    break;    
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}

void makeChild(int parent1Pos, int parent2pos, int child1Pos, int child2Pos, Exam_block_t *****genome){
    Exam_block_t *****child1_genome = Make_5D_Array(GENERATION_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);
    Exam_block_t *****child2_genome = Make_5D_Array(GENERATION_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);

    makeCrossover(parent1Pos, parent2pos, genome, child1_genome, child2_genome);

    insert(child1Pos, child1_genome);
    insert(child2Pos, child2_genome);

}

void insert(int childPos, Exam_block_t *****genome){
    int k, l, m, n,numOfRooms,numOfWeeks,numOfExams;

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
                    genome[childPos][k][l][m][n] = genome[0][k][l][m][n];
                }
            }
        }
    }
}

void makeCrossover(int genome_p1, int genome_p2, Exam_block_t *****parent, Exam_block_t *****child_1, Exam_block_t *****child_2){
    printf("start crossover\n");

    doCrossover(genome_p1, genome_p2, parent, child_1);

    doCrossover(genome_p2, genome_p1, parent, child_2);
    printf("stop crossover\n");
}

void doCrossover(int genome_p1,int genome_p2, Exam_block_t *****parent, Exam_block_t *****child){ /* pladser fra 1 og eksamner fra 2 */
    int i, j, k; /* parent1 */
    int h = 0, m = 0, l = 0; /* parent2*/

    for ( i = 0; i < WEEK_SIZE; i++){ /* finder pladsen */
        for ( j = 0; j < DAY_SIZE; j++){
            for ( k = 0; k < ROOM_SIZE; k++){
                if(parent[genome_p1][i][j][k][0].year != 0){
                    for ( ; h < WEEK_SIZE; h++){ /* finder pladsen */
                        for ( ; m < DAY_SIZE; m++){
                            for ( ; l < ROOM_SIZE; l++){
                                if(parent[genome_p2][h][m][l][0].year != 0){
                                    moving( child, parent, genome_p2, i, j, h, m);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void moving(Exam_block_t *****child, Exam_block_t *****parent, int genome, int p1_day, int p1_week, int p2_week, int p2_day){
    int j, k;

    for ( j = 0; j < ROOM_SIZE; j++){
        if(parent[genome][p2_week][p2_day][j][0].year != 0){
            for ( k = 0; k < 10; k++){ /* hvor mange der er på en dag */

                printf("%i\n", parent[genome][p2_week][p2_day][j][0].year);
                child[0][p1_week][p1_day][j][k].student      = parent[genome][p2_week][p2_day][j][k].student;
                child[0][p1_week][p1_day][j][k].subjects     = parent[genome][p2_week][p2_day][j][k].subjects;
                child[0][p1_week][p1_day][j][k].period_start = parent[genome][p2_week][p2_day][j][k].period_start;
                child[0][p1_week][p1_day][j][k].days         = parent[genome][p2_week][p2_day][j][k].days;
                child[0][p1_week][p1_day][j][k].year         = parent[genome][p2_week][p2_day][j][k].year;
                child[0][p1_week][p1_day][j][k].classname    = parent[genome][p2_week][p2_day][j][k].classname;
            }
        }
    }
}
