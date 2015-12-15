/*
The function getConfig(string) will search for, and read a given string's value
in the config.ini file.

example:
getConfig("s.numberOfStudents") - returns the value 24
*/



/*THIS VALUE SHOULD BE LARGER THAN THE AMOUNT
OF LINES IN THE CONFIG.INI FILE*/


/*STRUCT TO STORE EACH LINE'S STRING AND VALUE*/
struct line{
    char line[1024];
    int value;
};

int getConfig(char* in) {

    struct line line[LINES_TO_READ];
    int i;

    /*OPEN .INI FILE*/
    FILE *file;
    file = fopen("config.ini", "r");

    /*LOAD LINES INTO STRUCT*/
    for(i = 0; i <= LINES_TO_READ; i++){
        fscanf(file," %[a-zA-Z.] - %i" ,line[i].line, &line[i].value);
        fgetc(file);

        if (feof(file)){
            break;
        }
    }

    fclose(file);

    /*CHECK IF == INPUT*/
    for(i = 0; i <= LINES_TO_READ ; i++){
        if(strstr(in, line[i].line)){
            return line[i].value;
        }
    }

    /*IF THIS VALUE IS RETURNED, THE GIVEN STRING
    COULD NOT BE FOUND IN CONFIG.INI FILE.*/
    return 999;
}
