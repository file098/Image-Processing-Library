provastack: principale.o
	gcc --ansi --pedantic -ggdb main.o -omain

principale.o: main.c ip_lib.h
	gcc -c --ansi --pedantic -ggdb main.c -omain.o
