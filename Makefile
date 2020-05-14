testMain:
	gcc ip_lib.c -o ip_lib.o -Wall -c
	gcc main.c bmp.o ip_lib.o -o testMain -Wall -lm
	./testMain
	rm testMain
clean:
	rm new.bmp
memCheck:
	valgrind -v --leak-check=full ./testMain