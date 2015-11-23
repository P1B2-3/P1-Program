CC=gcc
CFLAGS= -Wall -pedantic -ansi
TARGET = main

.PHONY: clean

DEPS = Structs/DATA_BASE.h readWrite/Write/DaysWhereTeacherIsAbcent.h

OBJ = main.o Structs/TeacherDays.o Sorting/Get_exams_student.o Sorting/Sort_for_exams.o readWrite/Write/StudentData.o readWrite/Write/TeacherData.o readWrite/Write/DaysWhereTeacherIsAbcent.o


$(TARGET).exe: $(OBJ) main.c
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) main.c

TeacherDays.o: Structs/TeacherDays.c
	gcc $(CFLAGS) -c Structs/TeacherDays.c

Get_exams_student.o: Sorting/Get_exams_student.o
	gcc $(CFLAGS) -c Sorting/Get_exams_student.o

Sort_for_exams.o: Sorting/Sort_for_exams.c
	gcc $(CFLAGS) -c Sorting/Sort_for_exams.c

StudentData.o: readWrite/Write/StudentData.c
	gcc $(CFLAGS) -c readWrite/Write/StudentData.c

Teacherdata.o: readWrite/Write/Teacherdata.c
	gcc $(CFLAGS) -c readWrite/Write/Teacherdata.c

DaysWhereTeacherIsAbcent.o: readWrite/Write/DaysWhereTeacherIsAbcent.c
	gcc $(CFLAGS) -c readWrite/Write/DaysWhereTeacherIsAbcent.c


clean:
	rm $(TARGET).exe