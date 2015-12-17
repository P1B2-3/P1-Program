
void WriteToFile(Exam_block_t *****schema_data, int schemaNr, FILE *fptr);
void ResultOut(Exam_block_t *****schema_data) {
    int i,b,c,d,k,totalFitness = 0,tempFitness = 0,schemaNr;
    char temp_char;
    FILE *fptr;
    
    for(i = 0; i < SCHEMA_SIZE; i++) {

        for(b = 0; b < WEEK_SIZE; b++) {
            for(c = 0; c < DAY_SIZE; c++) {
                for(d = 0; d < ROOM_SIZE; d++) {
                    for(k = 0; k < EXAM_SIZE; k++) {
                        tempFitness += schema_data[i][b][c][d][k].fitness;
                    }
                }
            }
        }

        if(tempFitness > totalFitness) {
            totalFitness = tempFitness;
            schemaNr = i;
        }
    }
      
    if ((fptr=fopen("best_schema.txt","r"))==NULL){
        printf("Schema not existing creating new.\n");
        WriteToFile(schema_data,schemaNr,fptr);
    }
    
    else {

        printf("!Schema existing!\n Do you want to create new? [Y]es or [N]o: ");
        do{
            scanf("%c", &temp_char);
            printf("\n");
            if(temp_char == 'N' || temp_char == 'n'){
                printf("exitting.\n");
                assert(0);
            }
            else if(temp_char == 'Y' || temp_char == 'y') {
                WriteToFile(schema_data,schemaNr,fptr);
                break;
            }
            else {
                printf("Please indput either Y or N for [Y]es or [N]o :");
            }
        }while(1);

    }
    
    fclose(fptr);
}
void WriteToFile(Exam_block_t *****schema_data, int schemaNr, FILE *fptr) {
    int i,k,j,m;
    fptr = fopen("best_schema.txt", "w");
    fprintf(fptr,"Best solution.\n");
    
    for(k = 0; k < WEEK_SIZE; k++)
    {
        fprintf(fptr,"For week: %i\n",k);
        
        for(j = 0; j < DAY_SIZE; j++)
        {
            fprintf(fptr,"For day: %i\n",j);
            
            for(m = 0; m < ROOM_SIZE; m++)
            {
                fprintf(fptr,"For room: %i\n",m);
                
                for(i = 0; i < EXAM_SIZE; i++)
                {
                    fprintf(fptr, "For exam: %i",i);
                    fprintf(fptr, "Exam name: %s",schema_data[schemaNr][k][j][m][i].subjects.subject);
                    fprintf(fptr, "Class: %c.%i\n",schema_data[schemaNr][k][j][m][i].classname,schema_data[0][k][j][m][i].year);
                    fprintf(fptr, "Student id: %i\n",schema_data[schemaNr][k][j][m][i].student.unikID);
                    fprintf(fptr, "Student name: %s %s\n\n",schema_data[schemaNr][k][j][m][i].student.name,schema_data[0][k][j][m][i].student.surname);
                    fprintf(fptr, "Teacher id: %i\n",schema_data[schemaNr][k][j][m][i].subjects.teacher.ID);
                    fprintf(fptr, "Teacher name: %s %s\n\n",schema_data[schemaNr][k][j][m][i].subjects.teacher.name,schema_data[0][k][j][m][i].subjects.teacher.surname);
                    fprintf(fptr, "Censor id: %i \n",schema_data[schemaNr][k][j][m][i].subjects.censor.ID);
                    fprintf(fptr, "Censor name: %s %s\n",schema_data[schemaNr][k][j][m][i].subjects.censor.name,schema_data[0][k][j][m][i].subjects.censor.surname);


                }
            }
        }
    } 
}