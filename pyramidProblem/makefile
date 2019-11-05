TARGET=pyramidProblem

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= structs/pyramid/pyramid.c structs/way/way.c main.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3

debug:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -DDEBUG=1 -O3

run:
	./$(TARGET)

clear:
	rm $(TARGET)

clang:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3