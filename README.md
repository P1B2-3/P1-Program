# P1-Program

# HOW TO MAKEFILE (Currently not compiling)
  1. Naviger til mappe (med MinGW terminal)
  2. Brug komando: _make -f makefile.make_
 
# FUNKTIONER
  - <b>getConfig(string)</b> _configParser.c_ <br>
 Denne funktion retunerer en int-værdi, korresponderende med den givne string. Denne bruges til at hente data fra config.ini filen, i resten af programmet. <br>
F.eks. <br>
_getConfig("s.numberOfStudents")_ retunerer int-værdien _24_
<br>
<br>

  - <b>Funktion</b> _fil_ <br>
 Beskrivelse... <br>
F.eks. <br>
_eksempel_
<br>
<br>

  - <b>Funktion</b> _fil_ <br>
 Beskrivelse... <br>
F.eks. <br>
_eksempel_
<br>
<br>

  - <b>Funktion</b> _fil_ <br>
 Beskrivelse... <br>
F.eks. <br>
_eksempel_
<br>
<br>

  - <b>Funktion</b> _fil_ <br>
 Beskrivelse... <br>
F.eks. <br>
_eksempel_
<br>
<br>

# KONFIGURATION

I filen _config.ini_ har vi en række vædier som vi benytter som konstanter i vores program. Vi ønsker ikke at disse skal være hardcoded i vores program, og derfor importere vi data fra en tekstfil. Dette gør brugen af programmet nemmere, samt giver programmet et bredere brug muligheder.
<br>
<br>
Vi benytter et tag i starten af hvert paramter, til at bestemme typen af parameteren. Altså, i hvilken kontekst de skal indgå. Disse benyttes kun af organiserings grunde, og ikke tekniske grunde. Herunder ses definitionerne af tags'ene.
<br>
<br>

_g.xxx_ = Global parameter <br>
_s.xxx_ = Spoken exam parameter <br>
_w.xxx_ = Written exam parameter <br>
_a.xxx_ = Algorithm parameter <br>


