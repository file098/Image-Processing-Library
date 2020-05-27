testMain(27/05/2020):
	gcc ip_lib.c -o ip_lib.o -Wall -lm
	gcc main.c bmp.o ip_lib.o -o testMain -Wall --ansi --pedantic -lm -g3 -O3 -fsanitize=address -fsanitize=undefined -std=gnu89 -Wextra 
	./testMain
	#rm testMain

test: main.o bmp.o ip_lib.o
	gcc bmp.o main.o ip_lib.o -o test -Wall --ansi --pedantic -lm -g3 -O3 -fsanitize=address -fsanitize=undefined -std=gnu89 -Wextra
bmp.o: bmp.c bmp.h ip_lib.h
	gcc -c -Wall -std=gnu89 bmp.c -o bmp.o
ip_lib.o: ip_lib.c ip_lib.h bmp.h
	gcc -c -Wall --ansi --pedantic -std=gnu89 ip_lib.c -o ip_lib.o
main.o: main.c bmp.h ip_lib.h
	gcc -Wall --ansi --pedantic -std=gnu89 -c main.c -o main.o

clean:
	rm new.bmp



