runMainTest:
	gcc ip_lib.c -o ip_lib.o -Wall -c
	gcc main.c bmp.o ip_lib.o -o testMyMain -Wall -lm
	./testMain
