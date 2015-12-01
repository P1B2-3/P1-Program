#include <stdlib.h>
#include <stdio.h>
​
int main() {
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
​
    if ((fptr=fopen("Teacher_to_sub.txt","r"))!=NULL){ 
            printf("Creating new file\n");
            fptr = fopen("Teacher_to_sub.txt","w"); 
            fputs("//This entire document is dedicated to the processing of a school schedule.\n",fptr);
            fputs("//Please do not edit this file for any reasons. Unless you know what you are doing.\n\n\n",fptr);
​
        for(i=0;i<23;i++){
            fputs("--Teacher Start--\n",fptr);
            fprintf(fptr, "First name: %s\n",elev_for_navn[rand()%182] );
            fprintf(fptr, "Last name: %s\n", elev_efternavn[rand()%182]);
            fprintf(fptr, "unikID: %i\n",i+1);
            fprintf(fptr,"CMp = %i\n"
                         "CMb = %i\n"
                         "CMki = %i\n"
                         "CMs = %i\n"
                         "CMth = %i\n"
                         "CMp = %i\n"
                         "CMa = %i\n"  
                         
                         "BMf = %i\n"
                         
                         "BMe = %i\n"
                         
                         "BMk = %i\n"
                         
                         "BMt = %i\n"
                         "BMi = %i\n"
                         "BMb = %i\n"
                         "BMki = %i\n"
                         "BMs = %i\n"
                         "BMth = %i\n"
                         
                         "AMd = %i\n"
                         
                         "AMf = %i\n"
                         
                         "AMe = %i\n"
                         
                         "AMk = %i\n"
                         
                         "AMt = %i\n"
                         "AMbi = %i\n"
                         "AMki = %i\n",
                         (i == 0),(i==1),(i==2),(i==3),(i==4),(i==5),(i==6),(i==7),(i==8),(i==9),(i==10),(i==11),(i==12),(i==13),(i==14),(i==15),(i==16),(i==17),(i==18),(i==19),(i==20),(i==21),(i==22));
​
            fputs("--Teacher end--\n\n",fptr);
        }
    }
}
