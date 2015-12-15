CC=gcc
CFLAGS=-Wall -pedantic -ansi
TARGET = main
LIBS = -lm

.PHONY: default all clean

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c)) Structs/$(patsubst %.c, %.o, $(wildcard *.c)) Sorting/$(patsubst %.c, %.o, $(wildcard *.c)) readWrite/$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

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