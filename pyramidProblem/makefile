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

debug:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -DDEBUG=1

run:
	./$(TARGET)

clear:
	rm $(TARGET)

clang:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3