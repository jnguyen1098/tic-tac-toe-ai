CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -ggdb -Iinclude
VFLAGS = --show-leak-kinds=all --leak-check=full --track-origins=yes

.PHONY = clean run

run: obj/tictactoe.o obj/test.o bin/test
	./bin/test

bin/test: obj/test.o obj/tictactoe.o include/tictactoe.h
	$(CC) $(CFLAGS) obj/tictactoe.o obj/test.o -o bin/test

obj/test.o: test/test.c include/tictactoe.h
	$(CC) $(CFLAGS) -c test/test.c -o obj/test.o

obj/tictactoe.o: src/tictactoe.c include/tictactoe.h
	$(CC) $(CFLAGS) -c src/tictactoe.c -o obj/tictactoe.o

clean:
	rm -rf obj/*.o
	rm -rf bin/*
