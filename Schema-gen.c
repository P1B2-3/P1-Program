
/* Skema generator */
void ClassGenerator(Class_t classdata[]);
void TeacherGenerator(Class_t classdata[]);
/* pre-Examblock */
Exam_block_t *****Make_5D_Array( int genom, int week, int day, int room, int exam);
Exam_block_t    **Make_2D_Array( int day, int exam);
int Examblock(Class_t classdata, int l, Exam_block_t **temp_class_block, int room);
void PreExamBlock(Class_t classdata[], Exam_block_t *****schema_data, Exam_block_t **temp_block, int class_no, int genom);

Exam_block_t *****MakeSchema(){

    Exam_block_t *****schema_data      =  Make_5D_Array(SCHEMA_SIZE, WEEK_SIZE, DAY_SIZE, ROOM_SIZE, EXAM_SIZE);  /* Exam_blocket med alle uger og timer */
    Exam_block_t    **temp_class_block =  Make_2D_Array(DAY_SIZE,EXAM_SIZE);                                      /* et array for dage og timer */
    Class_t     *classdata;
    classdata = (Class_t *) calloc(30 , sizeof(Class_t));
        if (classdata == NULL){
            printf("No free memory for class data\n");
            return (0);
        }

    ClassGenerator(classdata); 
    TeacherGenerator(classdata);

    PreExamBlock(classdata, schema_data,temp_class_block,24, SCHEMA_SIZE);
    Free2DArray_Ex(temp_class_block,DAY_SIZE);
    return schema_data;
}

Exam_block_t *****Make_5D_Array( int genom, int week, int day, int room, int exam){
    /* allocere nok data ud fra dim. laver et fem dimensionel array "Løsning -> week->day -> local -> timer." */
    int i, j, k, n;

    Exam_block_t *****schema_data;
    schema_data = (Exam_block_t *****) calloc(genom,sizeof(Exam_block_t*****));
        if (schema_data == NULL)
            printf("Error: Not enough memory for Make_5D_Array(1)\n");      /* fejl kode, hvor at (x) er hvilken dimission der er fejl i */

        for (i = 0; i < genom; i++) {
            schema_data[i] = (Exam_block_t ****) calloc(week,sizeof(Exam_block_t ***));
            if (schema_data == NULL)
                printf("Error: Not enough memory for Make_5D_Array(2)\n");

            for (j = 0; j < week; j++) {
                schema_data[i][j] = (Exam_block_t ***)calloc(day,sizeof(Exam_block_t**));
                if (schema_data == NULL)
                    printf("Error: Not enough memory for Make_5D_Array(3)\n");

                for (k = 0; k < day; k++) {
                    schema_data[i][j][k] = (Exam_block_t **)calloc(room,sizeof(Exam_block_t*));
                    if (schema_data == NULL)
                        printf("Error: Not enough memory for Make_5D_Array(4)\n");

                    for (n = 0; n < room; n++) {
                        schema_data[i][j][k][n] = (Exam_block_t *)calloc(exam,sizeof(Exam_block_t));
                        if (schema_data == NULL)
                            printf("Error: Not enough memory for Make_5D_Array(5)\n");
                    }
                }
            }
        }

    return schema_data;
}

Exam_block_t **Make_2D_Array( int day, int exam){ /* laver et temp-array som skal bruges til klasse-blokken */
    /* allocering af et 2 dimensionel array "dag, examen"*/
    int i;

    Exam_block_t **temp_class_block;
    temp_class_block = (Exam_block_t **) malloc(day*sizeof(Exam_block_t**));

        for (i = 0; i < day; i++) {
            temp_class_block[i] = (Exam_block_t *) malloc(exam*sizeof(Exam_block_t ));
        }

    if (temp_class_block == NULL){
        printf("Error: Not enough memory\n");
    }

    return temp_class_block;
}

int Examblock(Class_t classdata, int l, Exam_block_t **temp_class_block, int room){ 
    /* returner antal dage der er sat af */
    int i, g;
    int dag = 0, timer = 0, tid = 815, total_days;

    int amount_of_students = classdata.student_num;

    Exam_block_t *temp_elevblock;

    temp_elevblock = (Exam_block_t *)malloc(30*sizeof(Exam_block_t)); /* allocering af temp, som bruges til at ligge dataen over i */

    if (amount_of_students % 10 != 0){
        total_days = (amount_of_students / 10) + 1;
    }
    else{
        total_days = (amount_of_students / 10);
    }

    for(i = 0; i < amount_of_students; i++){                    /* elevere, eve test med print i */
        temp_elevblock[i].student   = classdata.students[i];  
        temp_elevblock[i].subjects  = classdata.subjects[l];                                 
        temp_elevblock[i].year      = classdata.year;                      
        temp_elevblock[i].classname = classdata.name;            
        temp_elevblock[i].days      = total_days;
    }
    for (g = 0; g < amount_of_students; ++g){
        if( timer % 10 == 0){ /* 10 = ud fra 45 mins, 08-16 */
            dag++;
            timer = 0;
        }

        if(tid > 1615 || timer == 0){ /* udregning af af tid ( vi antager at eksamen vare 45 mins) */
            tid = 815;
        }
        tid += 45; /* 815 + 45*0*/
        if(60 <= tid - ((tid/100)*100)){
            tid += 40;
        }

        temp_elevblock[g].period_start = tid;

        temp_class_block[dag-1][timer] = temp_elevblock[g];
        timer++;
    }
    free(temp_elevblock);
    return dag- 1;
}

