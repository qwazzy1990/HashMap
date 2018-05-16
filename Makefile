

CC = gcc
CFLAGS = -std=c11 -Wall -g -pedantic

prog1:

	mkdir bin
	$(CC) $(CFLAGS) -Imnt/c/projects/String/include -Imnt/c/projects/utilities/include -Iinclude ../../String/src/String.c ../../utilities/src/utilities.c src/HashMap.c test/testmain.c -o bin/prog1

clean:
	rm -r bin
