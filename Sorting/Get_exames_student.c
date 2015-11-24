/*
Denne funktion, skal kunne fortælle i et nyt array hvilke studenter der skal op til hvilke eksamener.
Dette skal den gøre ved at køre qsort funktionen ->INSERT NAME HERE<-

Programmet er skrevet af: Asger Geel Weirsøe
21/11-2015
V. 1.00
*/
char * exmn_var;
int Get_examens_student(Data_elever_t Data_elever_t[], int last,char * examen, Data_after_sorting_t Data_elever_after_sorting_t[];) {
    Sort_for_examns(Data_elever_t[], Data_elever_after_sorting_t[])
    exmn_var = examen;
  
  
}

void Create_new_database(Data_after_sorting_t Data_elever_t[],Data_after_sorting_t Data_elever_after_sorting_t[]){
    int i=0;
    for(;Data_elever_t->examen == 1;i++) {
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