void PreExamBlock(Class_t classdata[], Exam_block_t *****schema_data, Exam_block_t **temp_block, int class_no, int genom){
    /* variabler som bruges i segmenterne */
    int days,
        day,
        week,
        room,
        move_phase,
        week_split; /* 0 er uden split af uger, 1 er med */
    /* variabler som bruges som tællere */
    int i,j,k,o,l;
    int runes = 0;

    for (k = 0; k < genom; k++){             /* Løsninger(hele Exam_blocker)*/

        for (i = 0; i < class_no; i++){     /* for skellige klasser */

            for (j = 0; j < 34; j++){       /* hvor mange eksamner der er */

                if(classdata[i].subjects[j].y_or_n == true && classdata[i].subjects[j].verbal){ /* kigger om de skal op til eksamen */

                    move_phase = true;
                    while(move_phase == true){ /* køre indtil at der bliver fundet en plads der er fri i data blokken */
                        runes++;
                        room = rand()% ROOM_SIZE;
                        day  = rand()% DAY_SIZE;
                        week = rand()% WEEK_SIZE;
                        days = Examblock(classdata[i],j,temp_block, room);/* return fra 1-> antal dage eksamen fylder */
                        if(schema_data[k][week][day][room][0].year == 0){ /* hvis lokalet er firt på dagen */

                            if( day + days > 4){  /* hvis at eksamne kan være i den nuværende uge, og ikke er sidste uge*/
                                if(week != 7){
                                    week += 1;
                                    day  -= days+1;
                                    if(schema_data[k][week][day][room][0].year == 0){ /* hvis at year er så er lokalet firt. da intet data */
                                        move_phase = false;
                                        week_split = true;
                                    }
                                }
                            }
                            else{ /* hvis at det ikke kan være i nuværende uge, så tag og træk nuværende fra antal af dage den tager*/
                                if(schema_data[k][week][day+days][room][0].year == 0){
                                move_phase = false;
                                week_split = false;
                                }
                            }
                    
                            if(runes > 10000000){
                                printf("Not enough space for examens\nrunes :%i\nAnother run could solve it\n", runes);
                                break;
                            }
                        }
                    }
                    /* flytning af temp til schema_data(altså det fulde array)-> Examblock */
                    for ( o = 0; o <= days; o++){
                        if(week_split == false){
                            for(l = 0; l < 10; l++){
                                schema_data[k][week][day+o][room][l] = temp_block[o][l];
                            }
                        }
                        else if(week_split == true){ /* fyldning af array hvis at arrayet er over 2 uger */

                            for(l = 0; l < 10; l++){
                                if (day + o <= 4){
                                    schema_data[k][week][day+o][room][l] = temp_block[o][l];
                                }
                                else{
                                    schema_data[k][week+1][day-o][room][l] = temp_block[o][l];
                                }
                            }
                        }
                    }    
                }
            }
        }
    }
}

