CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -ggdb -Iinclude
VFLAGS = --show-leak-kinds=all --leak-check=full --track-origins=yes

.PHONY = all clean run

all: bin/a1p1 bin/a1p2 bin/a1p3 bin/a1p4 bin/a1p5

train:
	./bin/a1p2
	./bin/a1p3 9
	./bin/a1p3 8
	./bin/a1p3 7
	./bin/a1p3 6
	./bin/a1p3 5
	./bin/a1p3 4
	./bin/a1p3 3
	./bin/a1p3 2
	./bin/a1p3 1
	./bin/a1p3 0

bin/a1p1: obj/a1p1.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/a1p1.o -o bin/a1p1

bin/a1p2: obj/a1p2.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/a1p2.o -o bin/a1p2

bin/a1p3: obj/a1p3.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/a1p3.o -o bin/a1p3

bin/a1p4: obj/a1p4.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/a1p4.o -o bin/a1p4

bin/a1p5: obj/a1p5.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/a1p5.o -o bin/a1p5


obj/a1p1.o: src/a1p1.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/a1p1.c -o obj/a1p1.o

obj/a1p2.o: src/a1p2.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/a1p2.c -o obj/a1p2.o

obj/a1p3.o: src/a1p3.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/a1p3.c -o obj/a1p3.o

obj/a1p4.o: src/a1p4.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/a1p4.c -o obj/a1p4.o

obj/a1p5.o: src/a1p5.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/a1p5.c -o obj/a1p5.o


obj/tictactoe.o: src/tictactoe.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/tictactoe.c -o obj/tictactoe.o


clean:
	rm -rf obj/*.o
	rm -rf bin/*
