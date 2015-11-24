/*
Denne funktion, skal kunne fortælle i et nyt array hvilke studenter der skal op til hvilke eksamener.
Dette skal den gøre ved at køre qsort funktionen ->INSERT NAME HERE<-

Programmet er skrevet af: Asger Geel Weirsøe
24/11-2015
V. 1.04
*/
char * glob_examen;
int Get_examens_student(Data_elever_t Data_elever_t[], int last,char * examen, Data_after_sorting_t Data_elever_after_sorting_t[];) {
    glob_examen = examen;
    Sort_for_examns(Data_elever_t[],last,examen)
    Create_new_database(Data_elever_t[],Data_elever_after_sorting_t[]);

}

void Create_new_database(Data_after_sorting_t Data_elever_t[],Data_after_sorting_t Data_elever_after_sorting_t[]){
    int i=0;
    for(;Data_elever_t[i]->glob_examen == 1;i++) {
        Data_elever_after_sorting_t[i] =
        Create_new_students(Data_elever_t.unikID,Data_elever_t.elev_for_navn,Data_elever_t.elev_efter_navn);
  }
}

Data_after_sorting_t Create_new_students(int unikID, char * student_first_name, char * student_last_name) {
    Data_after_sorting_t results;
    
    results.unikID = unikID;
    results.for_navn = student_first_name;
    results.efter_navn = student_last_name;
    
    return results;
}
