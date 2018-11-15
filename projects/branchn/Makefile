CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: randomtestresults

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c

	echo "randomtestcard1.c results:" >> randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c -f -b >> randomtestcard1.out
	
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c -f -b >> randomtestcard2.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -f -b >> randomtestadventurer.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

clean:
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out

cleanall: 
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out randomtestcard1 randomtestcard2 randomtestadventurer *.gcda *.gcno *.gcov *.exe.stackdump *.exe
