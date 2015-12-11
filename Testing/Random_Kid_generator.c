    /*
 * Random generating students with names, klasses, and other stuff and things.
 * 
 * Author Asger Geel Weirsøe
 * 
 * Version: 2.26
 * 
 * With a lot of new features.
 * Moved somethings and such + made it compatible with program (perhaps)
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int CMp,CMb,CMki,CMs,
        CMth,CMps,CMa;
}foersteG;

typedef struct{
    int BMm,BSm,BMf,BSf,
        BMe,BSe,BMk,BSk,
        BMt,BMi,BMb,BMki,
        BMs,BMth;
}andenG;

typedef struct {
    int AMm,ASm,AMd,ASd,
        AMf,AMe,ASe,AMk,ASf,
        ASk,AMt,AMbi,AMki;
}tredjeG;


void RandTing(Data_Student_t studentdata[],Data_Subject_t classubject[] Data_Class_t classdata[], Data_EksamensBlock_t eksamensblok[]) {

    foersteG TEMP_1G;
    foersteG Klasse_1A;
    foersteG Klasse_1B;
    foersteG Klasse_1C;
    foersteG Klasse_1D;
    foersteG Klasse_1E;
    foersteG Klasse_1F;
    foersteG Klasse_1G;
    foersteG Klasse_1H;

    andenG TEMP_2G; 
    andenG Klasse_2A;
    andenG Klasse_2B;
    andenG Klasse_2C;
    andenG Klasse_2D;
    andenG Klasse_2E;
    andenG Klasse_2F;
    andenG Klasse_2G;
    andenG Klasse_2H;

    tredjeG TEMP_3G;
    tredjeG Klasse_3A;
    tredjeG Klasse_3B;
    tredjeG Klasse_3C;
    tredjeG Klasse_3D;
    tredjeG Klasse_3E;
    tredjeG Klasse_3F;
    tredjeG Klasse_3G;
    tredjeG Klasse_3H;




    int i,unikID=0;

        TEMP_3G.AMm = 0; TEMP_3G.ASm = 0; TEMP_3G.AMd = 0; TEMP_3G.ASd = 0;
        TEMP_3G.AMf = 0; TEMP_3G.ASf = 0; TEMP_3G.AMe = 0; TEMP_3G.ASe = 0; TEMP_3G.AMk = 0;
        TEMP_3G.ASk = 0; TEMP_3G.AMt = 0; TEMP_3G.AMbi = 0; TEMP_3G.AMki = 0;


        TEMP_2G.BMm = 0; TEMP_2G.BSm = 0; TEMP_2G.BMf = 0; TEMP_2G.BSf = 0; TEMP_2G.BMe = 0; TEMP_2G.BSe = 0;
        TEMP_2G.BMk = 0; TEMP_2G.BSk = 0; TEMP_2G.BMt = 0; TEMP_2G.BMi = 0;  TEMP_2G.BMb = 0;
        TEMP_2G.BMki = 0; TEMP_2G.BMs = 0; TEMP_2G.BMth = 0;

       
        TEMP_1G.CMp = 0;TEMP_1G.CMb = 0;
        TEMP_1G.CMki = 0; TEMP_1G.CMs = 0; TEMP_1G.CMth = 0;
        TEMP_1G.CMps = 0; TEMP_1G.CMa = 0;



    int klass=0,k=0;
    int classdata[i].year =3,number_of_examens,temp_nr;
    char yorn;
    for(k=0; k<624 ;k++){
        for(i = 0; i < 34 i++) {
            classdata[k].fag[i] = 0;
        }  
    }
    
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
                                
       /*Åben fil jada jada*/
        FILE *fptr;
        char aar[20], examen[20];
        int taeller,tempP=0 ;
        printf("Before\n");
    if ((fptr=fopen("Student_Ran_Navn.txt","r"))==NULL){ 
        write : printf("Creating new file\n");
        fptr = fopen("Student_Ran_Navn.txt","w"); 
        fputs("//This entire document is dedicated to the processing of a school schedule.\n",fptr);
        fputs("//Please do not edit this file for any reasons. Unless you know what you are doing.\n\n\n",fptr);
        /*fputs, skriver simple kommandoer til filen*/
        
        /*For løkke som skriver alle elever ud.*/
        
        /*3g*/
        for(i = 1; i < 41; i++) {
            if(i == 6 || i == 11 || i == 16 || i == 21 || i == 26 || i == 31 || i == 36 ) {
                TEMP_3G.AMm = 0; TEMP_3G.ASm = 0; TEMP_3G.AMd = 0; TEMP_3G.ASd = 0;
                TEMP_3G.AMf = 0; TEMP_3G.ASf = 0; TEMP_3G.AMe = 0; TEMP_3G.ASe = 0; TEMP_3G.AMk = 0;
                TEMP_3G.ASk = 0; TEMP_3G.AMt = 0; TEMP_3G.AMbi = 0; TEMP_3G.AMki = 0;
            }

            randA3g: temp_nr = rand() % 13;
            if(temp_nr == 0) {
                if(TEMP_3G.AMk != 1) {
                   TEMP_3G.AMk = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 1) {
                if(TEMP_3G.AMm != 1) {
                    TEMP_3G.AMm = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 2) {
                if(TEMP_3G.ASm != 1) {
                    TEMP_3G.ASm = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 3) {
                if(TEMP_3G.AMd != 1) {
                    TEMP_3G.AMd = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 4) {
                if(TEMP_3G.ASd != 1) {
                    TEMP_3G.ASd = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 5) {
                if(TEMP_3G.AMki != 1) {
                    TEMP_3G.AMki = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 6) {
                if(TEMP_3G.AMf != 1){
                    TEMP_3G.AMf = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 7){
                if( TEMP_3G.ASf != 1){
                    TEMP_3G.ASf = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 8){
                if(TEMP_3G.AMe != 1){
                    TEMP_3G.AMe = 1;
                }else {
                    goto randA3g;
                }
            }else if(temp_nr == 9){
                if(TEMP_3G.ASe != 1){
                    TEMP_3G.ASe = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 10){
                if(TEMP_3G.ASk != 1){
                    TEMP_3G.ASk = 1;
                }else{
                    goto randA3g;
                }
            }else if(temp_nr == 11){
                if(TEMP_3G.AMt != 1) {
                    TEMP_3G.AMt = 1;
                }else{
                    goto randA3g;
                }
            }else {
                if(TEMP_3G.AMbi != 1){
                    TEMP_3G.AMbi = 1;
                }else
                    goto randA3g;
            }
            if(i == 5){
                tempP++;
                Klasse_3A = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 10){
                tempP++;
                Klasse_3B = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 15){
                tempP++;
                Klasse_3C = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 20){
                tempP++;
                Klasse_3D = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 25){
                tempP++;
                Klasse_3E = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 30){
                tempP++;
                Klasse_3F = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i == 35){
                tempP++;
                Klasse_3G = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }else if(i== 40){
                tempP++;
                Klasse_3H = TEMP_3G;
                if(TEMP_3G.AMm) {
                    classdata[tempP].fag[0] = 1;
                }if(EMP_3G.ASm) {
                    classdata[tempP].fag[1] = 1;
                }if(EMP_3G.AMd) {
                    classdata[tempP].fag[2] = 1;
                }if(EMP_3G.ASd) {
                    classdata[tempP].fag[3] = 1;
                }if(EMP_3G.AMf) {
                    classdata[tempP].fag[4] = 1;
                }if(EMP_3G.ASf) {
                    classdata[tempP].fag[5] = 1;
                }if(EMP_3G.AMe) {
                    classdata[tempP].fag[6] = 1;
                }if(EMP_3G.ASe) {
                    classdata[tempP].fag[7] = 1;
                }if(EMP_3G.AMk) {
                    classdata[tempP].fag[8] = 1;
                }if(EMP_3G.ASk) {
                    classdata[tempP].fag[9] = 1;
                }if(EMP_3G.AMt) {
                    classdata[tempP].fag[10] = 1; 
                }if(EMP_3G.AMbi) {
                    classdata[tempP].fag[11] = 1;
                }if(EMP_3G.AMki) {
                    classdata[tempP].fag[12] = 1;
                }  
            }
        }
        /*2g*/
        for(i = 1; i < 18; i++) {
            if(i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15){
                TEMP_2G.BMm = 0; TEMP_2G.BSm = 0; TEMP_2G.BMf = 0; TEMP_2G.BSf = 0; TEMP_2G.BMe = 0; TEMP_2G.BSe = 0;
                TEMP_2G.BMk = 0; TEMP_2G.BSk = 0; TEMP_2G.BMt = 0; TEMP_2G.BMi = 0;  TEMP_2G.BMb = 0;
                TEMP_2G.BMki = 0; TEMP_2G.BMs = 0; TEMP_2G.BMth = 0;
            }

            randA2g:temp_nr = rand() % 14;
            if(temp_nr == 0 ){
                if(TEMP_2G.BMm != 1) {
                    TEMP_2G.BMm = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 1) {
                if(TEMP_2G.BSm != 1){
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
                if(TEMP_2G.BMs != 1){
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
                if(TEMP_2G.BMki != 1){
                    TEMP_2G.BMki = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 8) {
                if(TEMP_2G.BMf != 1){
                    TEMP_2G.BMf = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 9) {
                if(TEMP_2G.BSf != 1){
                    TEMP_2G.BSf = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 10) {
                if(TEMP_2G.BMe != 1){
                    TEMP_2G.BMe = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 11) {
                if(TEMP_2G.BSe != 1){
                    TEMP_2G.BSe = 1;
                }else{
                    goto randA2g;
                }
            }else if(temp_nr == 12) {
                if(TEMP_2G.BMk != 1){
                    TEMP_2G.BMk = 1;
                }else{
                    goto randA2g;
                }
            }else {
                if(TEMP_2G.BSk != 1){
                    TEMP_2G.BSk = 1;
                }else{
                    goto randA2g;
                }
            }

           if(i == 2){
                tempP++;
                Klasse_2A = TEMP_2G;
                if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 4){
                tempP++;
                Klasse_2B = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 6){
                tempP++;
                Klasse_2C = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 8){
                tempP++;
                Klasse_2D = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 10){
                tempP++;
                Klasse_2E = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 12){
                tempP++;
                Klasse_2F = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 14){
                tempP++;
                Klasse_2G = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }else if(i == 16){
                tempP++;
                Klasse_2H = TEMP_2G;
                 if(TEMP_2G.BMm) {
                    classdata[tempP].fag[13] = 1;
                }if(TEMP_2G.BSm) {
                    classdata[tempP].fag[14] = 1;
                }if(TEMP_2G.BMf) {
                    classdata[tempP].fag[15] = 1;
                }if(TEMP_2G.BSf) {
                    classdata[tempP].fag[16] = 1;
                }if(TEMP_2G.BMe) {
                    classdata[tempP].fag[17] = 1;
                }if(TEMP_2G.BSe) {
                    classdata[tempP].fag[18] = 1;
                }if(TEMP_2G.BMk) {
                    classdata[tempP].fag[19] = 1;
                }if(TEMP_2G.BSk) {
                    classdata[tempP].fag[20] = 1;
                }if(TEMP_2G.BMt) {
                    classdata[tempP].fag[21] = 1;
                }if(TEMP_2G.BMi) {
                    classdata[tempP].fag[22] = 1;
                }if(TEMP_2G.BMb) {
                    classdata[tempP].fag[23] = 1;
                }if(TEMP_2G.BMki) {
                    classdata[tempP].fag[24] = 1;
                }if(TEMP_2G.BMs) {
                    classdata[tempP].fag[25] = 1;
                }if(TEMP_2G.BMth) {
                    classdata[tempP].fag[26] = 1;
                }
            }
        }
        /*1g*/
        for(i = 1; i < 9; i++){
            printf("Holaaa\n");
           
            TEMP_1G.CMp = 0;TEMP_1G.CMb = 0;
            TEMP_1G.CMki = 0; TEMP_1G.CMs = 0; TEMP_1G.CMth = 0;
            TEMP_1G.CMps = 0; TEMP_1G.CMa = 0;
            
            randA1g: temp_nr = rand() % 7;
            if(temp_nr == 0){ 
                if( TEMP_1G.CMki != 1){
                   TEMP_1G.CMki = 1;
                }else{
                    printf("Heja\n");
                    goto randA1g;
                }
                        /*CMki*/
            }else if(temp_nr == 1) {
                if( TEMP_1G.CMp){
                    TEMP_1G.CMp = 1;
                }else{
                    goto randA1g;
                }
                        /*CMp*/
            }else if(temp_nr == 2) {
                if( TEMP_1G.CMth =! 1){
                    TEMP_1G.CMth = 1;
                }else{
                    goto randA1g;
                }
                        /*CMth*/
            }else if(temp_nr == 3)  {
                if( TEMP_1G.CMps != 1){
                    TEMP_1G.CMps = 1;
                }else{
                    goto randA1g;
                }
            }else if(temp_nr == 4) {
                if( TEMP_1G.CMb != 1){
                    TEMP_1G.CMb = 1;
                }else{
                    goto randA1g;
                }
            }else if(temp_nr == 5) {
                if( TEMP_1G.CMs != 1){
                    TEMP_1G.CMs = 1;
                }else{
                    goto randA1g;
                }
            }else {
                if( TEMP_1G.CMa != 1){
                    TEMP_1G.CMa = 1;
                }else{
                    goto randA1g;
                }  
            }
            if(i == 1) {
                tempP++;
                Klasse_1A = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 2){
                tempP++;
                Klasse_1B = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 3){
                tempP++;
                Klasse_1C = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 4){
                tempP++;
                Klasse_1D = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 5){
                tempP++;
                Klasse_1E = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 6){
                tempP++;
                Klasse_1F = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 7){
                tempP++;
                Klasse_1G = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }else if(i == 8){
                tempP++;
                Klasse_1H = TEMP_1G;
                if(TEMP_1G.CMp) {
                    classdata[tempP].fag[27] = 1;
                }if(TEMP_1G.CMb) {
                    classdata[tempP].fag[28] = 1;
                }if(TEMP_1G.CMki) {
                    classdata[tempP].fag[29] = 1;
                }if(TEMP_1G.CMs) {
                    classdata[tempP].fag[30] = 1;
                }if(TEMP_1G.CMth) {
                    classdata[tempP].fag[31] = 1;
                }if(TEMP_1G.CMps) {
                    classdata[tempP].fag[32] = 1;
                }if(TEMP_1G.CMa) {
                    classdata[tempP].fag[33] = 1;
                }
            }
        }
        for(i=0;i<24;i++){
            fputs("\n--Class start--\n\n",fptr);
            fputs("##",fptr);
            fprintf(fptr, "Number in Class: %i\n",classdata[i].amountOfStudent = 26 );
            fprintf(fptr,"Id range: %s\n\n",(i==0) ? "1-26" : (i==1) ? "27-52" :
                                        (i==2) ? "53-78" : (i==3) ? "79-104" :
                                        (i==4) ? "105-130" : (i==5) ? "131-156" :
                                        (i==6) ? "157-182" : (i==7) ? "183-208" :
                                        (i==8) ? "209-234" : (i==9) ? "235-260" :
                                        (i==10) ? "261-286" : (i==11) ? "287-312" :
                                        (i==12) ? "313-338" : (i==13) ? "339-364" :
                                        (i==14) ? "365-390" : (i==15) ? "391-416" :
                                        (i==16) ? "417-442" : (i==17) ? "443-468" :
                                        (i==18) ? "469-494" : (i==19) ? "495-520" :
                                        (i==20) ? "521-546" : (i==21) ? "547-572" :
                                        (i==22) ? "573-598" : "599-624");
            fprintf(fptr,"Klasse nr: %i.%c\n",
                        classdata[i].year = (i<=8) ?  3 : (i > 8 && i<=16) ?  2 :  1,
                        classdata[i].className = 
                        (klass == 0 && classdata[i].year == 3)  ? 'A' :
                        (klass == 1 && classdata[i].year == 3)  ? 'B' :
                        (klass == 2 && classdata[i].year == 3)  ? 'C' :
                        (klass == 3 && classdata[i].year == 3)  ? 'D' :
                        (klass == 4 && classdata[i].year == 3)  ? 'E' :
                        (klass == 5 && classdata[i].year == 3)  ? 'F' :
                        (klass == 6 && classdata[i].year == 3)  ? 'G' :
                        (klass == 7 && classdata[i].year == 3)  ? 'H' :
                        (klass == 8 && classdata[i].year == 2)  ? 'A' :
                        (klass == 9 && classdata[i].year == 2)  ? 'B' :
                        (klass == 10 && classdata[i].year == 2) ? 'C' :
                        (klass == 11 && classdata[i].year == 2) ? 'D' :
                        (klass == 12 && classdata[i].year == 2) ? 'E' :
                        (klass == 13 && classdata[i].year == 2) ? 'F' :
                        (klass == 14 && classdata[i].year == 2) ? 'G' :
                        (klass == 15 && classdata[i].year == 2) ? 'H' :
                        (klass == 16 && classdata[i].year == 1) ? 'A' :
                        (klass == 17 && classdata[i].year == 1) ? 'B' :
                        (klass == 18 && classdata[i].year == 1) ? 'C' :
                        (klass == 19 && classdata[i].year == 1) ? 'D' :
                        (klass == 20 && classdata[i].year == 1) ? 'E' :
                        (klass == 21 && classdata[i].year == 1) ? 'F' :
                        (klass == 22 && classdata[i].year == 1) ? 'G' : 'H');

            if(classdata[i].year == 'A') {
                    if(classdata[i].year == 1) {
                        fprintf(fptr,"CMp = %i\n"
                                         "CMb = %i\n"
                                         "CMki = %i\n"
                                         "CMs = %i\n"
                                         "CMth = %i\n"
                                         "CMp = %i\n"
                                         "CMa = %i\n"  
                                         ,Klasse_1A.CMp,Klasse_1A.CMb,Klasse_1A.CMki,Klasse_1A.CMs,Klasse_1A.CMth,Klasse_1A.CMp,Klasse_1A.CMa);

                    }else if(classdata[i].year == 2) {
                        fprintf(fptr,"BMm = %i\n"
                                         "BSm = %i\n"
                                         "BMf = %i\n"
                                         "BSf = %i\n"
                                         "BMe = %i\n"
                                         "BSe = %i\n"
                                         "BMk = %i\n"
                                         "BSk = %i\n"
                                         "BMt = %i\n"
                                         "BMi = %i\n"
                                         "BMb = %i\n"
                                         "BMki = %i\n"
                                         "BMs = %i\n"
                                         "BMth = %i\n"

                                ,Klasse_2A.BMm,Klasse_2A.BSm,Klasse_2A.BMf,Klasse_2A.BSf,Klasse_2A.BMe,Klasse_2A.BSe,Klasse_2A.BMk,Klasse_2A.BSk,Klasse_2A.BMt,Klasse_2A.BMi,Klasse_2A.BMb,Klasse_2A.BMki,Klasse_2A.BMs,Klasse_2A.BMth);
                    }else {
                        fprintf(fptr,"AMm = %i\n"
                                         "ASm = %i\n"
                                         "AMd = %i\n"
                                         "ASd = %i\n"
                                         "AMf = %i\n"
                                         "ASf = %i\n"
                                         "AMe = %i\n"
                                         "ASe = %i\n"
                                         "AMk = %i\n"
                                         "ASk = %i\n"
                                         "AMt = %i\n"
                                         "AMbi = %i\n"
                                         "AMki = %i\n",
                                         Klasse_3A.AMm,Klasse_3A.ASm,Klasse_3A.AMd,Klasse_3A.ASd,Klasse_3A.AMf,Klasse_3A.AMe,Klasse_3A.ASe,Klasse_3A.AMk,Klasse_3A.ASk,Klasse_3A.AMt,Klasse_3A.AMbi,Klasse_3A.AMki);

                    }
            }else if(classdata[i].year == 'B') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1B.CMp,Klasse_1B.CMb,Klasse_1B.CMki,Klasse_1B.CMs,Klasse_1B.CMth,Klasse_1B.CMp,Klasse_1B.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2B.BMm,Klasse_2B.BSm,Klasse_2B.BMf,Klasse_2B.BSf,Klasse_2B.BMe,Klasse_2B.BSe,Klasse_2B.BMk,Klasse_2B.BSk,Klasse_2B.BMt,Klasse_2B.BMi,Klasse_2B.BMb,Klasse_2B.BMki,Klasse_2B.BMs,Klasse_2B.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3B.AMm,Klasse_3B.ASm,Klasse_3B.AMd,Klasse_3B.ASd,Klasse_3B.AMf,Klasse_3B.AMe,Klasse_3B.ASe,Klasse_3B.AMk,Klasse_3B.ASk,Klasse_3B.AMt,Klasse_3B.AMbi,Klasse_3B.AMki);
                }
            }else if(classdata[i].year == 'C') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1C.CMp,Klasse_1C.CMb,Klasse_1C.CMki,Klasse_1C.CMs,Klasse_1C.CMth,Klasse_1C.CMp,Klasse_1C.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2C.BMm,Klasse_2C.BSm,Klasse_2C.BMf,Klasse_2C.BSf,Klasse_2C.BMe,Klasse_2C.BSe,Klasse_2C.BMk,Klasse_2C.BSk,Klasse_2C.BMt,Klasse_2C.BMi,Klasse_2C.BMb,Klasse_2C.BMki,Klasse_2C.BMs,Klasse_2C.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3C.AMm,Klasse_3C.ASm,Klasse_3C.AMd,Klasse_3C.ASd,Klasse_3C.AMf,Klasse_3C.AMe,Klasse_3C.ASe,Klasse_3C.AMk,Klasse_3C.ASk,Klasse_3C.AMt,Klasse_3C.AMbi,Klasse_3C.AMki);
                }
            }else if(classdata[i].year == 'D') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1D.CMp,Klasse_1D.CMb,Klasse_1D.CMki,Klasse_1D.CMs,Klasse_1D.CMth,Klasse_1D.CMp,Klasse_1D.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2D.BMm,Klasse_2D.BSm,Klasse_2D.BMf,Klasse_2D.BSf,Klasse_2D.BMe,Klasse_2D.BSe,Klasse_2D.BMk,Klasse_2D.BSk,Klasse_2D.BMt,Klasse_2D.BMi,Klasse_2D.BMb,Klasse_2D.BMki,Klasse_2D.BMs,Klasse_2D.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3D.AMm,Klasse_3D.ASm,Klasse_3D.AMd,Klasse_3D.ASd,Klasse_3D.AMf,Klasse_3D.AMe,Klasse_3D.ASe,Klasse_3D.AMk,Klasse_3D.ASk,Klasse_3D.AMt,Klasse_3D.AMbi,Klasse_3D.AMki);
                }
            }else if(classdata[i].year == 'E') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1E.CMp,Klasse_1E.CMb,Klasse_1E.CMki,Klasse_1E.CMs,Klasse_1E.CMth,Klasse_1E.CMp,Klasse_1E.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2E.BMm,Klasse_2E.BSm,Klasse_2E.BMf,Klasse_2E.BSf,Klasse_2E.BMe,Klasse_2E.BSe,Klasse_2E.BMk,Klasse_2E.BSk,Klasse_2E.BMt,Klasse_2E.BMi,Klasse_2E.BMb,Klasse_2E.BMki,Klasse_2E.BMs,Klasse_2E.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3E.AMm,Klasse_3E.ASm,Klasse_3E.AMd,Klasse_3E.ASd,Klasse_3E.AMf,Klasse_3E.AMe,Klasse_3E.ASe,Klasse_3E.AMk,Klasse_3E.ASk,Klasse_3E.AMt,Klasse_3E.AMbi,Klasse_3E.AMki);
                }
            }else if(classdata[i].year == 'F') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1F.CMp,Klasse_1F.CMb,Klasse_1F.CMki,Klasse_1F.CMs,Klasse_1F.CMth,Klasse_1F.CMp,Klasse_1F.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2F.BMm,Klasse_2F.BSm,Klasse_2F.BMf,Klasse_2F.BSf,Klasse_2F.BMe,Klasse_2F.BSe,Klasse_2F.BMk,Klasse_2F.BSk,Klasse_2F.BMt,Klasse_2F.BMi,Klasse_2F.BMb,Klasse_2F.BMki,Klasse_2F.BMs,Klasse_2F.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3F.AMm,Klasse_3F.ASm,Klasse_3F.AMd,Klasse_3F.ASd,Klasse_3F.AMf,Klasse_3F.AMe,Klasse_3F.ASe,Klasse_3F.AMk,Klasse_3F.ASk,Klasse_3F.AMt,Klasse_3F.AMbi,Klasse_3F.AMki);
                }
            }else if(classdata[i].year == 'G') {
                if(classdata[i].year == 1) {
                    fprintf(fptr,"CMp = %i\n"
                                     "CMb = %i\n"
                                     "CMki = %i\n"
                                     "CMs = %i\n"
                                     "CMth = %i\n"
                                     "CMp = %i\n"
                                     "CMa = %i\n"  
                                     ,Klasse_1G.CMp,Klasse_1G.CMb,Klasse_1G.CMki,Klasse_1G.CMs,Klasse_1G.CMth,Klasse_1G.CMp,Klasse_1G.CMa);

                }else if(classdata[i].year == 2) {
                    fprintf(fptr,"BMm = %i\n"
                                     "BSm = %i\n"
                                     "BMf = %i\n"
                                     "BSf = %i\n"
                                     "BMe = %i\n"
                                     "BSe = %i\n"
                                     "BMk = %i\n"
                                     "BSk = %i\n"
                                     "BMt = %i\n"
                                     "BMi = %i\n"
                                     "BMb = %i\n"
                                     "BMki = %i\n"
                                     "BMs = %i\n"
                                     "BMth = %i\n"

                            ,Klasse_2G.BMm,Klasse_2G.BSm,Klasse_2G.BMf,Klasse_2G.BSf,Klasse_2G.BMe,Klasse_2G.BSe,Klasse_2G.BMk,Klasse_2G.BSk,Klasse_2G.BMt,Klasse_2G.BMi,Klasse_2G.BMb,Klasse_2G.BMki,Klasse_2G.BMs,Klasse_2G.BMth);
                }else {
                    fprintf(fptr,"AMm = %i\n"
                                     "ASm = %i\n"
                                     "AMd = %i\n"
                                     "ASd = %i\n"
                                     "AMf = %i\n"
                                     "ASf = %i\n"
                                     "AMe = %i\n"
                                     "ASe = %i\n"
                                     "AMk = %i\n"
                                     "ASk = %i\n"
                                     "AMt = %i\n"
                                     "AMbi = %i\n"
                                     "AMki = %i\n",
                                     Klasse_3G.AMm,Klasse_3G.ASm,Klasse_3G.AMd,Klasse_3G.ASd,Klasse_3G.AMf,Klasse_3G.AMe,Klasse_3G.ASe,Klasse_3G.AMk,Klasse_3G.ASk,Klasse_3G.AMt,Klasse_3G.AMbi,Klasse_3G.AMki);
                }
            }else  {
                    if(classdata[i].year == 1) {
                        fprintf(fptr,"CMp = %i\n"
                                         "CMb = %i\n"
                                         "CMki = %i\n"
                                         "CMs = %i\n"
                                         "CMth = %i\n"
                                         "CMp = %i\n"
                                         "CMa = %i\n"  
                                         ,Klasse_1H.CMp,Klasse_1H.CMb,Klasse_1H.CMki,Klasse_1H.CMs,Klasse_1H.CMth,Klasse_1H.CMp,Klasse_1H.CMa);

                    }else if(classdata[i].year == 2) {
                        fprintf(fptr,"BMm = %i\n"
                                         "BSm = %i\n"
                                         "BMf = %i\n"
                                         "BSf = %i\n"
                                         "BMe = %i\n"
                                         "BSe = %i\n"
                                         "BMk = %i\n"
                                         "BSk = %i\n"
                                         "BMt = %i\n"
                                         "BMi = %i\n"
                                         "BMb = %i\n"
                                         "BMki = %i\n"
                                         "BMs = %i\n"
                                         "BMth = %i\n"

                                ,Klasse_2H.BMm,Klasse_2H.BSm,Klasse_2H.BMf,Klasse_2H.BSf,Klasse_2H.BMe,Klasse_2H.BSe,Klasse_2H.BMk,Klasse_2H.BSk,Klasse_2H.BMt,Klasse_2H.BMi,Klasse_2H.BMb,Klasse_2H.BMki,Klasse_2H.BMs,Klasse_2H.BMth);
                    }else {
                        fprintf(fptr,"AMm = %i\n"
                                         "ASm = %i\n"
                                         "AMd = %i\n"
                                         "ASd = %i\n"
                                         "AMf = %i\n"
                                         "ASf = %i\n"
                                         "AMe = %i\n"
                                         "ASe = %i\n"
                                         "AMk = %i\n"
                                         "ASk = %i\n"
                                         "AMt = %i\n"
                                         "AMbi = %i\n"
                                         "AMki = %i\n",
                                         Klasse_3H.AMm,Klasse_3H.ASm,Klasse_3H.AMd,Klasse_3H.ASd,Klasse_3H.AMf,Klasse_3H.AMe,Klasse_3H.ASe,Klasse_3H.AMk,Klasse_3H.ASk,Klasse_3H.AMt,Klasse_3H.AMbi,Klasse_3H.AMki);
                    }
            }
            
            for(taeller = 1; taeller < 27;taeller++) {

                unikID++;
                
                /*klass bliver brugt til at holde styr på at der kun skal være 26 i en klasse */
    
                /*classdata[i].year bliver tildelt endten 3, 2 eller 1 som beskriver hvilken årgang vedkommende gård på*
                *dette gør det muligt at have de samme abcdefgh klasser til alle årgangene.              */
                fputs("--Student start--\n",fptr);
                fprintf(fptr, "Student unikID: %i\n",studentdata[unikID].unikID = unikID);
                
                strcpy(studentdata[unikID].studentName,Nameelev_for_navn[rand()%182]);
                strcpy(studentdata[unikID.studentSurname,elev_efternavn[rand()%234]);
                fprintf(fptr, "Nr in class: %i\n",studentdata[unikID].examNumber = taeller );
                fprintf(fptr, "First name: %s\n",studentdata[unikID].studentName);
                fprintf(fptr, "Last name: %s\n",studentdata[unikID.studentSurname);
                fputs("--Student end--\n\n",fptr);
            }
            
                fputs("\n\n--Class end--\n",fptr);
            klass++;
        }
            
            
    }else{
        printf("You already have a file called that, do you want to delete this file? [Y]es [N]o\n");
        scanf(" %c",&yorn);
        if(yorn == 'y' || yorn == 'Y') {
            goto write;
        }else if (yorn == 'n' || yorn == 'N') {
            printf("Alright shutting down.\n");
            exit(1);
        }else {
            printf("your mother sucks\n");
            exit(1);
        }
    }
    return 0;
}
