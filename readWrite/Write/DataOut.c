
void WriteDataToFile(int data[], FILE *fptr);
void ResultDataOut(int data[]) {
    char temp_char;
    FILE *fptr;

      
    if ((fptr=fopen("schema_data.txt","r"))==NULL){
        printf("Data not existing creating new.\n");
        WriteDataToFile(data,fptr);
    }
    else {

        printf("!Data existing!\n Do you want to create new? [Y]es or [N]o: ");
        do{
            scanf("%c", &temp_char);
            printf("\n");
            if(temp_char == 'N' || temp_char == 'n'){
                printf("exitting.\n");
                assert(0);
            }
            else if(temp_char == 'Y' || temp_char == 'y') {
                WriteDataToFile(data,fptr);
                break;
            }
            else {
                printf("Please indput either Y or N for [Y]es or [N]o :");
            }
        }while(1);

    }
    
    fclose(fptr);
}
void WriteDataToFile(int data[], FILE *fptr) {
    int i;
    fptr = fopen("schema_data.txt", "w");
    fprintf(fptr,"Run  | Data\n");
    
    for(i = 0; i < RUNS; i++)
    {
        fprintf(fptr, "%3i %5i\n",i, data[i]);
    } 
}