testMain:
	gcc ip_lib.c -o ip_lib.o -Wall -c
	gcc main.c bmp.o ip_lib.o -o testMain -Wall -lm
	./testMain
	#rm testMain

testMain2:
	gcc -Wall -c main.c -o testMain.o -lm
	gcc ip_lib.c bmp.o -oip_lib.o -lm
	gcc ip_lib.o bmp.o testMain.o -otestMain
	./testMain
clean:
	rm new.bmp
memCheck:
	valgrind -v --leak-check=full ./testMain
