testMain(27/05/2020):
	gcc ip_lib.c -o ip_lib.o -Wall -lm
	gcc main.c bmp.o ip_lib.o -o testMain -Wall --ansi --pedantic -lm -g3 -O3 -fsanitize=address -fsanitize=undefined -std=gnu89 -Wextra 
	./testMain
	#rm testMain

testMain:
	gcc ip_lib.c -o ip_lib.o -Wall -lm
	gcc main_iplib.o main.c bmp.o -o testMain -Wall --ansi --pedantic -lm -g3 -O3 -fsanitize=address -fsanitize=undefined -std=gnu89 -Wextra 
	./testMain

testMain2:
	gcc -Wall -c main.c -o testMain.o -lm
	gcc ip_lib.c bmp.o -oip_lib.o -lm
	gcc ip_lib.o bmp.o testMain.o -otestMain
	./testMain
clean:
	rm new.bmp
memCheck:
	valgrind -v --leak-check=full ./testMain
