TARGET=editionDistanceProblem.o

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= structs/editionDistance/editionDistance.c main.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

clear:
	rm $(TARGET)