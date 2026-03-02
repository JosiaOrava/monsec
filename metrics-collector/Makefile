CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iincludes

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=bin/%.o)

all: bin/monsec-metrics

bin/monsec-metrics: $(OBJ)
	$(CC) $(CFLAGS) -o bin/monsec-metrics $(OBJ)

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./bin/monsec-metrics

clean:
	rm -f bin/*.o bin/monsec-metrics