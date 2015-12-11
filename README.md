# P1-Program

**Indhold**

- [HOW TO MAKEFILE](#how-to-makefile)
- [FUNKTIONER](#funktioner)
- [KONFIGURATION](#konfiguration)

# HOW TO MAKEFILE
  1. Naviger til mappe (med MinGW terminal)
  2. Brug komando: _make -f makefile.make_
 
# FUNKTIONER
  - <b>getConfig(string)</b> _configParser.c_ <br>
 Denne funktion retunerer en double-værdi, korresponderende med den givne string. Denne bruges til at hente data fra config.ini filen, i resten af programmet. <br>
F.eks. <br>
_getConfig("s.numberOfStudents")_ retunerer int-værdien _24.00_
<br>
<br>

  - <b>ReturnSpeceficData(string,int,int,int,int,int,int,int,int,struct)</b> _ReturnSpeceficData.c_ <br>
 Funktionen skriver returner en pointer til enden char* eller int, og skal derfor fanges i en void pointer, for derefter at kunne blive sat til en specifik data senere (hvis der er behov for det). Det funktionen returnere afhænger af hvad du skriver i den første string, (examens\_class\_ID, name\_surname, Class, unikID, subject\_number, subject\_name, lokale, periodestart, periode_end) og de mange int bliver brugt til at beskrive hvor i arrayet der skal kigges. Så <br>
(indput\_nr\_class, indput\_nr\_subject, indput\_nr\_student, indput\_nr\_teacher, indput\_nr\_censor, indput\_nr\_classexam, indput\_nr\_exam, indput\_nr\_datablock) <br>
Structen skal være Data\_block\_t datablock. <br>
F.eks. <br>
_ReturnSpeceficData(name\_surname,1,0,1,-1,-1,-1,0,0,0,datablock)_ vil returnere en char* værdi med elev 1 i klasse 1's efternavn.<br>
Hvor imod hvis den så således ud:<br>
_ReturnSpeceficData(unikID,1,0,1,-1,-1,-1,0,0,0,datablock)_ vil den returnere en int værdi med elev 1 i klasse 1's unikke ID.
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

I filen _config.ini_ har vi en række vædier som vi benytter som konstanter i vores program. Vi ønsker ikke at disse skal være hardcoded i vores program, og derfor importere vi data fra en tekstfil. Dette gør brugen af programmet lettere, samt giver programmet et bredere brugs muligheder.
<br>
<br>
Vi benytter et tag i starten af hvert paramter, til at bestemme typen af parameteren. Altså, i hvilken kontekst de skal indgå. Disse benyttes kun af organiserings grunde, og ikke tekniske grunde. Herunder ses definitionerne af tags'ene.
<br>
<br>

_g.xxx_ = Global parameter <br>
_s.xxx_ = Spoken exam parameter <br>
_w.xxx_ = Written exam parameter <br>
_a.xxx_ = Algorithm parameter <br>


