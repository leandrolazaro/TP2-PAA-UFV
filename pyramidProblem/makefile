TARGET=pyramidProblem.o

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= structs/pyramid/pyramid.c main.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

clear:
	rm $(TARGET)