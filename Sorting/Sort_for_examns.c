/*
Qsort funktionen her, kan sortere ud fra eksamner.
Man skal blot give denne, structen med studenter, længden og en string som indbefatter:
- "matmund"
- "matskrif"
- "damund"
- "daskrif"
- "fysmund"
- "fysskrif"
- "engmund"
- "engskrif"
- "kemmund"
- "kemskrif"
- "tek"
- "prog"
- "ideh"
- "bio"
- "komit"
- "samf"
og for teknologihistorie
skal man ikke give den noget.

Skrevet af Asger Geel Weirsøe
20/11-2015
V. 1.00
*/
#include <stdlib.h>

char examn_var[20]; 

void Sort_data_student(data Data_elever_t[], int last,char * examen) {
if(examen == "matmund") {
    examn_var ="Mm";
  }else if(examen == "matskrif") {
    examn_var ="Sm";
  }else if(examen == "damund") {
    examn_var ="Md";
  }else if(examen == "daskrif") {
    examn_var ="Sd";
  }else if(examen == "fysmund") {
    examn_var ="Mf";
  }else if(examen == "fysskrif") {
    examn_var ="Sf";
  }else if(examen == "engmund") {
    examn_var ="Me";
  }else if(examen == "engskrif") {
    examn_var ="Se";
  }else if(examen == "kemmund") {
    examn_var ="Mk";
  }else if(examen == "kemskrif") {
    examn_var ="Sk";
  }else if(examen == "tek") {
    examn_var ="Mt";
  }else if(examen == "prog") {
    examn_var ="Mp";
  }else if(examen == "ideh") {
    examn_var ="Mi";
  }else if(examen == "bio") {
    examn_var ="Mb";
  }else if(examen == "komit") {
    examn_var ="Mki";
  }else if(examen == "samf") {
    examn_var ="Ms";
  }else {
    examn_var ="Mth";
  }
  qsort(stydebt_t,last+1,sizeof(data),qsort_examen);
}
int qsort_examen(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
    if(a->examn_var && b->examn_var) {
      if(a->unikID < b->unikID) {
        return 1;
      }
    }
    else if(a->examn_var && !(b->examn_var) {
      return 1;
    }
  return -1;
}
    
/*
void Sort_data_student(data Data_elever_t[], int last,char * examen) {
  if(examen == "matmund") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_mat_mundtlig);
  }else if(examen == "matskrif") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_mat_skriftlig);
  }else if(examen == "damund") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_da_mundtlig);
  }else if(examen == "daskrif") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_da_skriftlig);
  }else if(examen == "fysmund") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_fys_mundtlig);
  }else if(examen == "fysskrif") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_fys_skriftlig);
  }else if(examen == "engmund") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_eng_mundtlig);
  }else if(examen == "engskrif") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_eng_skriftlig);
  }else if(examen == "kemmund") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_kem_mundtlig);
  }else if(examen == "kemskrif") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_kem_skriftlig);
  }else if(examen == "tek") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_tek);
  }else if(examen == "prog") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_prog);
  }else if(examen == "ideh") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_ideh);
  }else if(examen == "bio") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_bio);
  }else if(examen == "komit") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_komit);
  }else if(examen == "samf") {
    qsort(stydebt_t,last+1,sizeof(data),qsort_samf);
  }else {
    qsort(stydebt_t,last+1,sizeof(data),qsort_tekhis);
  }
  
  
}
int qsort_mat_mundtlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
    if(a->Mm && b->Mm) {
      if(a->unikID < b->unikID) {
        return 1;
      }
    }
    else if(a->Mm && !(b->Mm) {
      return 1;
    }
  return -1;
}
int qsort_mat_skriftlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
    if(a->Sm && b->Sm) {
      if(a->unikID < b->unikID) {
        return 1;
      }
    }
    else if(a->Sm && !(b->Sm)) {
      return 1;
    }
  return -1;
}
int qsort_da_mundtlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Md && b->Md) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Md && !(b->Md)) {
    return 1;
  }
  return -1;
}
int qsort_da_skriftlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Sd && b->Sd) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Sd && !(b->Sd)) {
    return 1;
  }
  return -1;
}
int qsort_fys_mundtlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mf && b->Mf) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mf && !(b->unikID)) {
    return 1;
  }
  return -1;
}
int qsort_fys_skriftlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Sf && b->Sf) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Sf && !(b->Sf)) {
    return 1;
  }
  return -1;
}
int qsort_eng_mundtlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Me && b->Me) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Me && !(b->Me)) {
    return 1;
  }
  return -1;
}
int qsort_eng_skriftlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Se && b->Se) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Se && !(b->Se)) {
    return 1;
  }
  return -1;
}
int qsort_kem_mundtlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mk && b->Mk) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->unikID && !(b->unikID)) {
    return 1;
  }
  return -1;
}
int qsort_kem_skriftlig(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Sk && b->Sk) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Sk && !(b->Sk)) {
    return 1;
  }
  retuen -1;
}
int qsort_tek(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mt && b->Mt) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mt && !(b->Mt)) {
    return 1;
  }
  return -1;
}
int qsort_prog(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mp && b->Mp) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mp && !(b->Mp)) {
    return 1;
  }
  return -1;
}
int qsort_ideh(const void* p1,const void* p2) {
 data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mi && b->Mi) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mi && !(b->Mi)) {
    return 1;
  }
  return -1;
}
int qsort_bio(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mb && b->Mb) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mb && !(b->Mb)) {
    return 1;
  }
  return -1;
}
int qsort_komit(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mki && b->Mki) {
    if(a->unikID < b->unikID) {
      return 1;
    }
  }
  else if(a->Mki && !(b->Mki)) {
    return 1;
  }
  return -1;
}
int qsort_samf(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Ms && b->Ms) {
    if(a->unikID < b->unikId) {
      return 1;
    }
  }
  else if(a->Ms && !(b->Ms)) {
    return 1;
  }
  return -1;
}
int qsort_tekhis(const void* p1,const void* p2) {
  data *a,*b;
    a = (data*)p1;
    b = (data*)p2;
  if(a->Mth && b->Mth) {
    if(a->unikID < b->unikId) {
      return 1;
    }
  }
  else if(a->Mth && !(b->Mth)) {
    return 1;
  }
  return -1;
}
*/
