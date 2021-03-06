
void Moving(Exam_block_t *****child, Exam_block_t *****parent, int genome, int p1_day, int p1_week, int p2_week, int p2_day);
void DoCrossover(int genome_p1,int genome_p2, Exam_block_t *****parent, Exam_block_t *****child);
void MakeCrossover(int genome_p1, int genome_p2, Exam_block_t *****parent, Exam_block_t *****child_1, Exam_block_t *****child_2);
void Insert(int ChildPos, Exam_block_t ***** Child_genome, Exam_block_t *****genome);
void MakeChild(int parent1Pos, int parent2pos, int childPos1,int childPos2, Exam_block_t *****genome);
void child(int *numOfChildren, fitness_struct fit[], Exam_block_t *****genome);
void NextGen(int survivors, fitness_struct fit[], Exam_block_t *****genome);
void Kill(int position, Exam_block_t *****genome);
void Fill(Exam_block_t *****dest, Exam_block_t *****src);
float Select();
int SortFitness (const void *a, const void *b);
void Selection(Exam_block_t *****genome_data);



void Selection(Exam_block_t *****genome_data) {

    int i, 
        survivors = 0,
        mutationRate,
        savePerGen,
        totFitness;
    float survivalChance[SCHEMA_SIZE], chosen,
          Selected;
    fitness_struct tempFitness[SCHEMA_SIZE];      
    Exam_block_t *****temp_genome = Make_5D_Array(SCHEMA_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);

    mutationRate = GetConfig("a.mutationRate");

    /*ændrer procentsats til brøk, f.eks. 50% -> 1/2. Tager dog kun heltalsbrøk*/
    savePerGen =  100 / (100 - GetConfig("a.killPerGeneration"));

    Fill(temp_genome, genome_data);
/*    
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
 */   
    
    for (i = 0; i < SCHEMA_SIZE; i++)
    {
        if (rand() % 100 < mutationRate){
            
            Mutation(i, temp_genome);
        }
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

    int i, j, k, l,
        totFitness = 0;
    float parent1 = 0.0, parent2 = 0.0,
          Selected1, Selected2,
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

    Selected1 = Select();
    Selected2 = Select();

    for (i = 0; i < SCHEMA_SIZE; i++) {

        parent1 += breedingChance[i];
        
        if (parent1 > Selected1) {

            for (k = 0; k < SCHEMA_SIZE; k++) {

                parent2 += breedingChance[k];
                if (parent2 > Selected2){

                    for (j = 0; j < SCHEMA_SIZE; j++) {

                        if (fit[j].fitness == 0) {
                           
                            for (l = j+1; l < SCHEMA_SIZE; l++) {

                                if (fit[l].fitness == 0){

                                    MakeChild(fit[i].position, fit[k].position, fit[j].position, fit[l].position, genome);
									fit[j].fitness = -1;
									fit[j].saved   = true;
									fit[l].fitness = -1;
									fit[l].saved   = true;
									*numOfChildren = *numOfChildren+2;


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



void MakeChild(int parent1Pos, int parent2pos, int Child1Pos, int Child2Pos, Exam_block_t *****genome) {
    Exam_block_t *****Child1_genome = Make_5D_Array(SCHEMA_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);
    Exam_block_t *****Child2_genome = Make_5D_Array(SCHEMA_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);

    MakeCrossover(parent1Pos, parent2pos, genome, Child1_genome, Child2_genome);

    Insert(Child1Pos, Child1_genome,genome);
    Insert(Child2Pos, Child2_genome,genome);

    Free5DArray(Child1_genome);
    Free5DArray(Child2_genome);

}

void Insert(int ChildPos, Exam_block_t ***** Child_genome, Exam_block_t *****genome) {

    int k, l, m, n,numOfRooms,numOfWeeks,numOfExams;

    numOfRooms = (int)GetConfig("s.numberOfRooms");
    numOfWeeks = (int)GetConfig("s.numberOfWeeks");
    numOfExams = (int)GetConfig("s.numberOfExams");

    for (k = 0; k < numOfWeeks; k++)  {

        for (l = 0; l < 5; l++)  {

            for (m = 0; m < numOfRooms; m++)  {

                for (n = 0; n < numOfExams; n++)  {

                    genome[ChildPos][k][l][m][n] = Child_genome[0][k][l][m][n];
                }
            }
        }
    }
}

void MakeCrossover(int genome_p1, int genome_p2, Exam_block_t *****parent, Exam_block_t *****child_1, Exam_block_t *****child_2) {

    DoCrossover(genome_p1, genome_p2, parent, child_1);

    DoCrossover(genome_p2, genome_p1, parent, child_2);
}

void DoCrossover(int genome_p1,int genome_p2, Exam_block_t *****parent, Exam_block_t *****child) { /* pladser fra 1 og eksamner fra 2 */
	int p1_done = 0, p2_done = 0;

	int i,j,k;
	int h,m,l;


	while(h < WEEK_SIZE){

		if(p1_done != false){
			for (i = i ; i < WEEK_SIZE; i++) {

        		for (j = j ; j < DAY_SIZE; j++) {

            		for (k = 0; k < ROOM_SIZE; k++) {

		                if(parent[genome_p1][i][j][k][0].year != 0) {
		                	p1_done = true;
		                }
		                if(k == 9){
	                    	k = 0;
	                    	j++;
	                    	printf("reset k\n");
	                    }
		            }
		            if(j == 4){
                    	j = 0;
                    	i++;
                    	printf("reset j\n");
                    }
		        }
		    }
		}

		if(p2_done != false){

			for (h = h; h < WEEK_SIZE; h++) {

                for (m = m ; m < DAY_SIZE; m++) {

                    for (l = 0 ; l < ROOM_SIZE; l++) {

                        if(parent[genome_p2][h][m][l][0].year != 0) {
                        	p2_done = true;
                        }
                        if(l == 9){
	                    	l = 0;
	                    	m++;
	                    	printf("reset l\n");
	                    }
                    }
                    if(m == 4){
                    	m = 0;
                    	h++;
                    	printf("reset m\n");
                    }
                }
            }
		}

		if(p1_done == false && p2_done == false){
			Moving( child, parent, genome_p2, j, i, h, m);
			p1_done = p2_done = true;
		}
	}
}
void Moving(Exam_block_t *****child, Exam_block_t *****parent, int genome, int p1_day, int p1_week, int p2_week, int p2_day) {
    int j, k;

    for ( j = 0; j < ROOM_SIZE; j++) {
        if(parent[genome][p2_week][p2_day][j][0].year != 0) {
            for ( k = 0; k < 10; k++){ /* hvor mange der er på en dag */
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
