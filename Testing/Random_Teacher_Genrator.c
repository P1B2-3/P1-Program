/*
 *
 * This program writes a file for the subjects with teachers and censors, and subjects and unik ID for both teachers and censors
 * Besudes for testing purpose it also writes to structs 
 *
 *
 *
 *
 * Author: Asger Geel Weirsøe
 * Version: 2.00 
*/


void RanTingWithTeachers(Data_Subject_t subjectdata_t[]) {
    int i,unikID=0;
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

    if ((fptr=fopen("Teacher_to_sub.txt","r"))!=NULL){ 
            printf("Creating new file\n");
            fptr = fopen("Teacher_to_sub.txt","w"); 
            fputs("//This entire document is dedicated to the processing of a school schedule.\n",fptr);
            fputs("//Please do not edit this file for any reasons. Unless you know what you are doing.\n\n\n",fptr);

        for(i=0;i<23;i++){
          unikID++;
          switch (i){
              case 0:
                  /*Mundtlig matmatik*/
                  strcpy(examType,"AMm");
                  break;
              case 1:
                  /*Skriftlig matmatik*/
                  strcpy(examType,"ASm");
                  break;
              case 2:
                  /*Mundtlig dansk*/
                  strcpy(examType,"AMd");
                  break;
              case 3:
                  /*Skriftlig dansk*/
                  strcpy(examType,"ASd");
                  break;
              case 4:
                  /*Mundtlig fysik*/ 
                  strcpy(examType,"AMf");
                  break;
              case 5:
                  /*Skriftlig fysik*/
                  strcpy(examType,"ASf");
                  break;
              case 6:
                  /*Mundtlig engelsk*/
                  strcpy(examType,"AMe");
                  break;
              case 7:
                  /*Skriftlig engelsk*/
                  strcpy(examType,"ASe");
                  break;
              case 8:
                  /*Mundtlig kemi*/
                  strcpy(examType,"AMk");
                  break;
              case 9:
                  /*Skriftlig kemi*/
                  strcpy(examType,"ASk");
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
                  strcpy(examType,"BSm");
                  break;
              case 15:
                  /*Mundtlig fysik*/
                  strcpy(examType,"BMf");
                  break;
              case 16:
                  /*Skriftlig fysik*/
                  strcpy(examType,"BSf");
                  break;
              case 17:
                  /*Mundtlig engelsk*/
                  strcpy(examType,"BMe");
                  break;
              case 18:
                  /*Skriftlig engelsk*/
                  strcpy(examType,"BSe");
                  break;
              case 19:
                  /*Mundtlig kemi*/
                  strcpy(examType,"BMk");
                  break;
              case 20:
                  /*Skriftlig kemi*/
                  strcpy(examType,"BSk");
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
                  strcpy(examType,"1Mp");
                  break;
              case 28:
                  /*Mundtlig biologi*/
                  strcpy(examType,"1Mb");
                  break;
              case 29:
                  /*Mundtlig kom it*/
                  strcpy(examType,"1Mki");
                  break;
              case 30:
                  /*Mundtlig samfundsfag*/
                  strcpy(examType,"1Ms");
                  break;
              case 31:
                  /*Mundtlig teknologi historie*/
                  strcpy(examType,"1Mth");
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
          strcpy(subjectdata_t[i].subject,examenType);
          strcpy(subjectdata_t[i].teacherName,elev_for_navn[rand()%182]);
          strcpy(subjectdata_t[i].teacherSurname,elev_efternavn[rand()%234]);
          strcpy(subjectdata_t[i].censorName,elev_for_navn[rand()%182]);
          strcpy(subjectdata_t[i].censorSurname,elev_efternavn[rand()%234]);
          
          fputs("--Subject Start--\n",fptr);
          fprintf(fptr,"Examen: %s",examenType);
          fprintf(fptr, "Teacher unikID: %i\n",subjectdata_t[i].teacher_ID = unikID);
          fprintf(fptr, "Teacher first name: %s\n",subjectdata_t[i].teacherName );
          fprintf(fptr, "Teacher last name: %s\n",subjectdata_t[i].teacherSurname);
          unikID++;
          fprintf(fptr, "Teacher unikID: %i\n",subjectdata_t[i].teacher_ID = unikID);
          fprintf(fptr, "Teacher first name: %s\n",subjectdata_t[i].censorName );
          fprintf(fptr, "Teacher last name: %s\n",subjectdata_t[i].censorSurname);
            

            

            fputs("--Subject end--\n\n",fptr);
        }
    }
}
