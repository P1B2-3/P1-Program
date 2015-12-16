/*---------------------------------------------------------------------------*/

int Crossover(Data_block_t *****parents, Data_block_t *****nextGen, int par1, int nextGenCount) {
/*Cross the individual with its mate, making a child.*/
    int point1, point2, tmpPoint, mating; 

    srand((unsigned) par1);
    mating = ((crossoverRate * 100) >= (rand() % 100));
    if (mating) {
    /*Shall it mate?*/
        par2 = rand() % GENERATION_HALF;
        /*Who shall it mate with?*/
        point1 = rand() % GENES_PER_CHROMOSOME;
        point2 = rand() % GENES_PER_CHROMOSOME;
        /*SHOULD THERE BE SOMETHING TO CONTROL CROSSOVER SIZE?*/

        if (point1 > point2) {
            tmpPoint = point1;
            point1 = point2;
            point2 = tmpPoint;
        }
        /*point1 greater than point2: they are switched.*/
        else if (point1 == point2) {
            return Crossover(parents, nextGen, par1, nextGenCount);
        }
        /*Both points are equal: tries again.*/

        nextGen[nextGenCount] = 
        MakeChild(parents[par1], parents[par2], point1, point2);
        nextGen[++nextGenCount] = 
        MakeChild(parents[par2], parents[par1], point1, point2);
    }
    else { 
        nextGen[nextGenCount] = parents[par1];
    }
    /*No mating: simply parse the unchanged solution.*/

    return mating;
}

/*---------------------------------------------------------------------------*/

int MakeChild(Data_block_t ****individual, Data_block_t ****mate, int point1, int point2) {
/*Cross the individual with its mate, making a child.*/
    int i; 
    int child;
    /*Kromosomerne er: tid, lokale, placering*/

    for (i = 0; i < point1; i++) {
        switch(i) {
            case 1: child.var1 = individual.var1; break;
            case 2: child.var2 = individual.var2; break;
            case 3: child.var3 = individual.var3; break;
            default: exit(EXIT_FAILURE);
        }
    }
    /*Child variables until the variable meant by point1 are assigned to 
    par1's (the individual's) varibles*/

    for (; i < point2; i++) {
        switch(i) {
            case 1: child.var1 = mate.var1; break;
            case 2: child.var2 = mate.var2; break;
            case 3: child.var3 = mate.var3; break;
            default: exit(EXIT_FAILURE);
        }
    }
    /*Child variables following the variable meant by point1 until point2 are 
    assigned to par2's (the mate's) varibles*/

    for (; i < GENES_PER_CHROMOSOME; i++) {
        switch(i) {
            case 1: child.var1 = individual.var1; break;
            case 2: child.var2 = individual.var2; break;
            case 3: child.var3 = individual.var3; break;
            default: exit(EXIT_FAILURE);
        }
    }
    /*Child variables following the variable meant by point1 are assigned to 
    par1's (the individual's) varibles*/

    return child;
}

/*---------------------------------------------------------------------------*/
