CC=gcc
CFLAGS= -Wall -pedantic -ansi
TARGET = main

.PHONY: default all clean

HEADERS = Structs/DATA_BASE.h readWrite/Write/DaysWhereTeacherIsAbcent.h
OBJECTS = main.o Structs/TeacherDays.o Sorting/Get_exams_student.o Sorting/Sort_for_exams.o readWrite/Write/StudentData.o readWrite/Write/TeacherData.o readWrite/Write/DaysWhereTeacherIsAbcent.o

default: $(TARGET)
all: default

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)