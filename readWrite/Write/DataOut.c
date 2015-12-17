
void WriteDataToFile(int data[], FILE *fptr);
void ResultDataOut(int data[]) {
    char temp_char;
    FILE *fptr;

      
    if ((fptr=fopen("schema_data.txt","r"))==NULL){
        printf("Schema not existing creating new.\n");
        WriteToFile(schema_data,fptr);
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
                WriteToFile(schema_data,fptr);
                break;
            }
            else {
                printf("Please indput either Y or N for [Y]es or [N]o :");
            }
        }while(1);

    }
    
    fclose(fptr);
}
void WriteToFile(int data[], FILE *fptr) {
    int i;
    fptr = fopen("schema_data.txt", "w");
    fprintf(fptr,"data | run\n");
    
    for(i = 0; i < RUNS; i++)
    {
        fprintf(fptr, "%i,%i\n",data[i],i);
    } 
}