void ClassGenerator(Class_t classdata[]) {

    foersteG TEMP_1G;
    andenG TEMP_2G; 
    tredjeG TEMP_3G;

    int i,
        unikID=0,
        temp_nr,
        k,
        tempP=0;

    /* Array med fornavne, og tallene til siden, er hvor mange navne der er talt op indtil da.*/
    const char *elev_for_navn[] = {"Mathias", "Mads", "Magnus", "Emil", "Jakob", 
                                   "Jonas", "Hector", "Oliver", "Ilyas", "Carl" ,          /*10*/
                                   "Ruben", "Benjamin", "Aksel", "Mikkel", "Alexander" ,
                                   "Martin", "Conrad", "Viktor", "Simon", "Christoffer" ,  /*20*/
                                   "Evander", "Sebastian", "Kristian", "Samuel", "Gustav", 
                                   "Elias", "Asbjorn", "Sabri", "Frederik", "Jeppe",       /*30*/
                                   "Nicolaj", "Eren", "Valde", "Lucas", "Wiktor" ,
                                   "David", "Malthe", "Phillip", "Robin", "Hjalte" ,       /*40*/
                                   "Klara", "Caroline", "Nicoline", "Sidelya", "Maj", 
                                   "Victoria", "Sofie", "Clara", "Line", "Fenja" ,         /*50*/
                                   "Marie", "Filippa", "Frida", "Leen", "Layal" ,
                                   "Asta", "Robin", "Silke", "Adelina", "Margrethe" ,      /*60*/
                                   "Kaya", "Olivia", "Stephanie", "Hanna", "Sigrid", 
                                   "Esther", "Maja", "Clara-Ann", "Signe", "Emina",        /*70*/
                                   "Ida", "Muniba", "Thea", "Maria", "Emilie", 
                                   "Vera", "Sarah", "Gro", "Nicosia", "Gry" ,              /*80*/
                                   "Isabella", "Laura", "Mia", "Philippa", "Zeynep", 
                                   "Lia", "Celina", "Mille", "Eva", "Ditte" ,              /*90*/
                                   "Sara", "Elisabeth", "Louise", "Cecilie","Jonas",
                                   "Tosh","Maria","David","Lasse","Naja","Philip",         /*100*/
                                   "Ruben","Joakim","Palle","Jonathan","Matias",
                                   "Thor","Odin","Frej","Frida","Bente",                   /*110*/
                                   "Jens","Osama","Muhammed","Grant","Anne",
                                   "Anna","Falke","Natasha","Dorte","Lisa",                /*120*/
                                   "Lise","Camilla","Julian","Andreas","Anton",
                                   "Anders","Magnus","Frey","Connor","Marvin",             /*130*/
                                   "Octavian","Andreas","Ludvig","Rohan","Noah",
                                   "Asmus","Jacob","Marcus","Patrick","Mads-Emil",         /*140*/
                                   "Pelle","Markus","Vincent","Anas","Matt",
                                   "Albert","Hemen","Andreas","Thobias","Otto",            /*150*/
                                   "Malthe","Seier","Gabriel","Asger","Loke",  
                                   "Jakob","Rasmus","Frida","Gro","Victoria",              /*160*/
                                   "Melda","Gry","Sofia","Mulle","Emma",
                                   "Amanda","Laura","Melissa","Emilie","Sara",             /*170*/
                                   "Bryndhilda","Aase","Fine","Tine","Tina",               
                                   "Filte","Tilte","Sine","Tryne","Lars",                  /*180*/
                                   "Troels","Stine"};                 
                            
    /*Array med efternavne, tallene til siden gælder som det samme som ovenfor*/
    const char *elev_efternavn[] = {"Waterbuck", "Gnu", "Larsen", "Jensen", "Jensen", 
                             "Nielsen", "Nielsen", "Jensen", "Jensen", "Nielsen",           /*10*/
                             "Mennsink", "Rodensen", "Soernesen","Frederiksen", "Moeller" ,
                             "Flak", "Bonderup", "Kjaer","Pedersen", "Nybo",                /*20*/
                             "Madsen", "Tomsen", "Holmsgaard", "Andersen" ,"Soehus",
                             "Apple", "Engesgaard" ,"Bisgaard", "Andersen", "Rossen",       /*30*/
                             "Loekke", "Poulesen", "Mathiasen" ,"Gunder", "Guldborg", 
                             "Mikkelsen", "Schroeder", "Brandt", "Kvist", "Bergh" ,         /*40*/
                             "Vraa", "Krog", "Bach" ,"Mogensen", "Vinter" ,
                             "Winter" ,"Moelgaard", "Vium", "Rask", "Husin",                /*50*/
                             "Iversen", "Larsen", "Tovgaard", "Elkaaer", "Staal", 
                             "Iversen", "Asp", "Bertelsen", "Bunkegaard", "Bacbeth" ,       /*60*/
                             "Heindoff", "Dofensmirtch", "Busk", "Bush", "Proeksen", 
                             "Nielsen", "Bassam", "Oestergaard", "Alfter", "Kefil",         /*70*/
                             "Luttah", "Luder", "Holst", "Roemmer", "Rasmussen" ,
                             "Joernsen", "Pedersen", "Valback", "Maddesen", "Mathiasen",    /*80*/
                             "Burnsen", "Hardmann", "Sofie", "Bentsen", "Kirk" ,
                             "Johannesen", "Mallerup", "Skoet", "Falk", "Falck" ,           /*90*/
                             "Jacobsen", "Majer", "Lassen", "Vinkler", "Abgardi" ,
                             "Tomsen", "Rasmussen", "Tybo", "Henriksen", "Brandtoft",       /*100*/
                             "Slot", "Pind", "Krose", "Loekke", "Lykke" ,
                             "Holm", "Hitler", "Kraeft", "Stalin", "Gardaffi",              /*110*/
                             "Hammer", "Husien", "Kusk", "Noer", "Ahmmed", 
                             "Nuur","Troelsen","Finduersen","Grundvig","Bang",              /*120*/
                             "Vangsen","Krig","Aabenraa","Vejgaard","Klausen",
                             "Sirut","Vindrue","Babera","Odinssoen","Vandre",               /*130*/
                             "Noeremark","Johansen","Holst","Thomsen","Christiansen",
                             "Haslund","Bøndergaard","Thillemann","Flensborg","Thorgersen", /*140*/
                             "Haxvig","Petersen","Krause-Kjaer","Baagoee","Brams",
                             "Gydesen","Fuglesang","Købsted","Nygaard","Kyhn",              /*150*/
                             "Hem","Pesic","Enghaven","Caspersen","Ostenfeld",
                             "Hansen","Almind","Jendal","Ortmann","Aardestrup",             /*160*/
                             "Kirkby","Bargsteen","Dountsen","Bresson","Gjoederum",
                             "Roegen","Mortensen","Sillesen","Brobak","Joergensen",         /*170*/
                             "staermose","Breum","Ibsen","Thomsen","Juul-Nyholm",
                             "Vive","Karkov","Lindberg","Golobvanv","Gruberg",              /*180*/
                             "Ekici","Dahl","John","Klitgaard","Rask",
                             "Grosen","Umnus","Jensen","Larsen","Larsen",                   /*190*/
                             "Madsen","Schou","Frisgaard","Froekjaer","Soernesen",
                             "Olsen","Randers","Sommer","Vergerakis","Brorholt",            /*200*/
                             "Gadegaard","Jhaf","Gundersen","Hermannson","Simonsen",
                             "Thomsen","Hansen","Thomsen","Nash","Pedersen",                /*210*/
                             "Madsen","Pihi","Moellnitz","Larsen","Hald",
                             "Nielsen","Nielsen","Kristiansen","Elgaard","Larsen",          /*220*/
                             "Ferslev","Christensen","Vinter","Larsen","Jensen",
                             "Nielsen","Jensen","Madsen","Larsen","Jensen",                 /*230*/
                             "Magnusen","Jensen","Rasmussen","Weirsoee"};
                                
    

    /*De følgende "for" løkker skriver ind i structsne for at få tilfældige eksamener til at fremgå for de forskellige klasser*/
    /*3g*/
    
    for(i = 1; i < 81; i++) {

        randA3g: temp_nr = rand() % 13;
        if(temp_nr == 0) {
            if(TEMP_3G.AMk != 1) {
               TEMP_3G.AMk = 1;
            }else {
                /*Der blvier brug goto her i vores funktion for at sørger for at en eksamen ikke
                  kørt ind 2 gange*/
                goto randA3g;
            }
        }else if(temp_nr == 1) {
            if(TEMP_3G.AMm != 1) {
                TEMP_3G.AMm = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 2) {
            if(TEMP_3G.ASm != 1) {
                TEMP_3G.ASm = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 3) {
            if(TEMP_3G.AMd != 1) {
                TEMP_3G.AMd = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 4) {
            if(TEMP_3G.ASd != 1) {
                TEMP_3G.ASd = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 5) {
            if(TEMP_3G.AMki != 1) {
                TEMP_3G.AMki = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 6) {
            if(TEMP_3G.AMf != 1) {
                TEMP_3G.AMf = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 7) {
            if( TEMP_3G.ASf != 1) {
                TEMP_3G.ASf = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 8) {
            if(TEMP_3G.AMe != 1) {
                TEMP_3G.AMe = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 9) {
            if(TEMP_3G.ASe != 1) {
                TEMP_3G.ASe = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 10) {
            if(TEMP_3G.ASk != 1) {
                TEMP_3G.ASk = 1;
            }else {
                goto randA3g;
            }
        }else if(temp_nr == 11) {
            if(TEMP_3G.AMt != 1) {
                TEMP_3G.AMt = 1;
            }else {
                goto randA3g;
            }
        }else {
            if(TEMP_3G.AMbi != 1) {
                TEMP_3G.AMbi = 1;
            }else
                goto randA3g;
        }
        if(i == 10) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }else if(i == 20) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;
        }else if(i == 30) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;
        }else if(i == 40) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }else if(i == 50) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }else if(i == 60) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }else if(i == 70) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }else if(i== 80) {
            tempP++;
            if(TEMP_3G.AMm) {
                classdata[tempP].subjects[0].y_or_n = true;
            }if(TEMP_3G.ASm) {
                classdata[tempP].subjects[1].y_or_n = true;
            }if(TEMP_3G.AMd) {
                classdata[tempP].subjects[2].y_or_n = true;
            }if(TEMP_3G.ASd) {
                classdata[tempP].subjects[3].y_or_n = true;
            }if(TEMP_3G.AMf) {
                classdata[tempP].subjects[4].y_or_n = true;
            }if(TEMP_3G.ASf) {
                classdata[tempP].subjects[5].y_or_n = true;
            }if(TEMP_3G.AMe) {
                classdata[tempP].subjects[6].y_or_n = true;
            }if(TEMP_3G.ASe) {
                classdata[tempP].subjects[7].y_or_n = true;
            }if(TEMP_3G.AMk) {
                classdata[tempP].subjects[8].y_or_n = true;
            }if(TEMP_3G.ASk) {
                classdata[tempP].subjects[9].y_or_n = true;
            }if(TEMP_3G.AMt) {
                classdata[tempP].subjects[10].y_or_n = true; 
            }if(TEMP_3G.AMbi) {
                classdata[tempP].subjects[11].y_or_n = true;
            }if(TEMP_3G.AMki) {
                classdata[tempP].subjects[12].y_or_n = true;
            }
            TEMP_3G.AMk = 0;
            TEMP_3G.AMm = 0; 
            TEMP_3G.ASm = 0;
            TEMP_3G.AMd = 0;
            TEMP_3G.ASd = 0;
            TEMP_3G.AMki = 0;
            TEMP_3G.AMf = 0;
            TEMP_3G.ASf = 0;
            TEMP_3G.AMe = 0;
            TEMP_3G.ASe = 0;
            TEMP_3G.ASk = 0;
            TEMP_3G.AMt = 0;
            TEMP_3G.AMbi = 0;  
        }
    }
    /*2g*/
    for(i = 1; i < 33; i++) {


        randA2g:temp_nr = rand() % 14;
        if(temp_nr == 0 ) {
            if(TEMP_2G.BMm != 1) {
                TEMP_2G.BMm = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 1) {
            if(TEMP_2G.BSm != 1) {
                TEMP_2G.BSm = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 2) {
            if(TEMP_2G.BMt != 1) {
                TEMP_2G.BMt = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 3) {
            if(TEMP_2G.BMi != 1) {
                TEMP_2G.BMi = 1;
            }else { 
                goto randA2g;
            }
        }else if(temp_nr == 4) {
            if(TEMP_2G.BMs != 1) {
                TEMP_2G.BMs = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 5) {
            if(TEMP_2G.BMth != 1) {
               TEMP_2G.BMth = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 6) {
            if(TEMP_2G.BMb != 1) {
                TEMP_2G.BMb = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 7) {
            if(TEMP_2G.BMki != 1) {
                TEMP_2G.BMki = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 8) {
            if(TEMP_2G.BMf != 1) {
                TEMP_2G.BMf = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 9) {
            if(TEMP_2G.BSf != 1) {
                TEMP_2G.BSf = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 10) {
            if(TEMP_2G.BMe != 1) {
                TEMP_2G.BMe = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 11) {
            if(TEMP_2G.BSe != 1) {
                TEMP_2G.BSe = 1;
            }else {
                goto randA2g;
            }
        }else if(temp_nr == 12) {
            if(TEMP_2G.BMk != 1) {
                TEMP_2G.BMk = 1;
            }else {
                goto randA2g;
            }
        }else {
            if(TEMP_2G.BSk != 1) {
                TEMP_2G.BSk = 1;
            }else {
                goto randA2g;
            }
        }

        if(i == 4) {
            tempP++;
            if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 8) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 12) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 16) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 20) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 24) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 28) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }else if(i == 32) {
            tempP++;
             if(TEMP_2G.BMm) {
                classdata[tempP].subjects[13].y_or_n = true;
            }if(TEMP_2G.BSm) {
                classdata[tempP].subjects[14].y_or_n = true;
            }if(TEMP_2G.BMf) {
                classdata[tempP].subjects[15].y_or_n = true;
            }if(TEMP_2G.BSf) {
                classdata[tempP].subjects[16].y_or_n = true;
            }if(TEMP_2G.BMe) {
                classdata[tempP].subjects[17].y_or_n = true;
            }if(TEMP_2G.BSe) {
                classdata[tempP].subjects[18].y_or_n = true;
            }if(TEMP_2G.BMk) {
                classdata[tempP].subjects[19].y_or_n = true;
            }if(TEMP_2G.BSk) {
                classdata[tempP].subjects[20].y_or_n = true;
            }if(TEMP_2G.BMt) {
                classdata[tempP].subjects[21].y_or_n = true;
            }if(TEMP_2G.BMi) {
                classdata[tempP].subjects[22].y_or_n = true;
            }if(TEMP_2G.BMb) {
                classdata[tempP].subjects[23].y_or_n = true;
            }if(TEMP_2G.BMki) {
                classdata[tempP].subjects[24].y_or_n = true;
            }if(TEMP_2G.BMs) {
                classdata[tempP].subjects[25].y_or_n = true;
            }if(TEMP_2G.BMth) {
                classdata[tempP].subjects[26].y_or_n = true;
            }
            TEMP_2G.BMm = 0;
            TEMP_2G.BSm = 0;
            TEMP_2G.BMt = 0;
            TEMP_2G.BMi = 0;
            TEMP_2G.BMs = 0;
            TEMP_2G.BMth = 0;
            TEMP_2G.BMb = 0;
            TEMP_2G.BMki = 0;
            TEMP_2G.BMf = 0;
            TEMP_2G.BSf = 0;
            TEMP_2G.BMe = 0;
            TEMP_2G.BSe = 0;
            TEMP_2G.BMk = 0;
            TEMP_2G.BSk = 0;
        }
    }
    /*1g*/
    for(i = 1; i < 17; i++) {
        
        randA1g: temp_nr = rand() % 7;
        if(temp_nr == 0) { 
            if( TEMP_1G.CMki != 1) {
               TEMP_1G.CMki = 1;
            }else {
                goto randA1g;
            }
                    /*CMki*/
        }else if(temp_nr == 1) {
            if( TEMP_1G.CMp) {
                TEMP_1G.CMp = 1;
            }else {
                goto randA1g;
            }
                    /*CMp*/
        }else if(temp_nr == 2) {
            if( TEMP_1G.CMth != 1) {
                TEMP_1G.CMth = 1;
            }else {
                goto randA1g;
            }
                    /*CMth*/
        }else if(temp_nr == 3)  {
            if( TEMP_1G.CMps != 1) {
                TEMP_1G.CMps = 1;
            }else {
                goto randA1g;
            }
        }else if(temp_nr == 4) {
            if( TEMP_1G.CMb != 1) {
                TEMP_1G.CMb = 1;
            }else {
                goto randA1g;
            }
        }else if(temp_nr == 5) {
            if( TEMP_1G.CMs != 1) {
                TEMP_1G.CMs = 1;
            }else {
                goto randA1g;
            }
        }else {
            if( TEMP_1G.CMa != 1) {
                TEMP_1G.CMa = 1;
            }else {
                goto randA1g;
            }  
        }
        if(i == 2) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 4) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 6) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 8) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 10) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 12) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 14) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }else if(i == 16) {
            tempP++;
            if(TEMP_1G.CMp) {
                classdata[tempP].subjects[27].y_or_n = true;
            }if(TEMP_1G.CMb) {
                classdata[tempP].subjects[28].y_or_n = true;
            }if(TEMP_1G.CMki) {
                classdata[tempP].subjects[29].y_or_n = true;
            }if(TEMP_1G.CMs) {
                classdata[tempP].subjects[30].y_or_n = true;
            }if(TEMP_1G.CMth) {
                classdata[tempP].subjects[31].y_or_n = true;
            }if(TEMP_1G.CMps) {
                classdata[tempP].subjects[32].y_or_n = true;
            }if(TEMP_1G.CMa) {
                classdata[tempP].subjects[33].y_or_n = true;
            }
            TEMP_1G.CMki = 0;
            TEMP_1G.CMp = 0;
            TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0;
            TEMP_1G.CMb = 0;
            TEMP_1G.CMs = 0;
            TEMP_1G.CMa = 0;
        }
    }
    for(i=0;i<24;i++) {

        classdata[i].student_num = 26;
            /*Vi ved der er 9 klasser på hvert år*/
            if(i<=8) {
                classdata[i].year = 3;
            }
            else if(i > 8 && i<=16) {
                classdata[i].year = 2;
            }
            else {
                classdata[i].year = 1;
            }
            /*For hvert år skal der være klasser fra a til h*/
            classdata[i].name = 
                        ((i == 0 && classdata[i].year == 3)
                      || (i == 8  && classdata[i].year == 2)
                      || (i == 16 && classdata[i].year == 1))  ? 'A' :

                        ((i == 1  && classdata[i].year == 3)
                      || (i == 9  && classdata[i].year == 2)
                      || (i == 17 && classdata[i].year == 1))  ? 'B' :

                        ((i ==  2 && classdata[i].year == 3)
                      || (i == 10 && classdata[i].year == 2)
                      || (i == 18 && classdata[i].year == 1))  ? 'C' :

                        ((i ==  3 && classdata[i].year == 3)
                      || (i == 11 && classdata[i].year == 2)
                      || (i == 19 && classdata[i].year == 1))  ? 'D' :

                        ((i == 4  && classdata[i].year == 3)
                      || (i == 12 && classdata[i].year == 2)
                      || (i == 20 && classdata[i].year == 1))  ? 'E' :

                        ((i == 5  && classdata[i].year == 3)
                      || (i == 13 && classdata[i].year == 2)
                      || (i == 21 && classdata[i].year == 1))  ? 'F' :

                        ((i == 6  && classdata[i].year == 3)
                      || (i == 14 && classdata[i].year == 2)
                      || (i == 22 && classdata[i].year == 1)) ? 'G' : 'H';


        for(k = 1; k < 27; k++) {
            /*Genere elever yd fra klasser, der er 8 klaaser af 3 årgange, og i dette tilfælde er der 26 elever i hver klasse, dette giver 624 elver ialt.
              dette bliver der holdt styr på ved hjælp af unikID som er en tæller der tæller 1 op for hver elev. (og derfor er det nemmere at holde styr på.*/

            unikID++;

            classdata[i].students[k-1].unikID = unikID;
            
            strcpy(classdata[i].students[k-1].name,elev_for_navn[rand()%182]);
            strcpy(classdata[i].students[k-1].surname,elev_efternavn[rand()%234]);
            classdata[i].students[k-1].exam_number = k;
        } 
    }
}
/*Genere tilfældige lærere*/
void TeacherGenerator(Class_t classdata[]) {
    int i,j,unikID_teacher=0, unikID_censor=0;
    char examType[SIZE_OF_NAMES];
            /* Array med fornavne, og tallene til siden, er hvor mange navne der er talt op indtil da.*/
    const char *teacher_fornavn[] = {"Mathias", "Mads", "Magnus", "Emil", "Jakob", 
                                   "Jonas", "Hector", "Oliver", "Ilyas", "Carl" ,          /*10*/
                                   "Ruben", "Benjamin", "Aksel", "Mikkel", "Alexander" ,
                                   "Martin", "Conrad", "Viktor", "Simon", "Christoffer" ,  /*20*/
                                   "Evander", "Sebastian", "Kristian", "Samuel", "Gustav", 
                                   "Elias", "Asbjorn", "Sabri", "Frederik", "Jeppe",       /*30*/
                                   "Nicolaj", "Eren", "Valde", "Lucas", "Wiktor" ,
                                   "David", "Malthe", "Phillip", "Robin", "Hjalte" ,       /*40*/
                                   "Klara", "Caroline", "Nicoline", "Sidelya", "Maj", 
                                   "Victoria", "Sofie", "Clara", "Line", "Fenja" ,         /*50*/
                                   "Marie", "Filippa", "Frida", "Leen", "Layal" ,
                                   "Asta", "Robin", "Silke", "Adelina", "Margrethe" ,      /*60*/
                                   "Kaya", "Olivia", "Stephanie", "Hanna", "Sigrid", 
                                   "Esther", "Maja", "Clara-Ann", "Signe", "Emina",        /*70*/
                                   "Ida", "Muniba", "Thea", "Maria", "Emilie", 
                                   "Vera", "Sarah", "Gro", "Nicosia", "Gry" ,              /*80*/
                                   "Isabella", "Laura", "Mia", "Philippa", "Zeynep", 
                                   "Lia", "Celina", "Mille", "Eva", "Ditte" ,              /*90*/
                                   "Sara", "Elisabeth", "Louise", "Cecilie","Jonas",
                                   "Tosh","Maria","David","Lasse","Naja","Philip",         /*100*/
                                   "Ruben","Joakim","Palle","Jonathan","Matias",
                                   "Thor","Odin","Frej","Frida","Bente",                   /*110*/
                                   "Jens","Osama","Muhammed","Grant","Anne",
                                   "Anna","Falke","Natasha","Dorte","Lisa",                /*120*/
                                   "Lise","Camilla","Julian","Andreas","Anton",
                                   "Anders","Magnus","Frey","Connor","Marvin",             /*130*/
                                   "Octavian","Andreas","Ludvig","Rohan","Noah",
                                   "Asmus","Jacob","Marcus","Patrick","Mads-Emil",         /*140*/
                                   "Pelle","Markus","Vincent","Anas","Matt",
                                   "Albert","Hemen","Andreas","Thobias","Otto",            /*150*/
                                   "Malthe","Seier","Gabriel","Asger","Loke",  
                                   "Jakob","Rasmus","Frida","Gro","Victoria",              /*160*/
                                   "Melda","Gry","Sofia","Mulle","Emma",
                                   "Amanda","Laura","Melissa","Emilie","Sara",             /*170*/
                                   "Bryndhilda","Aase","Fine","Tine","Tina",               
                                   "Filte","Tilte","Sine","Tryne","Lars",                  /*180*/
                                   "Troels","Stine"};                 
                            
    /*Array med efternavne, tallene til siden gælder som det samme som ovenfor*/
    const char *teacher_efternavn[] = {"Waterbuck", "Gnu", "Larsen", "Jensen", "Jensen", 
                             "Nielsen", "Nielsen", "Jensen", "Jensen", "Nielsen",           /*10*/
                             "Mennsink", "Rodensen", "Soernesen","Frederiksen", "Moeller" ,
                             "Flak", "Bonderup", "Kjaer","Pedersen", "Nybo",                /*20*/
                             "Madsen", "Tomsen", "Holmsgaard", "Andersen" ,"Soehus",
                             "Apple", "Engesgaard" ,"Bisgaard", "Andersen", "Rossen",       /*30*/
                             "Loekke", "Poulesen", "Mathiasen" ,"Gunder", "Guldborg", 
                             "Mikkelsen", "Schroeder", "Brandt", "Kvist", "Bergh" ,         /*40*/
                             "Vraa", "Krog", "Bach" ,"Mogensen", "Vinter" ,
                             "Winter" ,"Moelgaard", "Vium", "Rask", "Husin",                /*50*/
                             "Iversen", "Larsen", "Tovgaard", "Elkaaer", "Staal", 
                             "Iversen", "Asp", "Bertelsen", "Bunkegaard", "Bacbeth" ,       /*60*/
                             "Heindoff", "Dofensmirtch", "Busk", "Bush", "Proeksen", 
                             "Nielsen", "Bassam", "Oestergaard", "Alfter", "Kefil",         /*70*/
                             "Luttah", "Luder", "Holst", "Roemmer", "Rasmussen" ,
                             "Joernsen", "Pedersen", "Valback", "Maddesen", "Mathiasen",    /*80*/
                             "Burnsen", "Hardmann", "Sofie", "Bentsen", "Kirk" ,
                             "Johannesen", "Mallerup", "Skoet", "Falk", "Falck" ,           /*90*/
                             "Jacobsen", "Majer", "Lassen", "Vinkler", "Abgardi" ,
                             "Tomsen", "Rasmussen", "Tybo", "Henriksen", "Brandtoft",       /*100*/
                             "Slot", "Pind", "Krose", "Loekke", "Lykke" ,
                             "Holm", "Hitler", "Kraeft", "Stalin", "Gardaffi",              /*110*/
                             "Hammer", "Husien", "Kusk", "Noer", "Ahmmed", 
                             "Nuur","Troelsen","Finduersen","Grundvig","Bang",              /*120*/
                             "Vangsen","Krig","Aabenraa","Vejgaard","Klausen",
                             "Sirut","Vindrue","Babera","Odinssoen","Vandre",               /*130*/
                             "Noeremark","Johansen","Holst","Thomsen","Christiansen",
                             "Haslund","Bøndergaard","Thillemann","Flensborg","Thorgersen", /*140*/
                             "Haxvig","Petersen","Krause-Kjaer","Baagoee","Brams",
                             "Gydesen","Fuglesang","Købsted","Nygaard","Kyhn",              /*150*/
                             "Hem","Pesic","Enghaven","Caspersen","Ostenfeld",
                             "Hansen","Almind","Jendal","Ortmann","Aardestrup",             /*160*/
                             "Kirkby","Bargsteen","Dountsen","Bresson","Gjoederum",
                             "Roegen","Mortensen","Sillesen","Brobak","Joergensen",         /*170*/
                             "staermose","Breum","Ibsen","Thomsen","Juul-Nyholm",
                             "Vive","Karkov","Lindberg","Golobvanv","Gruberg",              /*180*/
                             "Ekici","Dahl","John","Klitgaard","Rask",
                             "Grosen","Umnus","Jensen","Larsen","Larsen",                   /*190*/
                             "Madsen","Schou","Frisgaard","Froekjaer","Soernesen",
                             "Olsen","Randers","Sommer","Vergerakis","Brorholt",            /*200*/
                             "Gadegaard","Jhaf","Gundersen","Hermannson","Simonsen",
                             "Thomsen","Hansen","Thomsen","Nash","Pedersen",                /*210*/
                             "Madsen","Pihi","Moellnitz","Larsen","Hald",
                             "Nielsen","Nielsen","Kristiansen","Elgaard","Larsen",          /*220*/
                             "Ferslev","Christensen","Vinter","Larsen","Jensen",
                             "Nielsen","Jensen","Madsen","Larsen","Jensen",                 /*230*/
                             "Magnusen","Jensen","Rasmussen","Weirsoee"};
         /*24 klasser*/
        for (j=0;j<24;j++) {
            /*34 eksamener inklusiv skriftlige, men der skal der ikke være censore eller lærere til de skriftlige så de bliver skippet.*/
            for(i=0;i<34;i++) {
                skip:
                unikID_teacher++;
                unikID_censor++;
                switch (i) {
                       case 0:
                          /*Mundtlig matmatik*/
                          strcpy(examType,"AMm");
                          break;
                      case 1:
                          /*Skriftlig matmatik*/
                          strcpy(examType,"skip");
                          break;
                      case 2:
                          /*Mundtlig dansk*/
                          strcpy(examType,"AMd");
                          break;
                      case 3:
                          /*Skriftlig dansk*/
                          strcpy(examType,"skip");
                          break;
                      case 4:
                          /*Mundtlig fysik*/ 
                          strcpy(examType,"AMf");
                          break;
                      case 5:
                          /*Skriftlig fysik*/
                          strcpy(examType,"skip");
                          break;
                      case 6:
                          /*Mundtlig engelsk*/
                          strcpy(examType,"AMe");
                          break;
                      case 7:
                          /*Skriftlig engelsk*/
                          strcpy(examType,"skip");
                          break;
                      case 8:
                          /*Mundtlig kemi*/
                          strcpy(examType,"AMk");
                          break;
                      case 9:
                          /*Skriftlig kemi*/
                          strcpy(examType,"skip");
                          break;
                      case 10:
                          /*Mundtlig teknologi*/
                          strcpy(examType,"AMt");
                          break;
                      case 11:
                          /*Mundtlig bioteknologi*/
                          strcpy(examType,"AMbt");
                          break;
                      case 12:
                          /*Mundtlig kom it*/
                          strcpy(examType,"AMki");
                          break;
                      case 13:
                          /*Mundtlig matmatik*/
                          strcpy(examType,"BMm");
                          break;
                      case 14:
                          /*Skriftlig matmatik*/
                          strcpy(examType,"skip");
                          break;
                      case 15:
                          /*Mundtlig fysik*/
                          strcpy(examType,"BMf");
                          break;
                      case 16:
                          /*Skriftlig fysik*/
                          strcpy(examType,"skip");
                          break;
                      case 17:
                          /*Mundtlig engelsk*/
                          strcpy(examType,"BMe");
                          break;
                      case 18:
                          /*Skriftlig engelsk*/
                          strcpy(examType,"skip");
                          break;
                      case 19:
                          /*Mundtlig kemi*/
                          strcpy(examType,"BMk");
                          break;
                      case 20:
                          /*Skriftlig kemi*/
                          strcpy(examType,"skip");
                          break;
                      case 21:
                          /*Mundtlig teknologi*/
                          strcpy(examType,"BMt");
                          break;
                      case 22:
                          /*Mundtlig indehistorie*/
                          strcpy(examType,"BMi");
                          break;
                      case 23:
                          /*Mundtlig biologi*/
                          strcpy(examType,"BMb");
                          break;
                      case 24:
                          /*Mundtlig kom it*/
                          strcpy(examType,"BMki");
                          break;
                      case 25:
                          /*Mundtlig samfundsfag*/
                          strcpy(examType,"BMs");
                          break;
                      case 26:
                          /*Mundtlig teknologi historie*/
                          strcpy(examType,"BMth");
                          break;
                      case 27:
                          /*Mundtlig programmering*/
                          strcpy(examType,"CMp");
                          break;
                      case 28:
                          /*Mundtlig biologi*/
                          strcpy(examType,"CMb");
                          break;
                      case 29:
                          /*Mundtlig kom it*/
                          strcpy(examType,"CMki");
                          break;
                      case 30:
                          /*Mundtlig samfundsfag*/
                          strcpy(examType,"CMs");
                          break;
                      case 31:
                          /*Mundtlig teknologi historie*/
                          strcpy(examType,"CMth");
                          break;
                      case 32:
                          /*Mundtlig psykologi*/
                          strcpy(examType,"CMps");
                          break;
                      case 33:
                          /*Mundtlig astronomi*/
                          strcpy(examType,"CMa");
                          break;
                      default :
                          printf("faulty input\n");
                }

                if (strcmp(examType,"skip") == 0) {
                    i++;
                    classdata[j].subjects[i].verbal = false;
                    goto skip;
                }
                if(strcmp(examType, "skip") != 0){
                     /*Dan de overordnede oplysninger som hvilken eksamens typpe der er tale om, og om det er skriftlig eller mundtlig(det kan kun være mundtlig ergo 0*/
                    strcpy(classdata[j].subjects[i].subject,examType);
                    classdata[j].subjects[i].verbal = true;
                    /*Dan lærere*/
                    strcpy(classdata[j].subjects[i].teacher.name,teacher_fornavn[rand()%182]);
                    strcpy(classdata[j].subjects[i].teacher.surname,teacher_efternavn[rand()%234]);
                    classdata[j].subjects[i].teacher.ID = unikID_teacher;
                    /*Dan censore*/
                    strcpy(classdata[j].subjects[i].censor.name,teacher_fornavn[rand()%182]);
                    strcpy(classdata[j].subjects[i].censor.surname,teacher_efternavn[rand()%234]);
                    classdata[j].subjects[i].censor.ID = unikID_censor;
                }
            }
        } 
}
