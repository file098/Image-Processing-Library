
test: main_iplib.o bmp.o ip_lib.o
	gcc bmp.o main_iplib.o ip_lib.o -o main_iplib -lm -g3 -fsanitize=address -fsanitize=undefined -Wextra
bmp.o: bmp.c bmp.h ip_lib.h
	gcc -c -Wall -std=gnu89 bmp.c -o bmp.o
ip_lib.o: ip_lib.c ip_lib.h bmp.h
	gcc -c -Wall --ansi --pedantic -std=gnu89 ip_lib.c -o ip_lib.o
main_iplib.o: main_iplib.c bmp.h ip_lib.h
	gcc -Wall --ansi --pedantic -std=gnu89 -c main_iplib.c -o main_iplib.o


clean:
	rm main_iplib.o ip_lib.o bmp.o



